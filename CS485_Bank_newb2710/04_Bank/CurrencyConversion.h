//***************************************************************************
// File name:  CurrencyConversion.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CurrencyConversion class header
//***************************************************************************
#pragma once
#include <string>
#include "Money.h"
class CurrencyConversion {
	public:
		static CurrencyConversion& getInstance();
		double convert(Currency, Currency);

	private:
		CurrencyConversion(std::string file);
		~CurrencyConversion();
		CurrencyConversion(CurrencyConversion const&) = delete;
		CurrencyConversion& operator=(CurrencyConversion const&) = delete;
};