#include "Money.h"

Money::Money() {
	mAmount = 0;
}
Money::Money(long long amount) {
	mAmount = amount;
}
Money::~Money() {

}
Money Money::operator + (const Money &rcAmount) const {
	Money cAdd;
	cAdd = mAmount + rcAmount.mAmount;
	return cAdd;
}
Money Money::operator - (const Money &rcAmount) const {
	Money cSub;
	cSub = mAmount - rcAmount.mAmount;
	return cSub;
}
Money Money::operator / (const Money &rcAmount) const {
	Money cAmount;
	cAmount = mAmount / rcAmount.mAmount;
	return cAmount;
}
double Money::operator / (const double amount) const {
	double amt;
	amt = mAmount / amount;
	return amt;
}
Money Money::operator * (const Money &rcAmount) const {
	Money cAmount;
	cAmount = mAmount * rcAmount.mAmount;
	return cAmount;
}
Money& Money::operator = (const Money &rcAmount) {
	mAmount = rcAmount.mAmount;
	return *this;
}
bool Money::operator == (const Money &rcAmount) const {
	bool bIsEqual = false;
	if (mAmount == rcAmount.mAmount)
	{
		bIsEqual = true;
	}
	return bIsEqual;
}
Money& Money::operator -= (const Money &rcAmount) {
	mAmount -= rcAmount.mAmount;
	return *this;
}
Money& Money::operator += (const Money &rcAmount) {
	mAmount += rcAmount.mAmount;
	return *this;
}
bool Money::operator <(const Money &rcAmount) const {
	bool bIsLess = false;
	if (mAmount < rcAmount.mAmount)
	{
		bIsLess = true;
	}
	return bIsLess;
}
bool Money::operator > (const Money &rcAmount) const {
	bool bIsGreater = false;
	if (mAmount > rcAmount.mAmount)
	{
		bIsGreater = true;
	}
	return bIsGreater;
}
bool Money::operator <= (const Money &rcAmount) const {
	bool bIsLessEq = false;
	if (mAmount <= rcAmount.mAmount)
	{
		bIsLessEq = true;
	}
	return bIsLessEq;
}
bool Money::operator >= (const Money &rcAmount) const {
	bool bIsGreaterEq = false;
	if (mAmount >= rcAmount.mAmount) {
		bIsGreaterEq = true;
	}
	return bIsGreaterEq;
}
bool Money::operator < (const int amt) const {
	bool bIsLess = false;
	if (mAmount < amt) {
		bIsLess = true;
	}
	return bIsLess;
}
Money Money::operator * (const double amount) const {
	Money cAmount;
	cAmount = mAmount * static_cast<long long>(amount);
	return cAmount;
}
Money operator * (double dblAmount, Money& moneyAmount) {
	moneyAmount.mAmount *= static_cast<long long>(dblAmount);
	return(moneyAmount);
}
std::istream& operator >> (std::istream &rcIn, Money &rcAmount) {
	rcAmount.read(rcIn);
	return rcIn;
}
std::ostream& operator << (std::ostream &rcOut, Money &rcAmount) {
	rcAmount.write(rcOut);
	return rcOut;
}

void Money::read(std::istream& rcIn) {
	rcIn >> mAmount;
}
void Money::write(std::ostream& rcOut) {
	rcOut << mAmount;
}