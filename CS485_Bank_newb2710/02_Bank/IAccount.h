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
#include "IFee.h"
#include <iostream>

class IAccount {
	public:
		IAccount();
		~IAccount();
		IAccount(int acctNum, long long acctBalance, double interestRate,
			IFee* pcTheFee);
		int getAcctNum();
		void deposit(long long amt);
		void withdraw(long long amt);
		void generateInterest();
		void endOfMonth();
		friend std::istream& operator >> (std::istream &rcIn,
			IAccount &rcTheAccount);
		friend std::ostream& operator << (std::ostream &rcOut,
			IAccount &rcTheAccount);

	protected:
		bool checkNegBal();

	private:
		int mAcctNum;
		long long mAcctBalance;
		double mInterestRate;
		IFee *mpcFee;
};
#endif