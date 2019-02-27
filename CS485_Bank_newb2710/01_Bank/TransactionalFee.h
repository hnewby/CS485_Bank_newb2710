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
		TransactionalFee(long long minBalance, long long amount);
		~TransactionalFee();
		long long chargeMonthlyFee(const long long balance);
		long long chargeDepositFee(const long long balance);
		long long chargeWithdrawFee(const long long balance);
		void read(std::istream& rcIn);
	private:
		long long mMinBal;
};