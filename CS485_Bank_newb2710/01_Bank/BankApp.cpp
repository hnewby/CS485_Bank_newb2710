#include "BankApp.h"

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