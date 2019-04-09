//***************************************************************************
// File name:  TransactionalFee.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    TransactionalFee class header
//***************************************************************************
#pragma once
#include "IFee.h"

class TransactionalFee : public IFee {
	public:
		TransactionalFee();
		TransactionalFee(Money minBalance, Money amount);
		~TransactionalFee();
		Money chargeMonthlyFee(const Money balance);
		Money chargeDepositFee(const Money balance);
		Money chargeWithdrawFee(const Money balance);
		void read(std::istream& rcIn);
		void write(std::ostream &rcOut);
	private:
		Money mMinBal;
};