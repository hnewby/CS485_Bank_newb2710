#include "TieredInterestRate.h"

TieredInterestRate::TieredInterestRate() {
	mvcInterest.clear;
	//mInterestAmount = 0;
}
TieredInterestRate::~TieredInterestRate() {

}
Money TieredInterestRate::generateInterest(Money &rcMoney) {
	//return (rcMoney * mInterestAmount);
}
void TieredInterestRate::write(std::ostream &rcOut) {
	rcOut << "T";
	for (int i = 0; i < mNumTiers; i++)
	{
		mvcInterest[i].writeBalance(rcOut);
	}
	for (int i = 0; i < mNumTiers; i++)
	{
		mvcInterest[i].writeInterest(rcOut);
	}
	//rcOut << mInterestAmount;
}
void TieredInterestRate::read(std::istream &rcIn) {
	//rcIn >> mvcInterest
}
int TieredInterestRate::findTier(Money &rcMoney) {
	int index = 0;
	bool bIsFound = false;
	while (!bIsFound)
	{
		if (mvcInterest[index].checkBalance(rcMoney)) {
			bIsFound = true;
		}
		else {
			index++;
		}
	}
	return index++;
}

void TieredInterestRate::addTier(TieredType tier) {
	mvcInterest.push_back(tier);
	mNumTiers++;
	std::sort(mvcInterest.begin, mvcInterest.end, std::greater<int>()); // I think this will do sorting
}