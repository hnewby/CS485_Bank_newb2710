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
#include <iomanip>
#include <unordered_map>

enum class Currency {USD, GBP, EUR, YEN, ERR};
std::istream& operator >> (std::istream &rcIn,
	Currency &rcCurr);
const static std::unordered_map<std::string, Currency>strToEnum;
const static std::unordered_map<Currency, std::string>enumToStr;
class Money {
	public:
		Money();
		Money(long long amount);
		Money(long long amount, Currency cur);
		~Money();
		Money operator + (const Money &rcAmount) const;
		Money operator - (const Money &rcAmount) const;
		Money operator / (const Money &rcAmount) const;
		double operator / (const double amount) const;
		Money operator * (const Money &rcAmount) const;
		Money& operator = (const Money &rcAmount);
		Money& operator -= (const Money &rcAmount);
		Money& operator += (const Money &rcAmount);
		bool operator == (const Money &rcAmount) const;
		bool operator < (const Money &rcAmount) const;
		bool operator > (const Money &rcAmount) const;
		bool operator <= (const Money &rcAmount) const;
		bool operator >= (const Money &rcAmount) const;
		bool operator < (const int amt) const;
		Money operator * (const double amount) const;
		friend Money operator * (double dblAmount,Money& moneyAmount);
		friend std::istream& operator >> (std::istream &rcIn, 
			Money &rcAmount);
		friend std::ostream& operator << (std::ostream &rcOut,
			Money &rcAmount);
		void readCurrency(std::istream& rcIn);
		void writeCurrency(std::ostream& rcOut);
		void read(std::istream& rcIn);
		void write(std::ostream& rcOut);


		Currency getCurrency();
		Money convert(double exchange);
		double getExRate(Currency &rcCurr);
		Money calcExchange(Money &rcMoney);



		
	private:
		double checkCurrency(const Currency &rcCurr) const; // check for exception
		long long mAmount;
		Currency meCurrency;
		
};
#endif