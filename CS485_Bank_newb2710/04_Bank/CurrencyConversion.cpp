
#include "CurrencyConversion.h"



CurrencyConversion::CurrencyConversion(std::string file) {
	std::ifstream currFile;
	Money cMoney1, cMoney2;
	std::string currency1, currency2;
	Currency cCur1, cCur2;
	double exchange;
	currFile.open(file);
	if (currFile.fail()) {
		std::cout << "Currency file failed to open";
	}

	while (currFile) {
		cMoney1.readCurrency(currFile);
		cMoney2.readCurrency(currFile);
		currFile >> exchange;
		cCur1 = cMoney1.getCurrency();
		cCur2 = cMoney2.getCurrency();
		mCurrencyConversion.insert({ std::make_pair(cCur1, cCur2), exchange });
	}
}

CurrencyConversion::~CurrencyConversion(){
}
CurrencyConversion & CurrencyConversion::getInstance()
{
	static CurrencyConversion instance;
	return instance;
}

double CurrencyConversion::convert(Currency c1, Currency c2)
{
	if (mCurrencyConversion.find({ std::make_pair(c1, c2) }) == mCurrencyConversion.end()) {
		return -1;
	}
	else {
		return mCurrencyConversion.at({ std::make_pair(c1, c2) });
	}
}
