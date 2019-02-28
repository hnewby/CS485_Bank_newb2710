//***************************************************************************
// File name:  IFee.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IFee class header
//***************************************************************************
#pragma once
#include <iostream>
class IFee {
	public:
		IFee();
		IFee(long long amount);
		~IFee();
		virtual long long chargeMonthlyFee(const long long balance) = 0;
		virtual long long chargeDepositFee(const long long balance) = 0;
		virtual long long chargeWithdrawFee(const long long balance) = 0;
		friend std::istream& operator >> (std::istream &rcIn, IFee &rcFee);
		friend std::ostream& operator << (std::ostream &rcOut, IFee* pcFee);
		virtual void read(std::istream& rcIn);
		virtual void write(std::ostream &rcOut);
protected:
		long long getAmount(); // might not need this

	private:
		long long mAmount;
};