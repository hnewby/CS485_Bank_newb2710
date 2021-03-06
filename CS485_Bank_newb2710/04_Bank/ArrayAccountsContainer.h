//***************************************************************************
// File name:  ArrayAccountsContainer.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ArrayAccountsContainer class header
//***************************************************************************
#pragma once
#ifndef ArrayAccountsContainer_h
#define ArrayAccountsContainer_h
#include "IAccountsContainer.h"
#include "IAccountVisitor.h"
class ArrayAccountsContainer : public IAccountsContainer{
	public:
		ArrayAccountsContainer();
		~ArrayAccountsContainer();
		void addAccount(IAccount *pcTheAccount);
		int count();
		IAccount * findAccount(unsigned int acctNum);
		bool isFull();
		void applyVisitor(IAccountVisitor *);
		IAccount * getAccount(int index);


	private:
		void sort();
		static int const mMAX_ACCOUNTS = 100;
		IAccount *mapcAccounts[mMAX_ACCOUNTS];
		int mNumAccts;
};
#endif
