//***************************************************************************
// File name:  CheckingAccount.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CheckingAccount class header
//***************************************************************************
#pragma once
#include "Account.h"
class CheckingAccount : Account {
	public:
		CheckingAccount();
		CheckingAccount(int acctNum, long long amt, float interestRate, IFee theFee);
		~CheckingAccount();
	private:

};