#include "StreamCommandReader.h"
#include "StreamAccountReader.h"
//#include "ICommandReader.h"
#include "BankApp.h"
#include <string>
int main() {
	BankApp cBankApp;
	ICommandReader* pcCommandReader = new StreamCommandReader;
	//const string 
	//StreamCommandReader cCommandReader = new StreamCommandReader ();
	//StreamAccountReader cAccountReader;
	IAccountReader* pcAccountReader = new StreamAccountReader;
	Bank cTheBank;
	
	pcAccountReader->openAccountsDB("Accounts.txt");
	cBankApp.readAccounts(*pcAccountReader);
	pcCommandReader->openCommands("Commands.txt");
	cBankApp.readCommand(*pcCommandReader);
	return EXIT_SUCCESS;
}