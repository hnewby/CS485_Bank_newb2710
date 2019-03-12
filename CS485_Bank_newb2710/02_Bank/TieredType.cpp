#include "TieredType.h"
#include <iomanip>

TieredType::TieredType() {
	mInterestAmount = 0;
}
TieredType::~TieredType() {

}
Money TieredType::generateInterest(Money &rcMoney) {
	return (rcMoney * mInterestAmount);
}
void TieredType::writeBalance(std::ostream &rcOut) {
	rcOut << mBalanceAmount;
	//figure this out
}

void TieredType::writeInterest(std::ostream &rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal;
	double interest = mInterestAmount;

	bal = mBalanceAmount / DIV;
	interest *= DIV;
	rcOut << std::fixed << std::setprecision(DECIMAL) << mInterestAmount;
}
//void read(std::istream &rcIn);
bool TieredType::checkBalance(Money &rcMoney) {
	return (rcMoney > mBalanceAmount);
}
//bool TieredType::operator > (TieredType cT1, TieredType cT2) {
//	return (cT1)
//}
bool operator > (TieredType &rcT1, TieredType &rcT2) {
	return (rcT1.mBalanceAmount > rcT2.mBalanceAmount);
}
