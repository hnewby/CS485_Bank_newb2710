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

std::istream& operator >> (std::istream &rcIn, ICommand &rcCmd) {
	rcCmd.read(rcIn);
	return (rcIn);
}