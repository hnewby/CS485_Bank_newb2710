#include "TieredInterestRate.h"

TieredInterestRate::TieredInterestRate() {
	mvcInterest.clear();
	mNumTiers = 0;
	//mInterestAmount = 0;
}
TieredInterestRate::~TieredInterestRate() {

}
Money TieredInterestRate::generateInterest(Money &rcMoney) {
	int tier = findTier(rcMoney);
	Money interest;
	interest = mvcInterest[tier].generateInterest(rcMoney);
	return interest;
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
	TieredType newTier;
	int numTiers = 0;
	rcIn >> numTiers;
	for (int i = 0; i < numTiers; i++)
	{
		addTier(newTier);
		mvcInterest[i].readBal(rcIn);
	}
	for (int i = 0; i < numTiers; i++)
	{
		mvcInterest[i].readInterest(rcIn);
	}
	sortTiers();
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
}

void TieredInterestRate::sortTiers() {
	std::sort(mvcInterest.begin(), mvcInterest.end(), [](TieredType &rcT1, TieredType &rcT2) -> bool { //If breaks look at & 
		return rcT1 > rcT2;
	});
}
