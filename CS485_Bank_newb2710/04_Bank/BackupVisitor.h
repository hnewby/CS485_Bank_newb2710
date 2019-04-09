//***************************************************************************
// File name:  BackupVisitor.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BackupVisitor class header
//***************************************************************************
#pragma once
#ifndef BackupVisitor_h
#define BackupVisitor_h
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "IAccountVisitor.h"
class BackupVisitor : public IAccountVisitor {
public:
	BackupVisitor(std::string checkingFile, std::string savingFile);
	~BackupVisitor();
	void visit(CheckingAccount &rcCheckingAct);
	void visit(SavingsAccount &rcSavingsAct);


private:
	std::ofstream mChecking;
	std::ofstream mSavings;
};
#endif
