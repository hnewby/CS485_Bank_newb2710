//***************************************************************************
// File name:  MonthlyFee.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthlyFee class implamentation
//***************************************************************************
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
	//mMinBal = 0;
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
MonthlyFee::MonthlyFee(Money minBal, bool bWentBelow,
	Money amount) : IFee (amount){
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
// Returned:    Money
//***************************************************************************
Money MonthlyFee::chargeMonthlyFee(const Money balance) {
	Money feeAmount = 0;
	if (mbWentBelow || (balance < mMinBal))
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
// Returned:    Money
//***************************************************************************
Money MonthlyFee::chargeDepositFee(const Money balance) {
	
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
// Returned:    Money
//***************************************************************************
Money MonthlyFee::chargeWithdrawFee(const Money balance) {
	if (balance < mMinBal)
	{
		mbWentBelow = true;
	}
	return 0;
}
//***************************************************************************
// Function:		checkWentBelow
//
// Description: return bool if went below
//
// Parameters:  None
//
// Returned:    bool
//***************************************************************************
bool MonthlyFee::checkWentBelow() {
	return mbWentBelow;
}
//***************************************************************************
// Function:		read
//
// Description: read in from stream to fee
//
// Parameters:  rcIn				 - reference to istream
//
// Returned:    None
//***************************************************************************
void MonthlyFee::read(std::istream &rcIn){
	IFee::read(rcIn);
	rcIn >> mMinBal;
}
//***************************************************************************
// Function:		write
//
// Description: read into stream from min balance
//
// Parameters:  rcOut				 - reference to ostream
//
// Returned:    None
//***************************************************************************
void MonthlyFee::write(std::ostream &rcOut) {
	IFee::write(rcOut);
	rcOut << ", ";
	mMinBal.write(rcOut);
}