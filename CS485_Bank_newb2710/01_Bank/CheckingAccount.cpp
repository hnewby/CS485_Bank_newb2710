#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {

}
CheckingAccount::CheckingAccount(int acctNum, long long amt, float interestRate, IFee theFee) : IAccount(actNum, amt, interestRate, theFee) {
	
}
CheckingAccount::~CheckingAccount() {

}