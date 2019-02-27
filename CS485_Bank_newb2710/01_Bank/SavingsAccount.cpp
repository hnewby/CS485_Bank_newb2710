#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : IAccount (){
	//IFee* pcFee = new MonthlyFee();
	//SavingsAccount(0, 0, 0, pcFee);
	// might need to delt
}
SavingsAccount::SavingsAccount(int acctNum, long long amt, float interestRate, IFee* pcTheFee) : IAccount(acctNum, amt, interestRate, pcTheFee) {
	
}
SavingsAccount::~SavingsAccount() {

}