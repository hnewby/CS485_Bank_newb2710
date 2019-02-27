#include "DepositCmd.h"

DepositCmd::DepositCmd(int acctNum, long long amount) {
	mAcctNum = acctNum;
	mAmt = amount;
}
DepositCmd::~DepositCmd() {

}
void DepositCmd::action(Bank &rcTheBank) {
	rcTheBank.deposit(mAcctNum, mAmt);
}