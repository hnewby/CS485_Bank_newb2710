#include "Money.h"

Money::Money() {
	mAmount = 0;
}
Money::Money(long long amount) {
	mAmount = amount;
}
Money::~Money() {

}
Money& Money::operator + (Money &rcAmount) {
	mAmount += rcAmount.mAmount;
}
Money& Money::operator - (Money &rcAmount) {
	mAmount -= rcAmount.mAmount;
}
Money& Money::operator / (Money &rcAmount) {
	mAmount /= rcAmount.mAmount;
}
double Money::operator / (double amount) {
	mAmount / amount;
}
Money& Money::operator * (Money &rcAmount) {
	mAmount *= rcAmount.mAmount;
}
Money& Money::operator = (Money &rcAmount) {
	mAmount = rcAmount.mAmount;
}
bool Money::operator == (Money &rcAmount) {
	bool bIsEqual = false;
	if (mAmount == rcAmount.mAmount)
	{
		bIsEqual = true;
	}
	return bIsEqual;
}
Money& Money::operator -= (Money &rcAmount) {
	mAmount -= rcAmount.mAmount;
}
Money& Money::operator += (Money &rcAmount) {
	mAmount += rcAmount.mAmount;
}
bool Money::operator < (Money &rcAmount) {
	bool bIsLess = false;
	if (mAmount < rcAmount.mAmount)
	{
		bIsLess = true;
	}
	return bIsLess;
}
bool Money::operator > (Money &rcAmount) {
	bool bIsGreater = false;
	if (mAmount > rcAmount.mAmount)
	{
		bIsGreater = true;
	}
	return bIsGreater;
}
bool Money::operator <= (Money &rcAmount) {
	bool bIsLessEq = false;
	if (mAmount <= rcAmount.mAmount)
	{
		bIsLessEq = true;
	}
	return bIsLessEq;
}
bool Money::operator >= (Money &rcAmount) {
	bool bIsGreaterEq = false;
	if (mAmount >= rcAmount.mAmount) {
		bIsGreaterEq = true;
	}
	return bIsGreaterEq;
}
bool Money::operator < (int amt) {
	bool bIsLess = false;
	if (mAmount < amt) {
		bIsLess = true;
	}
	return bIsLess;
}
Money& Money::operator * (double amount) {
	mAmount *= static_cast<long long>(amount); //might have to static cast whole thing
}
Money& operator * (double dblAmount, Money& moneyAmount) {
	moneyAmount.mAmount *= dblAmount;
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