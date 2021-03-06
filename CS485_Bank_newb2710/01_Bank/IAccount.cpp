//***************************************************************************
// File name:  IAccount.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IAccount class implamentation
//***************************************************************************
#include "IAccount.h"
#include <string>
#include <iomanip>

//***************************************************************************
// Constructor: IAccount
//
// Description: Initialize IAccount
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
IAccount::IAccount() {
	mAcctBalance = 0;
	mAcctNum = 0;
	mInterestRate = 0.0;
	mpcFee = nullptr;
}
//***************************************************************************
// Destructor:  IAccount
//
// Description: Deconstructor for IAccount
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
IAccount::~IAccount() {
	delete mpcFee;
}
//***************************************************************************
// Constructor: IAccount
//
// Description: Initialize IAccount
//
// Parameters:  acctNum			 - Account Number
//							amt					 - Account Amount
//							interestRate - Account Interest Rate
//							pcTheFee		 - pointer to Acccounts fee
//
// Returned:    None
//***************************************************************************
IAccount::IAccount(int acctNum, long long acctBalance, double interestRate,
	IFee* pcTheFee) {
	mAcctNum = acctNum;
	mAcctBalance = acctBalance;
	mInterestRate = interestRate;
	mpcFee = pcTheFee;
}
//***************************************************************************
// Function:		getAcctNum
//
// Description: return account number
//
// Parameters:  None
//
// Returned:    int
//***************************************************************************
int IAccount::getAcctNum() {
	return mAcctNum;
}
//***************************************************************************
// Function:		deposit
//
// Description: deposit amount to balance
//
// Parameters:  amt - amount to be deposited
//
// Returned:    None
//***************************************************************************
void IAccount::deposit(long long amt) {
	mAcctBalance += amt;
	mAcctBalance -= mpcFee->chargeDepositFee(mAcctBalance); 
}
//***************************************************************************
// Function:		withdraw
//
// Description: withdraw amount from balance
//
// Parameters:  amt - amount to be withdrawn
//
// Returned:    None
//***************************************************************************
void IAccount::withdraw(long long amt) {
	mAcctBalance -= amt;
	mAcctBalance -= mpcFee->chargeDepositFee(mAcctBalance); 
}
//***************************************************************************
// Function:		generateInterest
//
// Description: determine interest on account
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void IAccount::generateInterest() {
	double temp;
	if (!checkNegBal())
	{
		temp = mAcctBalance * mInterestRate;
		mAcctBalance += static_cast<long long>(temp);
	}
}
//***************************************************************************
// Function:		endOfMonth
//
// Description: run end of month functions
//
// Parameters:	None
//
// Returned:    None
//***************************************************************************
void IAccount::endOfMonth() {
	
	mAcctBalance -= mpcFee->chargeMonthlyFee(mAcctBalance);
	generateInterest(); 
}
//***************************************************************************
// Function:		operator >>
//
// Description: read in from stream to account
//
// Parameters:  rcIn				 - reference to istream
//							rcTheAccount - refernce to account to read into
//
// Returned:    istream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, IAccount &rcTheAccount) {
	rcIn >> rcTheAccount.mAcctNum >> rcTheAccount.mAcctBalance >> 
		rcTheAccount.mInterestRate >> *rcTheAccount.mpcFee;
	return (rcIn);
}
//***************************************************************************
// Function:		operator <<
//
// Description: read to from stream from account
//
// Parameters:  rcOut				 - reference to ostream
//							rcTheAccount - refernce to account to read from
//
// Returned:    ostream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, IAccount &rcTheAccount) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal;
	double interest = rcTheAccount.mInterestRate;

	bal = rcTheAccount.mAcctBalance / DIV;
	interest *= DIV;

	rcOut << rcTheAccount.mAcctNum << ", " <<
		"$" << std::fixed << std::setprecision(DECIMAL) << bal << ", " 
		<< std::fixed << std::setprecision(DECIMAL)
		<< interest << "%, " << rcTheAccount.mpcFee;
	return rcOut;
}
//***************************************************************************
// Function:		checkNegBal
//
// Description: check if balance is negative
//
// Parameters:  None
//
// Returned:    bool
//***************************************************************************
bool IAccount::checkNegBal() {
	bool bNeg = false;
	if (mAcctBalance < 0)
	{
		bNeg = true;
	}
	return bNeg;
}