//***************************************************************************
// File name:  main.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    driver for bank
//***************************************************************************
#include "StreamCommandReader.h"
#include "StreamAccountReader.h"
#include "BankApp.h"
#include <string>
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
	pcAccountReader->openAccountsDB("Accounts.txt");
	pcCommandReader->openCommands("Commands.txt");

	try {
		cBankApp.readAccounts(*pcAccountReader);
		cBankApp.readCommand(*pcCommandReader);
	}
	catch (const std::bad_array_new_length &e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::range_error &e) {
	std::cout << e.what() << std::endl;
	}

	pcAccountReader->closeAccountsDB();
	pcCommandReader->closeCommands();

	delete pcAccountReader;
	delete pcCommandReader;
	return EXIT_SUCCESS;
}