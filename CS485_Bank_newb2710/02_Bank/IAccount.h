//***************************************************************************
// File name:  Account.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Account class header
//***************************************************************************
#ifndef IAccount_h
#define IAccount_h
#include "Money.h"
#include "IFee.h"
#include "IInterestRate.h"
#include <iostream>

class IAccount {
	public:
		IAccount();
		~IAccount();
		IAccount(int acctNum, Money acctBalance, IInterestRate * pInterestRate,
			IFee* pcTheFee);
		int getAcctNum();
		void deposit(Money amt);
		void withdraw(Money amt);
		void endOfMonth();
		friend std::istream& operator >> (std::istream &rcIn,
			IAccount &rcTheAccount);
		friend std::ostream& operator << (std::ostream &rcOut,
			IAccount &rcTheAccount);

	protected:
		bool checkNegBal();

	private:
		int mAcctNum;
		Money mcAcctBalance;
		IInterestRate* mpcInterestRate;
		IFee *mpcFee;
};
#endif