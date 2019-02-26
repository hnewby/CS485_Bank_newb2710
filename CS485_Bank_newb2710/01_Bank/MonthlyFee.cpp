#include "MonthlyFee.h"

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