#include "Bank.h"

Bank::Bank() {

}
Bank::~Bank() {

}
void Bank::readAccounts(IAccountReader cAcctReader) {

}
void Bank::readCommand(ICommandReader cCmdReader) {

}
void Bank::writeBank(IBankWriter cOut) {

}
void Bank::deposit(int acctNum, long long amount) {
	mapcAccount[getAccount(acctNum)]->deposit(amount);
}
void Bank::withdraw(int acctNum, long long amount) {
	mapcAccount[getAccount(acctNum)]->withdraw(amount);
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
		if (mapcAccount[index]->getAcctNum == acctNum)
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
void Bank::addAccount(IAccount *pTheAccount) {

}