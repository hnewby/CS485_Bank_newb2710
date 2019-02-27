#include "Bank.h"

Bank::Bank() {
	mNumAccts = 0;
}
Bank::~Bank() {

}
void Bank::readAccounts(IAccountReader &rcAcctReader) {

	rcAcctReader.read(mcTheCollection);
	// could be off by one here but dont think so

	//addAccount(mapcAccounts[(mNumAccts - 1)]);
}
void Bank::readCommand(ICommandReader &rcCmdReader) {

}
void Bank::writeBank(IBankWriter &rcOut) {

}
void Bank::deposit(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->deposit(amount);
}
void Bank::withdraw(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->withdraw(amount);
}
void Bank::generateAllInterest() {

}
void Bank::generateInterest(IAccount &rcTheAccount) {

}
int Bank::getAccount(int acctNum) {
	bool bIsFound = false;
	int index = 0;

	while (!bIsFound && index < mMAX_ACCOUNTS)
	{
		if (mapcAccounts[index]->getAcctNum() == acctNum)
		{
			bIsFound = true;
		}
		else
		{
			index++;
		}
	}
	return index;
}
//void Bank::addAccount(IAccount *pcTheAccount) {
//	if (mNumAccts <= mMAX_ACCOUNTS)
//	{
//		mapcAccounts[mNumAccts] = pcTheAccount;
//		mNumAccts++;
//	}
//}