#include "MonthlyFee.h"

//***************************************************************************
// Constructor: MonthlyFee
//
// Description: Initialize MonthlyFee
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
MonthlyFee::MonthlyFee() : IFee() {
	mMinBal = 0;
	mbWentBelow = false;
}
//***************************************************************************
// Constructor: MonthlyFee
//
// Description: Initialize MonthlyFee
//
// Parameters:  minBal		 - Minimum Balance
//							bWentBelow - bool if go below min bal
//							amount		 - fee amount
//
// Returned:    None
//***************************************************************************
MonthlyFee::MonthlyFee(long long minBal, bool bWentBelow,
	long long amount) : IFee (amount){
	mMinBal = minBal;
	mbWentBelow = bWentBelow;
}
//***************************************************************************
// Destructor:  MonthlyFee
//
// Description: Deconstructor for MonthlyFee
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
MonthlyFee::~MonthlyFee() {

}
//***************************************************************************
// Function:		chargeMonthlyFee
//
// Description: charge the monthly fee to account
//
// Parameters:  balance - balance of account
//
// Returned:    long long
//***************************************************************************
long long MonthlyFee::chargeMonthlyFee(const long long balance) {
	long long feeAmount = 0;
	if (mbWentBelow)
	{
		feeAmount = getAmount();
	}
	mbWentBelow = false; //reset for new month
	return feeAmount;
}
//***************************************************************************
// Function:		chargeDepositFee
//
// Description: charge the deposit fee to account
//
// Parameters:  balance - balance of account
//
// Returned:    long long
//***************************************************************************
long long MonthlyFee::chargeDepositFee(const long long balance) {
	
	if (balance < mMinBal)
	{
		mbWentBelow = true;
	}
	return 0;
}
//***************************************************************************
// Function:		chargeWithdrawFee
//
// Description: charge the withdraw fee to account
//
// Parameters:  balance - balance of account
//
// Returned:    long long
//***************************************************************************
long long MonthlyFee::chargeWithdrawFee(const long long balance) {
	if (balance < mMinBal)
	{
		mbWentBelow = true;
	}
	return 0;
}

bool MonthlyFee::checkWentBelow() {
	return mbWentBelow;
}

void MonthlyFee::read(std::istream &rcIn){
	IFee::read(rcIn);
	rcIn >> mMinBal;// >> mbWentBelow;
}

void MonthlyFee::write(std::ostream &rcOut) {
	IFee::write(rcOut);
	rcOut << ", " << mMinBal;
}