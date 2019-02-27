#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {
	//mcFee = new IFee();
}
SavingsAccount::SavingsAccount(int acctNum, long long amt, float interestRate, IFee theFee) : IAccount(acctNum, amt, interestRate, theFee) {

}
SavingsAccount::~SavingsAccount() {

}