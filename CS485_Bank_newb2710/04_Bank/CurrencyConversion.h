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
	struct KeyHash {
		std::size_t operator()(const std::pair<Currency, Currency> k) const
		{
			
			return std::hash<Currency>()(k.first) ^ 
				(std::hash<Currency>()(k.second) << 1);
		}
	};
	struct KeyEqual {
		bool operator()(const std::pair<Currency, Currency> lhs, 
			const std::pair<Currency, Currency> rhs) const
		{
			
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};
	public:
		static CurrencyConversion& getInstance();
		double convert(Currency, Currency);
		void insert(Currency, Currency, double);

	private:
		CurrencyConversion(); //need to return instance
		~CurrencyConversion();
		CurrencyConversion(CurrencyConversion const&) = delete;
		CurrencyConversion& operator=(CurrencyConversion const&) = delete;

		std::unordered_map < std::pair<Currency, Currency>, double,
			KeyHash, KeyEqual > mCurrencyConversion;
};