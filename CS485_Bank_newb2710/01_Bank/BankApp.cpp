//***************************************************************************
// File name:  BankApp.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BankApp class implamentation
//***************************************************************************
#include "BankApp.h"

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
	mpcCurrentCmd = nullptr;
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
		pcTheCmd = rcCmdReader.read(); // be careful of when to delete pcTheCmd
		runCommand(pcTheCmd);
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