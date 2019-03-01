//***************************************************************************
// File name:  BankApp.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BankApp class header
//***************************************************************************
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