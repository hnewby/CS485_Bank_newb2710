//***************************************************************************
// File name:  CheckingAccount.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Checking Account class implamentation
//***************************************************************************
#include "CheckingAccount.h"

//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initialize CheckingAccount
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CheckingAccount::CheckingAccount() : IAccount() {
	IFee* pcFee = new TransactionalFee();
	CheckingAccount(0, 0, 0, pcFee);
}
//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initialize CheckingAccount
//
// Parameters:  acctNum			 - Account Number
//							amt					 - Account Amount
//							interestRate - Account Interest Rate
//							pcTheFee		 - pointer to Acccounts fee
//
// Returned:    None
//***************************************************************************
CheckingAccount::CheckingAccount(int acctNum, Money amt,
	IInterestRate* pInterestRate, IFee* pcTheFee) : IAccount(acctNum, amt,
		pInterestRate, pcTheFee) {
	
}
//***************************************************************************
// Destructor:  CheckingAccount
//
// Description: Deconstructor for CheckingAccount
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
CheckingAccount::~CheckingAccount() {

}
//***************************************************************************
// Function:		accept
//
// Description: accept visitor and call visit
//
// Parameters:  pcAcctVisitor - pointer to account visitor using
//
// Returned:    None
//***************************************************************************
void CheckingAccount::accept(IAccountVisitor *pcActVisitor) {
	pcActVisitor->visit(*this);

}