#include "ArrayAccountsContainer.h"


ArrayAccountsContainer::ArrayAccountsContainer() {
	mNumAccts = 0;
}
ArrayAccountsContainer::~ArrayAccountsContainer() {

}
void ArrayAccountsContainer::addAccount(IAccount *pcTheAccount) {
	if (mNumAccts <= mMAX_ACCOUNTS)
	{
		mapcAccounts[mNumAccts] = pcTheAccount;
		mNumAccts++;
	}
}
int ArrayAccountsContainer::count() {
	return mNumAccts;
}
int ArrayAccountsContainer::findAccount(unsigned int acctNum) {
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
bool ArrayAccountsContainer::isFull() {
	bool bIsFull = false;
	if (mNumAccts >= mMAX_ACCOUNTS)
	{
		bIsFull = true;
	}
	return bIsFull;
}

IAccount& ArrayAccountsContainer::operator[] (std::size_t index) {
	return *mapcAccounts[index];
}
const IAccount& ArrayAccountsContainer::operator[](std::size_t index) const {
	return *mapcAccounts[index];
}

//int ArrayAccountsContainer::getAccount(int acctNum) {
//	//is this diff from find?
//}