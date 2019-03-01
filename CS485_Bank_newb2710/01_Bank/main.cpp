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

	cBankApp.readAccounts(*pcAccountReader);
	cBankApp.readCommand(*pcCommandReader);

	pcAccountReader->closeAccountsDB();
	pcCommandReader->closeCommands();
	return EXIT_SUCCESS;
}