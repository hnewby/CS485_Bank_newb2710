//***************************************************************************
// File name:  WithdrawCmd.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    WithdrawCmd class header
//***************************************************************************
#pragma once
#include "ICommand.h"

class WithdrawCmd : public ICommand{
	public:
		WithdrawCmd(int acctNum, long long amount);
		~WithdrawCmd();
		void action(Bank &rcTheBank);
	private:
		int mAcctNum;
		long long mAmt;
};