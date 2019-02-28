//***************************************************************************
// File name:  DepositCmd.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    DepositCmd class header
//***************************************************************************
#pragma once

#include "ICommand.h"
class DepositCmd : public ICommand {
	public:
		DepositCmd();
		DepositCmd(int acctNum, long long amount);
		~DepositCmd();
		void action(Bank &rcTheBank);
	private:
		int mAcctNum;
		long long mAmt;
};