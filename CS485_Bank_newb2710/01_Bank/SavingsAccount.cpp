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
SavingsAccount::SavingsAccount(int acctNum, long long amt,
	float interestRate, IFee* pcTheFee) : IAccount(acctNum, amt, interestRate,
		pcTheFee) {
	
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