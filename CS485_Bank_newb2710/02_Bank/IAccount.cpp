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
#include "FlatInterestRate.h"
#include "TieredInterestRate.h"
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
	//mcAcctBalance = 0;
	mAcctNum = 0;
	mpcInterestRate = nullptr;
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
IAccount::IAccount(int acctNum, Money acctBalance, IInterestRate *pInterestRate,
	IFee* pcTheFee) {
	mAcctNum = acctNum;
	mcAcctBalance = acctBalance;
	mpcInterestRate = pInterestRate;
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
void IAccount::deposit(Money amt) {
	mcAcctBalance += amt;
	mcAcctBalance -= mpcFee->chargeDepositFee(mcAcctBalance); 
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
void IAccount::withdraw(Money amt) {
	mcAcctBalance -= amt;
	mcAcctBalance -= mpcFee->chargeDepositFee(mcAcctBalance); 
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
	
	mcAcctBalance -= mpcFee->chargeMonthlyFee(mcAcctBalance);
	mpcInterestRate->generateInterest(mcAcctBalance); 
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
	char interestType;
	//IInterestRate *pcRate = nullptr;
	rcIn >> rcTheAccount.mAcctNum >> rcTheAccount.mcAcctBalance >> interestType;


	switch (interestType) {
	case 'F':
		rcTheAccount.mpcInterestRate = new FlatInterestRate();
		break;
	case 'T':
		rcTheAccount.mpcInterestRate = new TieredInterestRate();
		break;
	}

		rcIn >> *rcTheAccount.mpcInterestRate >> *rcTheAccount.mpcFee;
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

	bal = rcTheAccount.mcAcctBalance / DIV;

	rcOut << rcTheAccount.mAcctNum << ", " <<
		"$" << std::fixed << std::setprecision(DECIMAL) << bal << ", ";
	rcOut << rcTheAccount.mpcInterestRate;
		rcOut << rcTheAccount.mpcFee;
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
	if (mcAcctBalance < 0)
	{
		bNeg = true;
	}
	return bNeg;
}