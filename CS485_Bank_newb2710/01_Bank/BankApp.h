#pragma once
#include "IAccountReader.h"
#include "ICommandReader.h"
#include "Bank.h"

class BankApp {
	public:
		BankApp();
		~BankApp();
		void readAccounts(IAccountReader &rcAcctReader);
		void readCommand(ICommandReader &rcCmdReader);
		void runCommand(ICommand* pcCmd);
	private:
		Bank mcTheBank;
};