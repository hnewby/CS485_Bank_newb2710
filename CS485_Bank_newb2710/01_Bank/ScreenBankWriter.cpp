#include "ScreenBankWriter.h"
//void ScreenBankWriter::openToWrite(std::ostream &rcOut)
//{
//}

void ScreenBankWriter::displayLines(std::ostream &rcOut) {
	rcOut << "-------------\n";
}
bool ScreenBankWriter::write(std::ostream &rcOut, IAccount &rcTheAccount) {
	//rcTheAccount.print(rcOut);
	rcOut << rcTheAccount;
	//rcOut << rcTheAccount.getAcctNum << rcTheAccount. rcTheAccount.getAcctBal(); // figure this out
	return false;
}
bool ScreenBankWriter::close() {
	return false;
}