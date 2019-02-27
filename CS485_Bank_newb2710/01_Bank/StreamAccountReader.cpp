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
bool StreamAccountReader::read(AccountCollection &rcTheCollection) {
	char accountType;
	//rcAccount
	IAccount* pcAccount = nullptr;
	IFee* pcFee = nullptr;
	while (mcInFile >> accountType) {
		switch (accountType) {
			case 'S':
				pcFee = new MonthlyFee();
				pcAccount = new SavingsAccount(0, 0, 0, pcFee);
				break;
			case 'C':
				pcFee = new TransactionalFee();
				pcAccount = new CheckingAccount(0, 0, 0, pcFee);
				break;
		}
		mcInFile >> *pcAccount;
		rcTheCollection.addAccount(pcAccount);
		//need to add account to bank
	}
	return false;
}
bool StreamAccountReader::closeAccountsDB() {
	mcInFile.close();
	return false;
}