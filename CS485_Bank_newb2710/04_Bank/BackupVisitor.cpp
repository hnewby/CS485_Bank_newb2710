//***************************************************************************
// File name:  BackupVisitor.cpp
// Author:     Hannah Newby
// Date:       4/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BackupVisitor class implamentation
//***************************************************************************
#include "BackupVisitor.h"

//***************************************************************************
// Constructor: BackupVisitor
//
// Description: Initialize backup visitor
//
// Parameters:  checkingFile - string with checking file name
//							savingFile	 - string with saving file name
//
// Returned:    None
//***************************************************************************
BackupVisitor::BackupVisitor(std::string checkingFile, std::string savingFile){
	mChecking.open(checkingFile);
	mSavings.open(savingFile);
	if (mChecking.fail() || mSavings.fail()) {
		std::cout << "File failed to open\n";
	}
}
//***************************************************************************
// Destructor:  BackupVisitor
//
// Description: Deconstructor for BackupVisitor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BackupVisitor::~BackupVisitor(){
	mChecking.close();
	mSavings.close();
}
//***************************************************************************
// Function:		visit
//
// Description: display account
//
// Parameters:  rcCheckingAct - reference to checking account
//
// Returned:    None
//***************************************************************************
void BackupVisitor::visit(CheckingAccount & rcCheckingAct){
	mChecking << rcCheckingAct << std::endl;
}
//***************************************************************************
// Function:		visit
//
// Description: display account
//
// Parameters:  rcSavingsAct - reference to savings account
//
// Returned:    None
//***************************************************************************
void BackupVisitor::visit(SavingsAccount & rcSavingsAct) {
	mSavings << rcSavingsAct << std::endl;
}
