//***************************************************************************
// File name:  Money.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Money class header
//***************************************************************************
#pragma once
#ifndef Money_h
#define Money_h

#include <iostream>
#include <fstream>

class Money {
	public:
		Money();
		Money(long long amount);
		~Money();
		Money& operator + (Money &rcAmount);
		Money& operator - (Money &rcAmount);
		Money& operator / (Money &rcAmount);
		double operator / (double amount);
		Money& operator * (Money &rcAmount);
		Money& operator = (Money &rcAmount);
		Money& operator -= (Money &rcAmount);
		Money& operator += (Money &rcAmount);
		bool operator == (Money &rcAmount);
		bool operator < (Money &rcAmount);
		bool operator > (Money &rcAmount);
		bool operator <= (Money &rcAmount);
		bool operator >= (Money &rcAmount);
		bool operator < (int amt);
		Money& operator * (double amount);
		friend Money& operator * (double dblAmount, Money& moneyAmount);
		friend std::istream& operator >> (std::istream &rcIn, Money &rcAmount);
		friend std::ostream& operator << (std::ostream &rcOut, Money &rcAmount);

		void read(std::istream& rcIn);
		void write(std::ostream& rcOut);

	private:
		long long mAmount;
};
#endif