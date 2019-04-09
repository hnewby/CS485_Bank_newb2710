
#include "CurrencyConversion.h"

CurrencyConversion::CurrencyConversion(std::string file) {
	std::ifstream currFile;
	Money cMoney;
	std::string currency1, currency2;
	Currency cCur1, cCur2;
	double exchange;
	currFile.open(file);
	if (currFile.fail()) {
		std::cout << "Currency file failed to open";
	}

	while (currFile) {
		currFile >> currency1 >> currency2 >> exchange;
		cCur1 = cMoney.strToEnum(currency1);
		cCur2 = cMoney.strToEnum(currency2);
	}
}