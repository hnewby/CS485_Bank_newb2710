//***************************************************************************
// File name:  Money.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: Money
// Purpose:    Money class implamentation
//***************************************************************************
#include "Money.h"

//***************************************************************************
// Constructor: Money
//
// Description: Initialize Money
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Money::Money() {
	mAmount = 0;
}
//***************************************************************************
// Constructor: Money
//
// Description: Initialize Money
//
// Parameters:  amount - amount to inititialize money to
//
// Returned:    None
//***************************************************************************
Money::Money(long long amount) {
	mAmount = amount;
}
//***************************************************************************
// Destructor:  Money
//
// Description: Deconstructor for Money
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Money::~Money() {

}
//***************************************************************************
// Function:		operator +
//
// Description: add two Money amounts
//
// Parameters:  rcAmount - amount of money to add
//
// Returned:    Money
//***************************************************************************
Money Money::operator + (const Money &rcAmount) const {
	Money cAdd;
	cAdd = mAmount + rcAmount.mAmount;
	return cAdd;
}
//***************************************************************************
// Function:		operator -
//
// Description: subtract two Money amounts
//
// Parameters:  rcAmount - amount of money to subtract
//
// Returned:    Money
//***************************************************************************
Money Money::operator - (const Money &rcAmount) const {
	Money cSub;
	cSub = mAmount - rcAmount.mAmount;
	return cSub;
}
//***************************************************************************
// Function:		operator /
//
// Description: divide two Money amounts
//
// Parameters:  rcAmount - amount of money to divide by
//
// Returned:    Money
//***************************************************************************
Money Money::operator / (const Money &rcAmount) const {
	Money cAmount;
	cAmount = mAmount / rcAmount.mAmount;
	return cAmount;
}
//***************************************************************************
// Function:		operator /
//
// Description:	divide two Money amounts
//
// Parameters:  rcAmount - amount of money to divide
//
// Returned:    double
//***************************************************************************
double Money::operator / (const double amount) const {
	double amt;
	amt = mAmount / amount;
	return amt;
}
//***************************************************************************
// Function:		operator *
//
// Description: multiply two Money amounts
//
// Parameters:  rcAmount - amount of money to multiply
//
// Returned:    Money
//***************************************************************************
Money Money::operator * (const Money &rcAmount) const {
	Money cAmount;
	cAmount = mAmount * rcAmount.mAmount;
	return cAmount;
}
//***************************************************************************
// Function:		operator =
//
// Description: set Money amounts equal
//
// Parameters:  rcAmount - amount of money to set equal
//
// Returned:    Money&
//***************************************************************************
Money& Money::operator = (const Money &rcAmount) {
	mAmount = rcAmount.mAmount;
	return *this;
}
//***************************************************************************
// Function:		operator ==
//
// Description: check if two moneys are equal
//
// Parameters:  rcAmount - amount of money to check against
//
// Returned:    bool
//***************************************************************************
bool Money::operator == (const Money &rcAmount) const {
	bool bIsEqual = false;
	if (mAmount == rcAmount.mAmount){
		bIsEqual = true;
	}
	return bIsEqual;
}
//***************************************************************************
// Function:		operator -=
//
// Description: minus equal from amount
//
// Parameters:  rcAmount - amount of money to subtract
//
// Returned:    Money&
//***************************************************************************
Money& Money::operator -= (const Money &rcAmount) {
	mAmount -= rcAmount.mAmount;
	return *this;
}
//***************************************************************************
// Function:		operator +=
//
// Description: add two Money amounts
//
// Parameters:  rcAmount - amount of money to add
//
// Returned:    Money&
//***************************************************************************
Money& Money::operator += (const Money &rcAmount) {
	mAmount += rcAmount.mAmount;
	return *this;
}
//***************************************************************************
// Function:		operator <
//
// Description: check if less than
//
// Parameters:  rcAmount - amount of money to check
//
// Returned:    bool
//***************************************************************************
bool Money::operator <(const Money &rcAmount) const {
	bool bIsLess = false;
	if (mAmount < rcAmount.mAmount)
	{
		bIsLess = true;
	}
	return bIsLess;
}
//***************************************************************************
// Function:		operator >
//
// Description: check if greater than
//
// Parameters:  rcAmount - amount of money to check
//
// Returned:    bool
//***************************************************************************
bool Money::operator > (const Money &rcAmount) const {
	bool bIsGreater = false;
	if (mAmount > rcAmount.mAmount) {
		bIsGreater = true;
	}
	return bIsGreater;
}
bool Money::operator <= (const Money &rcAmount) const {
	bool bIsLessEq = false;
	if (mAmount <= rcAmount.mAmount) {
		bIsLessEq = true;
	}
	return bIsLessEq;
}
//***************************************************************************
// Function:		operator >=
//
// Description: check if greater than or equals to
//
// Parameters:  rcAmount - amount of money to check
//
// Returned:    bool
//***************************************************************************
bool Money::operator >= (const Money &rcAmount) const {
	bool bIsGreaterEq = false;
	if (mAmount >= rcAmount.mAmount) {
		bIsGreaterEq = true;
	}
	return bIsGreaterEq;
}
//***************************************************************************
// Function:		operator <
//
// Description: check if less than
//
// Parameters:  amt - amount to check against
//
// Returned:    bool
//***************************************************************************
bool Money::operator < (const int amt) const {
	bool bIsLess = false;
	if (mAmount < amt) {
		bIsLess = true;
	}
	return bIsLess;
}
//***************************************************************************
// Function:		operator  *
//
// Description: multiple money and double
//
// Parameters:  amount - double to multiple by
//
// Returned:    Money
//***************************************************************************
Money Money::operator * (const double amount) const {
	Money cAmount;
	cAmount = static_cast<long long>(mAmount * amount);
	return cAmount;
}
//***************************************************************************
// Function:		operator  *
//
// Description: multiple money and double
//
// Parameters:  dblAmount		- double to multiple 
//							moneyAmount - Money about to multiply
//
// Returned:    Money
//***************************************************************************
Money operator * (double dblAmount, Money& moneyAmount) {
	moneyAmount.mAmount = static_cast<long long>(moneyAmount.mAmount * dblAmount);
	return(moneyAmount);
}
//***************************************************************************
// Function:		operator  >>
//
// Description: read into money
//
// Parameters:  rcIn		 - istream reading from
//							rcAmount - amount of money to check
//
// Returned:    istream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, Money &rcAmount) {
	rcAmount.read(rcIn);
	return rcIn;
}
//***************************************************************************
// Function:		operator  <<
//
// Description: read out of money
//
// Parameters:  rcOut		 - istream reading from
//							rcAmount - amount of money to check
//
// Returned:    istream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, Money &rcAmount) {
	rcAmount.write(rcOut);
	return rcOut;
}
//***************************************************************************
// Function:		read
//
// Description: read into money
//
// Parameters:  rcIn - reference to istream
//
// Returned:    void
//***************************************************************************
void Money::read(std::istream& rcIn) {
	rcIn >> mAmount;
}
//***************************************************************************
// Function:		write
//
// Description: write from money
//
// Parameters:  rcOut - reference to ostream
//
// Returned:    void
//***************************************************************************
void Money::write(std::ostream& rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal = mAmount / DIV;
	rcOut << "$" << std::fixed << std::setprecision(DECIMAL) << bal;
}