#include "TransactionalFee.h"

TransactionalFee::TransactionalFee() : IFee() {

}
TransactionalFee::TransactionalFee(long long minBalance, long long amount) : IFee (amount)
{
	mMinBal = minBalance;
}
TransactionalFee::~TransactionalFee()
{

}
long long TransactionalFee::chargeMonthlyFee(const long long balance)
{
	return 0;
	//do nothing not a monthly fee
}
long long TransactionalFee::chargeDepositFee(const long long balance)
{
	long long fee = 0;
	if (balance < mMinBal)
	{
		fee = getAmount();
	}
	return fee;
}

long long TransactionalFee::chargeWithdrawFee(const long long balance)
{
	long long fee = 0;
	if (balance < mMinBal)
	{
		fee = getAmount();
	}
	return fee;
}

void TransactionalFee::read(std::istream &rcIn) {
	rcIn >> mMinBal; //minBal first because thats the way file is
	IFee::read(rcIn);
}