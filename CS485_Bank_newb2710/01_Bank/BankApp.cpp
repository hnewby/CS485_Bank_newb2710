#include "BankApp.h"
void BankApp::readAccounts(IAccountReader &rcAcctReader) {
	
	rcAcctReader.read(mcTheBank);
	// could be off by one here but dont think so

	//addAccount(mapcAccounts[(mNumAccts - 1)]);
}
void BankApp::readCommand(ICommandReader &rcCmdReader) {
	ICommand *pcTheCmd = nullptr;
	do {
		pcTheCmd = rcCmdReader.read(); // be careful of when to delete pcTheCmd
		runCommand(pcTheCmd);
	} while (pcTheCmd != nullptr);
}
void BankApp::runCommand(ICommand *pcCmd)
{
	pcCmd->action(mcTheBank);
}


//run command