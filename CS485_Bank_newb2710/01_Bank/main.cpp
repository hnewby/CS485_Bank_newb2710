#include "StreamCommandReader.h"
#include "StreamAccountReader.h"
#include "IAccountReader.h"
#include "Bank.h"
#include <string>
int main() {
	//ICommandReader cCommandReader = new StreamCommandReader ();
	//const string 
	//StreamCommandReader cCommandReader;
	StreamAccountReader cAccountReader;
	//IAccountReader cAcctReader = new StreamAccountReader;
	Bank cTheBank;

	cAccountReader.openAccountsDB("Accounts.txt");
	cTheBank.readAccounts(cAccountReader);
	return EXIT_SUCCESS;
}