//***************************************************************************
// File name:  SavingsAccount.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    SavingsAccount class implamentation
//***************************************************************************
#include "SavingsAccount.h"

//***************************************************************************
// Constructor: SavingsAccount
//
// Description: Initialize SavingsAccount
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SavingsAccount::SavingsAccount() : IAccount (){
	
}
//***************************************************************************
// Constructor: SavingsAccount
//
// Description: Initialize SavingsAccount
//
// Parameters:  acctNum			 - Account Number
//							amt					 - Account Amount
//							interestRate - Account Interest Rate
//							pcTheFee		 - pointer to Acccounts fee
//
// Returned:    None
//***************************************************************************
SavingsAccount::SavingsAccount(int acctNum, Money amt,
	IInterestRate * pInterestRate, IFee* pcTheFee) : IAccount(acctNum, amt,
		pInterestRate, pcTheFee) {
	
}
//***************************************************************************
// Destructor:  SavingsAccount
//
// Description: Deconstructor for SavingsAccount
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
SavingsAccount::~SavingsAccount() {

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
void SavingsAccount::accept(IAccountVisitor *pcActVisitor) {
	pcActVisitor->visit(*this);

}