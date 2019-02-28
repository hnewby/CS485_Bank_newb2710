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
CheckingAccount::CheckingAccount(int acctNum, long long amt,
	float interestRate, IFee* pcTheFee) : IAccount(acctNum, amt, interestRate,
		pcTheFee) {
	
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