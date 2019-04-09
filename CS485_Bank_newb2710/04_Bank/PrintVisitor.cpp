//***************************************************************************
// File name:  PrintVisitor.cpp
// Author:     Hannah Newby
// Date:       4/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    PrintVisitor class implamentation
//***************************************************************************
#include "PrintVisitor.h"

//***************************************************************************
// Constructor: PrintVisitor
//
// Description: Initialize backup visitor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
PrintVisitor::PrintVisitor(std::string printFile) {
	mDisplay.open(printFile);
	if (mDisplay.fail()) {
		std::cout << "file failed to open\n";
	}
}
//***************************************************************************
// Destructor:  PrintVisitor
//
// Description: Deconstructor for PrintVisitor
//
// Parameters:  None
//
// Returned:    None
//**************************************************************************
PrintVisitor::~PrintVisitor() {
	mDisplay.close();
}
//***************************************************************************
// Function:		visit
//
// Description: print account
//
// Parameters:  rcCheckingAct - reference to checking account
//
// Returned:    None
//***************************************************************************
void PrintVisitor::visit(CheckingAccount & rcCheckingAct) {
	mDisplay << rcCheckingAct;
}
//***************************************************************************
// Function:		visit
//
// Description: print account
//
// Parameters:  rcSavingsAct - reference to savings account
//
// Returned:    None
//***************************************************************************
void PrintVisitor::visit(SavingsAccount & rcSavingsAct) {
	mDisplay << rcSavingsAct;
}
