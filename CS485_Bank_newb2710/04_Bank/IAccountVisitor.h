//***************************************************************************
// File name:  IAccountVisitor.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IAccountVisitor class header
//***************************************************************************
#pragma once
#ifndef IAccountVisitor_h
#define IAccountVisitor_h
#include "CheckingAccount.h"
#include "SavingsAccount.h"

class IAccountVisitor {
public:
	IAccountVisitor();
	~IAccountVisitor();
	virtual void visit(CheckingAccount &rcCheckingAct) = 0;
	virtual void visit(SavingsAccount &rcSavingsAct) = 0;


private:

};
#endif
