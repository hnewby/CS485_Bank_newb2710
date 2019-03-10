//***************************************************************************
// File name:  TransactioalFee.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    TransactionalFee class implamentation
//***************************************************************************
#include "TransactionalFee.h"

//***************************************************************************
// Constructor: TransactionalFee
//
// Description: Initialize TransactionalFee
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TransactionalFee::TransactionalFee() : IFee() {

}
//***************************************************************************
// Constructor: TransactionalFee
//
// Description: Initialize TransactionalFee
//
// Parameters:  minBalance - Minimum Balance
//							amount		 - fee amount
//
// Returned:    None
//***************************************************************************
TransactionalFee::TransactionalFee(long long minBalance,
	long long amount) : IFee (amount) {
	mMinBal = minBalance;
}
//***************************************************************************
// Destructor:  TransactionalFee
//
// Description: Deconstructor for TransactionalFee
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
TransactionalFee::~TransactionalFee() {

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
long long TransactionalFee::chargeMonthlyFee(const long long balance) {
	return 0;
	//not a monthly fee no charge
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
long long TransactionalFee::chargeDepositFee(const long long balance) {
	long long fee = 0;
	if (balance < mMinBal)
	{
		fee = getAmount();
	}
	return fee;
}
//***************************************************************************
// Function:		chargeWithdraeFee
//
// Description: charge the withdraw fee to account
//
// Parameters:  balance - balance of account
//
// Returned:    long long
//***************************************************************************
long long TransactionalFee::chargeWithdrawFee(const long long balance) {
	long long fee = 0;
	if (balance < mMinBal) {
		fee = getAmount();
	}
	return fee;
}
//***************************************************************************
// Function:		read
//
// Description: read in from stream to min balance
//
// Parameters:  rcIn - reference to istream
//
// Returned:    None
//***************************************************************************
void TransactionalFee::read(std::istream &rcIn) {
	rcIn >> mMinBal; //minBal first because thats the way file is
	IFee::read(rcIn);
}
//***************************************************************************
// Function:		write
//
// Description: write to stream from min balance
//
// Parameters:  rcOut - reference to ostream
//
// Returned:    None
//***************************************************************************
void TransactionalFee::write(std::ostream &rcOut) {
	rcOut << mMinBal << ", ";
	IFee::write(rcOut);
}