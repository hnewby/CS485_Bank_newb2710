//***************************************************************************
// File name:  SavingsAccount.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    SavingsAccount class header
//***************************************************************************
#pragma once
#include "IAccount.h"
#include "MonthlyFee.h"
class SavingsAccount : public IAccount {
	public:
		SavingsAccount();
		SavingsAccount(int acctNum, Money amt, double interestRate,
			IFee* pcTheFee);
		~SavingsAccount();
	private:

};