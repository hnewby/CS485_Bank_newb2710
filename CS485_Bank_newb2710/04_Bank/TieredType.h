//***************************************************************************
// File name:  TieredType.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    TieredType class header
//***************************************************************************
#pragma once
#ifndef TieredType_h
#define TieredType_h
#include "IInterestRate.h"

class TieredType {
public:
	TieredType();
	~TieredType();
	Money generateInterest(Money &rcMoney);
	void writeBalance(std::ostream &rcOut);
	void writeInterest(std::ostream &rcOut);
	void readBal(std::istream &rcIn);
	void readInterest(std::istream &rcIn);
	bool checkBalance(Money &rcMoney);
	friend bool operator > (TieredType &rcT1, TieredType &rcT2);
private:
	double mInterestAmount;
	Money mBalanceAmount;
};
#endif
