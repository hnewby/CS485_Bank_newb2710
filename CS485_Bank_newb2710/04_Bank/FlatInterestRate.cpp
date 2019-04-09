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
//***************************************************************************
// Destructor:  FlatInterestRate
//
// Description: Deconstructor for FlatInterestRate
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
FlatInterestRate::~FlatInterestRate() {

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
Money FlatInterestRate::generateInterest(Money &rcMoney) {
	Money amount = 0;
	if (rcMoney > 0)
	{
		amount = (rcMoney * mInterestAmount);
	}
	return amount;
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
void FlatInterestRate::write(std::ostream &rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal = mInterestAmount * DIV;
	rcOut << "F " << std::fixed << std::setprecision(DECIMAL) << bal << "%";
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
void FlatInterestRate::read(std::istream &rcIn) {
	rcIn >> mInterestAmount;
}