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
	rcOut << "F";
	rcOut << mInterestAmount;
}
void FlatInterestRate::read(std::istream &rcIn) {
	rcIn >> mInterestAmount;
}