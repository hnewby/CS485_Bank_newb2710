#include "TransactionalFee.h"

TransactionalFee::TransactionalFee(long long minBalance)
{
	mMinBal = minBalance;
}
TransactionalFee::~TransactionalFee()
{

}
long long TransactionalFee::chargeMonthlyFee(const long long balance)
{
	//do nothing not a monthly fee
}
long long TransactionalFee::chargeDepositFee(const long long balance)
{
	long long fee = 0;
	if (balance <= mMinBal)
	{
		fee = getAmount();
	}
	return fee;
}

long long TransactionalFee::chargeWithdrawFee(const long long balance)
{
	long long fee = 0;
	if (balance <= mMinBal)
	{
		fee = getAmount();
	}
	return fee;
}