//***************************************************************************
// File name:  ICommand.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ICommand class implamentation
//***************************************************************************
#include "ICommand.h"
//***************************************************************************
// Constructor: ICommand
//
// Description: Initialize ICommand
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ICommand::ICommand() {

}
//***************************************************************************
// Destructor:  ICommand
//
// Description: Deconstructor for ICommand
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
ICommand::~ICommand() {

}
//***************************************************************************
// Function:		operator >>
//
// Description: read in from stream to command
//
// Parameters:  rcIn	- reference to istream
//							rcCmd	- reference to command to read into
//
// Returned:    istream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, ICommand &rcCmd) {
	rcCmd.read(rcIn);
	return (rcIn);
}