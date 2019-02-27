#include "CheckingAccount.h"


CheckingAccount::CheckingAccount() : IAccount() {
	IFee* pcFee = new TransactionalFee();
	CheckingAccount(0, 0, 0, pcFee);
}
CheckingAccount::CheckingAccount(int acctNum, long long amt, float interestRate, IFee* pcTheFee) : IAccount(acctNum, amt, interestRate, pcTheFee) {
	
}
CheckingAccount::~CheckingAccount() {

}