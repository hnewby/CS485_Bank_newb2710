//***************************************************************************
// File name:  FlatInterestRate.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: FlatInterestRate
// Purpose:    FlatInterestRate class implamentation
//***************************************************************************
#include "FlatInterestRate.h"

//***************************************************************************
// Constructor: FlatInterestRate
//
// Description: Initialize FlatInterestRate
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
FlatInterestRate::FlatInterestRate() {
	mInterestAmount = 0;
}
FlatInterestRate::~FlatInterestRate() {

}
Money FlatInterestRate::generateInterest(Money &rcMoney) {
	return (rcMoney * mInterestAmount);
}
void FlatInterestRate::write(std::ostream &rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal = mInterestAmount * DIV;
	rcOut << "F " << std::fixed << std::setprecision(DECIMAL) << bal << "%";
}
void FlatInterestRate::read(std::istream &rcIn) {
	rcIn >> mInterestAmount;
}