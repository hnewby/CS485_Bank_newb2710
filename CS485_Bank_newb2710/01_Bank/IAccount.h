//***************************************************************************
// File name:  Account.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Account class header
//***************************************************************************
#pragma once
#include "IFee.h"
#include <iostream>
class IAccount {
	public:
		IAccount();
		~IAccount();
		IAccount(int acctNum, long long acctBalance, float interestRate, IFee* pcTheFee);
		int getAcctNum();
		long long getAcctBal();
		void deposit(long long amt);
		void withdraw(long long amt);
		void generateInterest();
		void setInterestRate(float interestRate);
		void endOfMonth();
		friend std::istream& operator >> (std::istream &rcIn, IAccount &rcTheAccount);

	protected:
		bool checkNegBal();

	private:
		int mAcctNum;
		long long mAcctBalance;
		float mInterestRate;
		IFee *mpcFee;
};