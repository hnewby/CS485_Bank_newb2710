//***************************************************************************
// File name:  CheckingAccount.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CheckingAccount class header
//***************************************************************************
#pragma once
#include "IAccount.h"
#include "TransactionalFee.h"

class CheckingAccount : public IAccount {
	public:
		CheckingAccount();
		CheckingAccount(int acctNum, Money amt,
			IInterestRate * pInterestRate, IFee* pcTheFee);
		~CheckingAccount();
		void accept(IAccountVisitor *pcActVisitor);
	private:

};