#include "MonthlyFee.h"

MonthlyFee::MonthlyFee() : IFee() {
	mMinBal = 0;
	mbWentBelow = false;
}
MonthlyFee::MonthlyFee(long long minBal, bool bWentBelow, long long amount) : IFee (amount){
	mMinBal = minBal;
	mbWentBelow = bWentBelow;
}

MonthlyFee::~MonthlyFee() {

}

long long MonthlyFee::chargeMonthlyFee(const long long balance) {
	long long feeAmount = 0;
	if (mbWentBelow)
	{
		feeAmount = getAmount();
	}
	return feeAmount;
}

long long MonthlyFee::chargeDepositFee(const long long balance) {
	
	if (balance < mMinBal)
	{
		mbWentBelow = true;
	}
	return 0;
}

long long MonthlyFee::chargeWithdrawFee(const long long balance) {
	if (balance < mMinBal)
	{
		mbWentBelow = true;
	}
	return 0;
}

bool MonthlyFee::checkWentBelow() {
	return mbWentBelow;
}

void MonthlyFee::read(std::istream &rcIn){
	IFee::read(rcIn);
	rcIn >> mMinBal;// >> mbWentBelow;
}

void MonthlyFee::write(std::ostream &rcOut) {
	IFee::write(rcOut);
	rcOut << mMinBal;
}