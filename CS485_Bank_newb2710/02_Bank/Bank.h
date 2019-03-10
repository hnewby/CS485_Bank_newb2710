//***************************************************************************
// File name:  Bank.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Bank class header
//***************************************************************************
#ifndef Bank_h
#define Bank_h
#include "IBankWriter.h"

class Bank {
	public:
		Bank();
		~Bank();
		void writeBank(IBankWriter &rcOut);
		void deposit(int acctNum, long long amount);
		void withdraw(int acctNum, long long amount);
		int getAccount(int acctNum);
		void addAccount(IAccount *pcTheAccount);
		void print();
		void endOfMonthForAll();
		void deleteAll();
	private:
		static int const mMAX_ACCOUNTS = 100;
		IAccount *mapcAccounts[mMAX_ACCOUNTS];
		int mNumAccts;
};
#endif