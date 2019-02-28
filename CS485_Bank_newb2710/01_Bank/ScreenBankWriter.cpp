#include "ScreenBankWriter.h"


//***************************************************************************
// Function:		displayLines
//
// Description: display lines out
//
// Parameters:  rcOut - reference to ostream
//
// Returned:    None
//***************************************************************************
void ScreenBankWriter::displayLines(std::ostream &rcOut) {
	rcOut << "-------------\n";
}
//***************************************************************************
// Function:		write
//
// Description: read into ostream from account
//
// Parameters:  rcOut				 - reference to ostream
//							rcTheAccount - refernce to account to read into
//
// Returned:    istream
//***************************************************************************
void ScreenBankWriter::write(std::ostream &rcOut, IAccount &rcTheAccount) {
	rcOut << rcTheAccount;
}