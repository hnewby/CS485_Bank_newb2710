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
#include "Money.h"
class IFee {
	public:
		IFee();
		IFee(Money amount);
		~IFee();
		virtual Money chargeMonthlyFee(const Money balance) = 0;
		virtual Money chargeDepositFee(const Money balance) = 0;
		virtual Money chargeWithdrawFee(const Money balance) = 0;
		friend std::istream& operator >> (std::istream &rcIn, IFee &rcFee);
		friend std::ostream& operator << (std::ostream &rcOut, IFee* pcFee);
		virtual void read(std::istream& rcIn);
		virtual void write(std::ostream &rcOut);
protected:
		Money getAmount(); 

	private:
		Money mAmount;
};