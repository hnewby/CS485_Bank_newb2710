#include "WithdrawCmd.h"

//***************************************************************************
// Constructor: WithdrawCmd
//
// Description: Initialize WithdraeCmd
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
WithdrawCmd::WithdrawCmd() : WithdrawCmd(0, 0) {
}
//***************************************************************************
// Constructor: WithdrawCmd
//
// Description: Initialize WithdrawCmd
//
// Parameters:  acctNum - Account Number
//							amount	- Amount in account
//
// Returned:    None
//***************************************************************************
WithdrawCmd::WithdrawCmd(int acctNum, long long amount){
	mAcctNum = acctNum;
	mAmt = amount;
}
//***************************************************************************
// Destructor:  WithdrawCmd
//
// Description: Deconstructor for WithdrawCmd
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
WithdrawCmd::~WithdrawCmd() {

}
//***************************************************************************
// Function:		read
//
// Description: read in to WithdrawCmd
//
// Parameters:  rcIn - istream to read in from
//
// Returned:    None
//***************************************************************************
void WithdrawCmd::read(std::istream &rcIn) {
	rcIn >> mAcctNum >> mAmt;
}

void WithdrawCmd::action(Bank &rcTheBank) {
	rcTheBank.withdraw(mAcctNum, mAmt);
}