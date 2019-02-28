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
	//do nothing not a monthly fee
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

void TransactionalFee::read(std::istream &rcIn) {
	rcIn >> mMinBal; //minBal first because thats the way file is
	IFee::read(rcIn);
}

void TransactionalFee::write(std::ostream &rcOut) {
	rcOut << mMinBal << ", ";
	IFee::write(rcOut);
}