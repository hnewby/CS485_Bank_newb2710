//***************************************************************************
// File name:  DepositCmd.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    DepositCmd class implamentation
//***************************************************************************
#include "DepositCmd.h"

//***************************************************************************
// Constructor: DepositCmd
//
// Description: Initialize DepositCmd
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
DepositCmd::DepositCmd() : DepositCmd(0, 0) {

}
//***************************************************************************
// Constructor: DepositCmd
//
// Description: Initialize DepositCmd
//
// Parameters:  acctNum - Account Number
//							amount  - Account Amount
//
// Returned:    None
//***************************************************************************
DepositCmd::DepositCmd(int acctNum, long long amount) {
	mAcctNum = acctNum;
	mAmt = amount;
}
//***************************************************************************
// Destructor:  DepositCmd
//
// Description: Deconstructor for DepositCmd
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
DepositCmd::~DepositCmd() {

}
//***************************************************************************
// Function:		read
//
// Description: read in to DepositCmd
//
// Parameters:  rcIn - istream to read in from
//
// Returned:    None
//***************************************************************************
void DepositCmd::read(std::istream &rcIn) {
	rcIn >> mAcctNum >> mAmt;
}
//***************************************************************************
// Function:		action
//
// Description: deposit money to account
//
// Parameters:  rcTheBank - reference to bank
//
// Returned:    None
//***************************************************************************
void DepositCmd::action(Bank &rcTheBank) {
	rcTheBank.deposit(mAcctNum, mAmt);
}