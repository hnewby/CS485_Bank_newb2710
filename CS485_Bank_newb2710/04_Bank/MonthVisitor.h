//***************************************************************************
// File name:  MonthVisitor.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthVisitor class header
//***************************************************************************
#pragma once
#ifndef MonthVisitor_h
#define MonthVisitor_h
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "IAccountVisitor.h"
class MonthVisitor : public IAccountVisitor {
public:
	MonthVisitor();
	~MonthVisitor();
	void visit(CheckingAccount &rcCheckingAct);
	void visit(SavingsAccount &rcSavingsAct);


private:
};
#endif
