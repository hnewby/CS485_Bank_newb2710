#include "PrintCmd.h"
#include "ScreenBankWriter.h"

//***************************************************************************
// Constructor: PrintCmd
//
// Description: Initialize PrintCmd
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
PrintCmd::PrintCmd(){

}
//***************************************************************************
// Destructor:  PrintCmd
//
// Description: Deconstructor for PrintCmd
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
PrintCmd::~PrintCmd() {

}
//***************************************************************************
// Function:		read
//
// Description: read in to PrintCmd
//
// Parameters:  rcIn - istream to read in from
//
// Returned:    None
//***************************************************************************
void PrintCmd::read(std::istream &rcIn) {
	//not using this assignment
}
//***************************************************************************
// Function:		action
//
// Description: print account
//
// Parameters:  rcTheBank - reference to bank
//
// Returned:    None
//***************************************************************************
void PrintCmd::action(Bank &rcTheBank) {
	IBankWriter* pcWriter = new ScreenBankWriter;
	rcTheBank.writeBank(*pcWriter);
}