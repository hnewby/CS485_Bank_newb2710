//***************************************************************************
// File name:  IInterestRate.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IInterestRate class header
//***************************************************************************
#pragma once
#ifndef IInterestRate_h
#define IInterestRate_h
#include "Money.h"
#include <fstream>
#include <iostream>

class IInterestRate {
	public:
		IInterestRate();
		~IInterestRate();
		virtual Money generateInterest(Money &rcMoney) = 0;
		virtual void write(std::ostream &rcOut) = 0;
		virtual void read(std::istream &rcIn) = 0;
		friend std::istream& operator >> (std::istream &rcIn, IInterestRate &rcRate);
		friend std::ostream& operator << (std::ostream &rcOut, IInterestRate *pcRate);

	private:
};
#endif