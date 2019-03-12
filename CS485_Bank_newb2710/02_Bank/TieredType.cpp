#include "TieredType.h"
#include <iomanip>

//***************************************************************************
// Constructor: TieredType
//
// Description: Initialize TieredType
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TieredType::TieredType() {
	mInterestAmount = 0.0;
}
//***************************************************************************
// Destructor:  TieredType
//
// Description: Deconstructor for TieredType
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TieredType::~TieredType() {

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
Money TieredType::generateInterest(Money &rcMoney) {
	return (rcMoney * mInterestAmount);
}
//***************************************************************************
// Function:		writeBalance
//
// Description: send value out
//
// Parameters:  rcOut - refernce to ostream
//
// Returned:    None
//***************************************************************************
void TieredType::writeBalance(std::ostream &rcOut) {
	mBalanceAmount.write(rcOut);
	rcOut << " ";
}
//***************************************************************************
// Function:		writeInterest
//
// Description: send value out
//
// Parameters:  rcOut - refernce to ostream
//
// Returned:    None
//***************************************************************************
void TieredType::writeInterest(std::ostream &rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal;
	double interest = mInterestAmount * DIV;

	rcOut << std::fixed << std::setprecision(DECIMAL) << interest << "%";
}
//***************************************************************************
// Function:		readBal
//
// Description: read value into istream
//
// Parameters:  rcIn - refernce to istream
//
// Returned:    None
//***************************************************************************
void TieredType::readBal(std::istream &rcIn) {
	rcIn >> mBalanceAmount;
}
//***************************************************************************
// Function:		readInterest
//
// Description: read value into istream
//
// Parameters:  rcIn - refernce to istream
//
// Returned:    None
//***************************************************************************
void TieredType::readInterest(std::istream &rcIn) {
	rcIn >> mInterestAmount;
}
//***************************************************************************
// Function:		checkBalance
//
// Description: check if given balance is greater than or eq to Tier bal
//
// Parameters:  rcmoney - reference to money amount to check against
//
// Returned:    bool
//***************************************************************************
bool TieredType::checkBalance(Money &rcMoney) {
	return (rcMoney >= mBalanceAmount);
}
//***************************************************************************
// Function:		operator >
//
// Description: check if tiers is greater than another
//
// Parameters:  rcT1 - reference to 1st tier
//							rcT2 - reference to 2nd tier
//
// Returned:    bool
//***************************************************************************
bool operator > (TieredType &rcT1, TieredType &rcT2) {
	return (rcT1.mBalanceAmount > rcT2.mBalanceAmount);
}
