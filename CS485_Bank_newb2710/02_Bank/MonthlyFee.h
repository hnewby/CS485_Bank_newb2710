//***************************************************************************
// File name:  MonthlyFee
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthlyFee class header
//***************************************************************************
#pragma once
#include "IFee.h"

class MonthlyFee : public IFee{
public:
	MonthlyFee();
	MonthlyFee(long long minBal, bool bWentBelow, long long amount);
	~MonthlyFee();
	long long chargeMonthlyFee(const long long balance);
	long long chargeDepositFee(const long long balance);
	long long chargeWithdrawFee(const long long balance);
	bool checkWentBelow();
	void read(std::istream& rcIn);
	void write(std::ostream &rcOut);
private:
	long long mMinBal;
	bool mbWentBelow;
};