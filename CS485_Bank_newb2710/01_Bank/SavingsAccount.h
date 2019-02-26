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
class SavingsAccount : IAccount {
	public:
		SavingsAccount();
		SavingsAccount(int acctNum, long long amt, float interestRate, IFee theFee);
		~SavingsAccount();
	private:

};