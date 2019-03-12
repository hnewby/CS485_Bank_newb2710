#include "FlatInterestRate.h"

FlatInterestRate::FlatInterestRate() {
	mInterestAmount = 0;
}
FlatInterestRate::~FlatInterestRate() {

}
Money FlatInterestRate::generateInterest(Money &rcMoney) {
	return (rcMoney * mInterestAmount);
}
void FlatInterestRate::write(std::ostream &rcOut) {
	const double DIV = 100.00;
	const int DECIMAL = 2;
	double bal = mInterestAmount * DIV;
	rcOut << "F " << std::fixed << std::setprecision(DECIMAL) << bal << "%";
}
void FlatInterestRate::read(std::istream &rcIn) {
	rcIn >> mInterestAmount;
}