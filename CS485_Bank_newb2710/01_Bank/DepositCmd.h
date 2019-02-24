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
		~DepositCmd();
		void action(Bank &rcTheBank);
	private:
		int mAcctNum;
		long long mAmt;
};