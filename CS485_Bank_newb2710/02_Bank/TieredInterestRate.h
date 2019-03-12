//***************************************************************************
// File name:  TieredInterestRate.h
// Author:     Hannah NewbyTieredInterestRate
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    TieredInterestRate class header
//***************************************************************************
#pragma once
#ifndef TieredInterestRate_h
#define TieredInterestRate_h
#include <vector>
#include "TieredType.h"
#include <algorithm>
class TieredInterestRate : public IInterestRate{
public:
	TieredInterestRate();
	~TieredInterestRate();
	Money generateInterest(Money &rcMoney);
	void write(std::ostream &rcOut);
	void read(std::istream &rcIn);
	void addTier(TieredType tier);
	void sortTiers();

private:
	int findTier(Money &);
	std::vector<TieredType> mvcInterest;

	int mNumTiers = 0;
};
#endif
