#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : IAccount (){
	//mcFee = new IFee();
}
SavingsAccount::SavingsAccount(int acctNum, long long amt, float interestRate, IFee &rcTheFee) : IAccount(acctNum, amt, interestRate, rcTheFee) {

}
SavingsAccount::~SavingsAccount() {

}