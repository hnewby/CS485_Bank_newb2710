#include "IAccount.h"

IAccount::IAccount() {
	mAcctBalance = 0;
	mAcctNum = 0;
	//mcFee = new IFee();
}
IAccount::~IAccount() {

}
IAccount::IAccount(int acctNum, long long acctBalance, float interestRate, IFee &rcTheFee) {
	mAcctNum = acctNum;
	mAcctBalance = acctBalance;
	mInterestRate = interestRate;
	//mcFee = theFee; // this wont work need to figure out
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
	//do nothing if acct bal neg
}
void IAccount::setInterestRate(float interestRate) {
	mInterestRate = interestRate;
}
void IAccount::endOfMonth() {
	generateInterest(); //figure this out
	mAcctBalance -= mpcFee->chargeMonthlyFee(mAcctBalance);
}
std::istream& operator >> (std::istream &rcIn, IAccount &rcTheAccount) {
	rcIn >> rcTheAccount.mAcctBalance >> 
		rcTheAccount.mInterestRate >> *rcTheAccount.mpcFee;
	return (rcIn);
}

bool IAccount::checkNegBal() {
	bool bNeg = false;
	if (mAcctBalance < 0)
	{
		bNeg = true;
	}
	return bNeg;
}