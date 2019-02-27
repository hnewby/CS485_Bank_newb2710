#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() : IAccount() {

}
CheckingAccount::CheckingAccount(int acctNum, long long amt, float interestRate, IFee &rcTheFee) : IAccount(acctNum, amt, interestRate, rcTheFee) {
	
}
CheckingAccount::~CheckingAccount() {

}