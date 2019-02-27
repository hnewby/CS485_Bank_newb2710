#pragma once

#include "IAccount.h"
class AccountCollection {
public:
	AccountCollection();
	~AccountCollection();
	//void display(SDLApp& rcApp);
	void addAccount(IAccount *pcAccount);
	void moveFrom(AccountCollection& rcCol);
	void deleteAll();
	static int const mMAX_ACCOUNTS = 100;

private:
	//static int const mMAX_ACCOUNTS = 100;
	int mNumAccts;
	IAccount* mapcAccounts[mMAX_ACCOUNTS];
};