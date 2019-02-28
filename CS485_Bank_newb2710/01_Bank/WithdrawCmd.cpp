#include "WithdrawCmd.h"

WithdrawCmd::WithdrawCmd() : WithdrawCmd(0, 0) {
}
WithdrawCmd::WithdrawCmd(int acctNum, long long amount){
	mAcctNum = acctNum;
	mAmt = amount;
}
WithdrawCmd::~WithdrawCmd() {

}
void WithdrawCmd::action(Bank &rcTheBank) {
	rcTheBank.withdraw(mAcctNum, mAmt);
}