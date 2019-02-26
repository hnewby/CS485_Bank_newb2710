#include "ScreenBankWriter.h"


bool ScreenBankWriter::write(std::ostream &rcOut, IAccount &rcTheAccount) {
	rcOut << rcTheAccount.getAcctBal(); // figure this out
}
bool ScreenBankWriter::closeBankDB() {

}