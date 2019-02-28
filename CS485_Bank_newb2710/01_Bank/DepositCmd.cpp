#include "DepositCmd.h"

DepositCmd::DepositCmd() : DepositCmd(0, 0) {

}
DepositCmd::DepositCmd(int acctNum, long long amount) {
	mAcctNum = acctNum;
	mAmt = amount;
}
DepositCmd::~DepositCmd() {

}
void DepositCmd::read(std::istream &rcIn) {
	rcIn >> mAcctNum >> mAmt;
}
void DepositCmd::action(Bank &rcTheBank) {
	rcTheBank.deposit(mAcctNum, mAmt);
}