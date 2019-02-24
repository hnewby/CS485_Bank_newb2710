#pragma once
#include "Account.h"
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
		void generateInterest(Account &rcTheAccount);
		int getAccount(int acctNum);
		void addAccount(Account *pTheAccount);

	private:
		static int const mMAX_ACCOUNTS = 100;
		Account * mapcAccount[mMAX_ACCOUNTS];
		int mNumAccts;
};