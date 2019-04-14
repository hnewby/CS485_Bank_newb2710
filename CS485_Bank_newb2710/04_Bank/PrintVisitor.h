//***************************************************************************
// File name:  PrintVisitor.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    PrintVisitor class header
//***************************************************************************
#pragma once
#ifndef PrintVisitor_h
#define PrintVisitor_h
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "IAccountVisitor.h"
class PrintVisitor : public IAccountVisitor {
public:
	PrintVisitor();
	~PrintVisitor();
	void visit(CheckingAccount &rcCheckingAct);
	void visit(SavingsAccount &rcSavingsAct);


private:
	std::ofstream mDisplay;
};
#endif
