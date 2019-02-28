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
IAccount::IAccount(int acctNum, long long acctBalance, float interestRate, IFee* pcTheFee) {
	mAcctNum = acctNum;
	mAcctBalance = acctBalance;
	mInterestRate = interestRate;
	mpcFee = pcTheFee;
}
int IAccount::getAcctNum() {
	return mAcctNum;
}
long long IAccount::getAcctBal() {
	return mAcctBalance;
}
void IAccount::deposit(long long amt) {
	mAcctBalance += amt;
	mAcctBalance -= mpcFee->chargeDepositFee(mAcctBalance); //charge fee is one
}
void IAccount::withdraw(long long amt) {
	mAcctBalance -= amt;
	mAcctBalance -= mpcFee->chargeDepositFee(mAcctBalance); //charge fee is one
}
void IAccount::generateInterest() {
	float temp;
	if (!checkNegBal())
	{
		temp = mAcctBalance * mInterestRate;
		mAcctBalance += static_cast<long long>(temp);
	}
}
void IAccount::setInterestRate(float interestRate) {
	mInterestRate = interestRate;
}
void IAccount::endOfMonth() {
	
	mAcctBalance -= mpcFee->chargeMonthlyFee(mAcctBalance);
	generateInterest(); //figure this out
}
std::istream& operator >> (std::istream &rcIn, IAccount &rcTheAccount) {
	rcIn >> rcTheAccount.mAcctNum >> rcTheAccount.mAcctBalance >> 
		rcTheAccount.mInterestRate >> *rcTheAccount.mpcFee;
	return (rcIn);
}

std::ostream& operator << (std::ostream &rcOut, IAccount &rcTheAccount) {
	float bal;// = rcTheAccount.mAcctBalance;
	float interest = rcTheAccount.mInterestRate;
	//std::string dollar = "$";

	bal = rcTheAccount.mAcctBalance / 100.00;
	interest *= 100;

	/*if (rcTheAccount.checkNegBal())
	{
		dollar = "$-";
	}*/

	rcOut << rcTheAccount.mAcctNum << ", " <<
		"$" << std::fixed << std::setprecision(2) << bal << ", " 
		<< std::fixed << std::setprecision(2)
		<< interest << "%, " << rcTheAccount.mpcFee;
	return rcOut;
}
//void IAccount::print(std::ostream &rcOut) {
//	float bal = mAcctBalance, interest = mInterestRate;
//
//
//	bal /= 100;
//	interest *= 100;
//	
//	rcOut << mAcctNum << ", " << std::fixed << std::setprecision(2) <<
//		"$" << bal << ", " << std::fixed << std::setprecision(2) 
//		<< interest << "%, " << mpcFee;
//}
bool IAccount::checkNegBal() {
	bool bNeg = false;
	if (mAcctBalance < 0)
	{
		bNeg = true;
	}
	return bNeg;
}