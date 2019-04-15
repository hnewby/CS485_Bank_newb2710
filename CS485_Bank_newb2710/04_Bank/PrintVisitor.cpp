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
PrintVisitor::PrintVisitor() {
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
	std::cout << rcCheckingAct << std::endl;
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
	std::cout << rcSavingsAct << std::endl;
}
