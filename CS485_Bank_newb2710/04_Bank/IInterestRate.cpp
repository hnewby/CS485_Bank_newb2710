//***************************************************************************
// File name:  IInterestRate.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: IInterestRate
// Purpose:    IInterestRate class implamentation
//***************************************************************************
#include "IInterestRate.h"

//***************************************************************************
// Constructor: IInterestRate
//
// Description: Initialize IInterestRate
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
IInterestRate::IInterestRate() {

}
//***************************************************************************
// Destructor:  IInterestRate
//
// Description: Deconstructor for IInterestRate
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
IInterestRate::~IInterestRate() {

}
//***************************************************************************
// Function:		operator  >>
//
// Description: read in to IInterestRate
//
// Parameters:  rcIn - reference to istream
//							rcRate - reference to interest rate to read into
//
// Returned:    istream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, IInterestRate &rcRate) {
	rcRate.read(rcIn);
	return rcIn;
}
//***************************************************************************
// Function:		operator  <<
//
// Description: IInterestRate into ostream
//
// Parameters:  rcOut - reference to ostream
//							pcRate - pointer to interest rate to read out
//
// Returned:    ostream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, IInterestRate *pcRate) {
	pcRate->write(rcOut);
	return rcOut;
}