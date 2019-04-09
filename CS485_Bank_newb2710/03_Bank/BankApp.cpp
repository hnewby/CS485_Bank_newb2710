//***************************************************************************
// File name:  BankApp.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BankApp class implamentation
//***************************************************************************
#include "BankApp.h"
#include "CurrencyMismatchException.h"
//***************************************************************************
// Constructor: BankApp
//
// Description: Initialize BankApp
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BankApp::BankApp() {
}
//***************************************************************************
// Destructor: BankApp
//
// Description: Destruct Bank App
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BankApp::~BankApp() {
	mcTheBank.deleteAll();
}
//***************************************************************************
// Function:		readAccounts
//
// Description: Read accounts from reader into array
//
// Parameters:  rcAcctReader - reader which holds where file is
//														 being read from
//
// Returned:    None
//***************************************************************************
void BankApp::readAccounts(IAccountReader &rcAcctReader) {
		rcAcctReader.read(mcTheBank);

}
//***************************************************************************
// Function:		readCommand
//
// Description: Read command from reader variable
//
// Parameters:  rcCmdReader - reader which holds where info is
//														 being read from
//
// Returned:    None
//***************************************************************************
void BankApp::readCommand(ICommandReader &rcCmdReader) {
	ICommand *pcTheCmd = nullptr;
	do {
		try {
			pcTheCmd = rcCmdReader.read();
			if (pcTheCmd != nullptr)// be careful of when to delete pcTheCmd
			{
				runCommand(pcTheCmd);
			}
		}
		catch (const CurrencyMismatchException &e) {
			std::cout << e.what() << '\n';
		}
		delete pcTheCmd;
	} while (pcTheCmd != nullptr);
}
//***************************************************************************
// Function:		runCommand
//
// Description: Given and command runs proper action
//
// Parameters:  pcCmd - pointer to command
//
// Returned:    None
//***************************************************************************
void BankApp::runCommand(ICommand *pcCmd)
{
	pcCmd->action(mcTheBank);
}