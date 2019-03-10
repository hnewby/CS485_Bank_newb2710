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
	MonthlyFee(Money minBal, bool bWentBelow, Money amount);
	~MonthlyFee();
	Money chargeMonthlyFee(const Money balance);
	Money chargeDepositFee(const Money balance);
	Money chargeWithdrawFee(const Money balance);
	bool checkWentBelow();
	void read(std::istream& rcIn);
	void write(std::ostream &rcOut);
private:
	Money mMinBal;
	bool mbWentBelow;
};