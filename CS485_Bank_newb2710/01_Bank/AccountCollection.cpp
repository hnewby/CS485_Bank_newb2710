#include "AccountCollection.h"

AccountCollection::AccountCollection() {

}
AccountCollection::~AccountCollection() {

}
//void display(SDLApp& rcApp);
void AccountCollection::addAccount(IAccount *pcAccount) {
	if (mNumAccts <= mMAX_ACCOUNTS)
	{
		mapcAccounts[mNumAccts] = pcAccount;
		mNumAccts++;
	}
}
void AccountCollection::moveFrom(AccountCollection& rcCol) {

}
void AccountCollection::deleteAll() {

}