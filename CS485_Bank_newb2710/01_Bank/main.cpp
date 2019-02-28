#include "StreamCommandReader.h"
#include "StreamAccountReader.h"
#include "BankApp.h"
#include <string>
int main() {
	BankApp cBankApp;
	ICommandReader* pcCommandReader = new StreamCommandReader;
	IAccountReader* pcAccountReader = new StreamAccountReader;

	
	pcAccountReader->openAccountsDB("Accounts.txt");
	pcCommandReader->openCommands("CommandsTest.txt");

	cBankApp.readAccounts(*pcAccountReader);
	cBankApp.readCommand(*pcCommandReader);

	pcAccountReader->closeAccountsDB();
	pcCommandReader->closeCommands();
	return EXIT_SUCCESS;
}