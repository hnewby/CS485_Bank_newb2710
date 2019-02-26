#include "IAccount.h"

IAccount::IAccount() {

}
IAccount::~IAccount() {

}
IAccount::IAccount(int acctNum, long long acctBalance, float interestRate, IFee theFee) {
	mAcctNum = acctNum;
	mAcctBalance = acctBalance;
	mInterestRate = interestRate;
	mcFee = theFee; // this wont work need to figure out
}
int IAccount::getAcctNum() {
	return mAcctNum;
}
long long IAccount::getAcctBal() {
	return mAcctBalance;
}
void IAccount::deposit(long long amt) {
	mAcctBalance += amt;
	mAcctBalance -= mcFee.chargeDepositFee(mAcctBalance); //charge fee is one
}
void IAccount::withdraw(long long amt) {
	mAcctBalance -= amt;
	mAcctBalance -= mcFee.chargeDepositFee(mAcctBalance); //charge fee is one
}
void IAccount::generateInterest() {
	//do nothing if acct bal neg
}
void IAccount::setInterestRate(float interestRate) {
	mInterestRate = interestRate;
}
void IAccount::endOfMonth() {
	generateInterest(); //figure this out
	mAcctBalance -= mcFee.chargeMonthlyFee(mAcctBalance);
}
std::istream& operator >> (std::istream &rcIn, IAccount &rcTheAccount) {
	//what is this doing?
}

bool IAccount::checkNegBal() {
	bool bNeg = false;
	if (mAcctBalance < 0)
	{
		bNeg = true;
	}
	return bNeg;
}