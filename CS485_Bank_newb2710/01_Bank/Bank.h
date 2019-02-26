//***************************************************************************
// File name:  Bank.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Bank class header
//***************************************************************************
#pragma once
#include "IAccount.h"
#include "IAccountReader.h"
#include "ICommandReader.h"
#include "IBankWriter.h"

class Bank {
	public:
		Bank();
		~Bank();
		void readAccounts(IAccountReader cAcctReader);
		void readCommand(ICommandReader cCmdReader);
		void writeBank(IBankWriter cOut);
		void deposit(int acctNum, long long amount);
		void withdraw(int acctNum, long long amount);
		void generateAllInterest();
		void generateInterest(IAccount &rcTheAccount);
		int getAccount(int acctNum);
		void addAccount(IAccount *pTheAccount);

	private:
		static int const mMAX_ACCOUNTS = 100;
		IAccount * mapcAccount[mMAX_ACCOUNTS];
		int mNumAccts;
};