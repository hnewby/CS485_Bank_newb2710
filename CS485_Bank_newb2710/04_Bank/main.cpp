//***************************************************************************
// File name:  main.cpp
// Author:     Hannah Newby
// Date:       4/15/19
// Class:      CS485
// Assignment: Bank
// Purpose:    driver for bank
//***************************************************************************
#include "StreamCommandReader.h"
#include "StreamAccountReader.h"
#include "CurrencyConversion.h"
#include "BankApp.h"
#include <string>
#include "CurrencyMismatchException.h"
//#include <vld.h>
//***************************************************************************
// Function:		main
//
// Description: driver of bank
//
// Parameters:  None
//
// Returned:    int
//***************************************************************************
int main() {
	BankApp cBankApp;
	ICommandReader* pcCommandReader = new StreamCommandReader;
	IAccountReader* pcAccountReader = new StreamAccountReader;
	std::string currencyFile = "CurrencyConversions.txt";
	std::ifstream currFile;
	pcAccountReader->openAccountsDB("Accounts.txt");
	pcCommandReader->openCommands("Commands.txt");
	CurrencyConversion& cConversion = CurrencyConversion::getInstance();
	Currency cCur1, cCur2;
	double exchange;

	currFile.open(currencyFile);
	if (currFile.fail()) {
		std::cout << "Currency file failed to open";
	}
	while (!currFile.eof()) {
		currFile >> cCur1 >> cCur2 >> exchange;
		cConversion.insert(cCur1, cCur2, exchange);
	}

	try {
		cBankApp.readAccounts(*pcAccountReader);
		cBankApp.readCommand(*pcCommandReader);
	}
	catch (const CurrencyMismatchException &e) {
		e.what(); //swallow
	}
	catch (const std::bad_array_new_length &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::range_error &e) {
		std::cout << e.what() << std::endl;
	}
	
	
	pcAccountReader->closeAccountsDB();
	pcCommandReader->closeCommands();
	currFile.close();
	delete pcAccountReader;
	delete pcCommandReader;
	return EXIT_SUCCESS;
}