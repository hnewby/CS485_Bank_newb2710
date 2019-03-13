//***************************************************************************
// File name:  TieredInterestRate.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: TieredInterestRate
// Purpose:    TieredInterestRate class implamentation
//***************************************************************************
#include "TieredInterestRate.h"

//***************************************************************************
// Constructor: TieredInterestRate
//
// Description: Initialize TieredInterestRate
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TieredInterestRate::TieredInterestRate() {
	mNumTiers = 0;
}
//***************************************************************************
// Destructor:  TieredInterestRate
//
// Description: Deconstructor for TieredInterestRate
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TieredInterestRate::~TieredInterestRate() {
	while (mvcInterest.size() > 0)
	{
		mvcInterest.pop_back();
	}
}
//***************************************************************************
// Function:		generateInterest
//
// Description: generates Interest for account
//
// Parameters:  rcMoney - reference to money to multiply by interest
//
// Returned:    Money
//***************************************************************************
Money TieredInterestRate::generateInterest(Money &rcMoney) {
	int tier = findTier(rcMoney);
	Money interest = 0;
	if (tier != -1) {
		interest = mvcInterest[tier].generateInterest(rcMoney);
	}
	return interest;
}
//***************************************************************************
// Function:		write
//
// Description: send value out
//
// Parameters:  rcOut - refernce to ostream
//
// Returned:    None
//***************************************************************************
void TieredInterestRate::write(std::ostream &rcOut) {
	rcOut << "T ";
	for (int i = (mNumTiers - 1); i >= 0; i--) {
		mvcInterest[i].writeBalance(rcOut);
	}
	for (int i = (mNumTiers - 1); i >= 0; i--) {
		mvcInterest[i].writeInterest(rcOut);
		if (i > 0) {
			rcOut << " ";
		}
	}
}
//***************************************************************************
// Function:		read
//
// Description: read value into istream
//
// Parameters:  rcIn - refernce to istream
//
// Returned:    None
//***************************************************************************
void TieredInterestRate::read(std::istream &rcIn) {
	TieredType newTier;
	int numTiers = 0;
	rcIn >> numTiers;
	for (int i = 0; i < numTiers; i++){
		addTier(newTier);
		mvcInterest[i].readBal(rcIn);
	}
	for (int i = 0; i < numTiers; i++){
		mvcInterest[i].readInterest(rcIn);
	}
	sortTiers();
}
//***************************************************************************
// Function:		findTier
//
// Description: find tier in vector given Money amount
//
// Parameters:  rcMoney - referecne to money amount checking against
//
// Returned:    int
//***************************************************************************
int TieredInterestRate::findTier(Money &rcMoney) {
	int index = 0;
	bool bIsFound = false;
	while (!bIsFound && index < mNumTiers){
		if (mvcInterest[index].checkBalance(rcMoney)) {
			bIsFound = true;
		}
		else {
			index++;
		}
	}
	if (!bIsFound) {
		index = -1;
	}
	return index;
}
//***************************************************************************
// Function:		addTier
//
// Description: ad a tier to vector
//
// Parameters:  tier - tier to add to vector
//
// Returned:    void
//***************************************************************************
void TieredInterestRate::addTier(TieredType tier) {
	mvcInterest.push_back(tier);
	mNumTiers++;
}
//***************************************************************************
// Function:		sortTiers
//
// Description: sort tiers in desc order
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TieredInterestRate::sortTiers() {
	std::sort(mvcInterest.begin(), mvcInterest.end(),
		[](TieredType &rcT1, TieredType &rcT2) -> bool {
		return rcT1 > rcT2;
	});
}
