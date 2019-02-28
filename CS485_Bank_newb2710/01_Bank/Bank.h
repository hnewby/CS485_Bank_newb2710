//***************************************************************************
// File name:  Bank.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Bank class header
//***************************************************************************
//#pragma once
#ifndef Bank_h
#define Bank_h
//#include "IAccount.h"
//#include "IAccountReader.h"
//#include "ICommandReader.h"
#include "IBankWriter.h"
#include "AccountCollection.h"
//class ICommandReader;
class Bank {
	public:
		Bank();
		~Bank();
		//void readAccounts(IAccountReader &rcAcctReader);
		//void readCommand(ICommandReader &rcCmdReader);
		void writeBank(IBankWriter &rcOut);
		void deposit(int acctNum, long long amount);
		void withdraw(int acctNum, long long amount);
		void generateAllInterest();
		void generateInterest(IAccount &rcTheAccount);
		int getAccount(int acctNum);
		void addAccount(IAccount *pcTheAccount);
		void print();

	private:
		AccountCollection mcTheCollection;
		static int const mMAX_ACCOUNTS = 100;
		IAccount *mapcAccounts[mMAX_ACCOUNTS];
		int mNumAccts;
};
#endif