//***************************************************************************
// File name:  FlatInterestRate.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    FlatInterestRate class header
//***************************************************************************
#pragma once
#ifndef FlatInterestRate_h
#define FlatInterestRate_h
#include "IInterestRate.h"

class FlatInterestRate : public IInterestRate{
	public:
		FlatInterestRate();
		~FlatInterestRate();
		Money generateInterest(Money &rcMoney);
		void write(std::ostream &rcOut);
		void read(std::istream &rcIn);
	private:
		double mInterestAmount;
};
#endif
