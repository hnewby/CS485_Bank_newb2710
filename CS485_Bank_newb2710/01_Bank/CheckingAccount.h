//***************************************************************************
// File name:  CheckingAccount.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CheckingAccount class header
//***************************************************************************
#pragma once
#include "IAccount.h"
#include "TransactionalFee.h"
class CheckingAccount : public IAccount {
	public:
		CheckingAccount();
		CheckingAccount(int acctNum, long long amt, float interestRate, IFee* pcTheFee);
		~CheckingAccount();
	private:

};