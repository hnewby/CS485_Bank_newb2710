#include "ScreenBankWriter.h"
//void ScreenBankWriter::openToWrite()


bool ScreenBankWriter::write(std::ostream &rcOut, IAccount &rcTheAccount) {
	//rcTheAccount.print(rcOut);
	rcOut << rcTheAccount;
	//rcOut << rcTheAccount.getAcctNum << rcTheAccount. rcTheAccount.getAcctBal(); // figure this out
	return false;
}
bool ScreenBankWriter::close() {
	return false;
}