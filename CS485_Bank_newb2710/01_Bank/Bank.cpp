#include "Bank.h"
#include "ScreenBankWriter.h"
Bank::Bank() {
	mNumAccts = 0;
}
Bank::~Bank() {

}
//void Bank::readAccounts(IAccountReader &rcAcctReader) {
//
//	rcAcctReader.read(mcTheCollection);
//	// could be off by one here but dont think so
//
//	//addAccount(mapcAccounts[(mNumAccts - 1)]);
//}
//void Bank::readCommand(ICommandReader &rcCmdReader) {
//
//}
void Bank::writeBank(IBankWriter &rcOut) {
	for (int i = 0; i < mNumAccts; i++)
	{
		//mapcAccounts[i]->print()
		rcOut.write(std::cout, *mapcAccounts[i]);
		std::cout << '\n';
	}
}
void Bank::deposit(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->deposit(amount);
}
void Bank::withdraw(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->withdraw(amount);
}
void Bank::generateAllInterest() {
	for (int i = 0; i < mNumAccts; i++)
	{
		generateInterest(*mapcAccounts[i]);
	}
}
void Bank::generateInterest(IAccount &rcTheAccount) {
	rcTheAccount.generateInterest();
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
void Bank::addAccount(IAccount *pcTheAccount) {
	if (mNumAccts <= mMAX_ACCOUNTS)
	{
		mapcAccounts[mNumAccts] = pcTheAccount;
		mNumAccts++;
	}
}

void Bank::print() {
	IBankWriter* pcWriter = new ScreenBankWriter;

	writeBank(*pcWriter);
}

void Bank::endOfMonthForAll() {
	for (int i = 0; i < mNumAccts; i++)
	{
		mapcAccounts[i]->endOfMonth();
	}
	//generateAllInterest();
}