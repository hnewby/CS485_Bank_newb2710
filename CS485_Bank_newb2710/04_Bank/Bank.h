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
#include "IAccountsContainer.h"

class Bank {
	public:
		Bank();
		~Bank();
		void writeBank(IBankWriter &rcOut);
		void deposit(int acctNum, Money amount);
		void withdraw(int acctNum, Money amount);
		void addAccount(IAccount *pcTheAccount);
		void print();
		void endOfMonthForAll();
		void deleteAll();
		void backup(std::string checkingFile, std::string savingsFile);
	private:
		IAccountsContainer *mpcAccounts;
};
#endif