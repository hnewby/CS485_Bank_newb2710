//***************************************************************************
// File name:  MonthCmd.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthCmd class implamentation
//***************************************************************************
#include "MonthCmd.h"

//***************************************************************************
// Constructor: MonthCmd
//
// Description: Initialize MonthCmd
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
MonthCmd::MonthCmd() {

}
//***************************************************************************
// Destructor:  MonthCmd
//
// Description: Deconstructor for MonthCmd
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
MonthCmd::~MonthCmd() {

}
//***************************************************************************
// Function:		read
//
// Description: read in to MonthCmd
//
// Parameters:  rcIn - istream to read in from
//
// Returned:    None
//***************************************************************************
void MonthCmd::read(std::istream &rcIn) {
	//not using this assignment
}
//***************************************************************************
// Function:		action
//
// Description: perform end of month routine
//
// Parameters:  rcTheBank - reference to bank
//
// Returned:    None
//***************************************************************************
void MonthCmd::action(Bank &rcTheBank) {
	rcTheBank.endOfMonthForAll();
}