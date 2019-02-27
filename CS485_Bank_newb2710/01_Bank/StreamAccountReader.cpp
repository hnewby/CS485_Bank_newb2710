#include "StreamAccountReader.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

bool StreamAccountReader::openAccountsDB(std::string file) {
	bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;
}
bool StreamAccountReader::read(IAccount &rcAccount) {
	char accountType;
	IAccount *pcAccount = nullptr;
	while (mcInFile >> accountType) {
		switch (accountType) {
			case 'S':
				pcAccount = new SavingsAccount();
				break;
			case 'C':
				pcAccount = new CheckingAccount();
				break;
		}
		mcInFile >> *pcAccount;
		//need to add account to bank
	}
	return false;
}
bool StreamAccountReader::closeAccountsDB() {
	mcInFile.close();
	return false;
}