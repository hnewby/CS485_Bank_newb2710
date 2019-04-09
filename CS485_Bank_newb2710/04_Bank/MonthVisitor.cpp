//***************************************************************************
// File name:  MonthVisitor.cpp
// Author:     Hannah Newby
// Date:       4/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthVisitor class implamentation
//***************************************************************************
#include "MonthVisitor.h"

//***************************************************************************
// Constructor: MonthVisitor
//
// Description: Initialize backup visitor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
MonthVisitor::MonthVisitor(){
}
//***************************************************************************
// Destructor:  MonthVisitor
//
// Description: Deconstructor for MonthVisitor
//
// Parameters:  None
//
// Returned:    None
//**************************************************************************
MonthVisitor::~MonthVisitor(){
}
//***************************************************************************
// Function:		visit
//
// Description: end of month
//
// Parameters:  rcCheckingAct - reference to checking account
//
// Returned:    None
//***************************************************************************
void MonthVisitor::visit(CheckingAccount & rcCheckingAct){
	rcCheckingAct.endOfMonth();
}
//***************************************************************************
// Function:		visit
//
// Description: end of month
//
// Parameters:  rcSavingsAct - reference to savings account
//
// Returned:    None
//***************************************************************************
void MonthVisitor::visit(SavingsAccount & rcSavingsAct){
	rcSavingsAct.endOfMonth();
}
