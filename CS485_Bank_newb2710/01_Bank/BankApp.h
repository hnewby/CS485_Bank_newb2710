#pragma once
#include "IAccountReader.h"
#include "ICommandReader.h"
//#include "IBankWriter.h"
#include "Bank.h"

class BankApp {
	public:
		void readAccounts(IAccountReader &rcAcctReader);
		void readCommand(ICommandReader &rcCmdReader);
		//void writeBank(IBankWriter &rcOut);
		void runCommand(ICommand* pcCmd);
	private:
		Bank mcTheBank;
		ICommand* mpcCurrentCmd;
};