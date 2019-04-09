//***************************************************************************
// File name:  BackupCmd.cpp
// Author:     Hannah Newby
// Date:       4/8/19
// Class:      CS485
// Assignment: BackupCmd
// Purpose:    BackupCmd class implamentation
//***************************************************************************
#include "BackupCmd.h"

//***************************************************************************
// Constructor: BackupCmd
//
// Description: Initalize BackupCmd
//
// Parameters:  checkingFile - string for file to send checking accounts
//							savingFile	 - string for file to send saving accounts
//
// Returned:    None
//***************************************************************************
BackupCmd::BackupCmd(std::string checkingFile, std::string savingFile) {
	mCheckingFile = checkingFile;
	mSavingsFile = savingFile;
}
//***************************************************************************
// Destructor:	BackupCmd
//
// Description: Destruct BackupCmd
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BackupCmd::~BackupCmd() {

}
//***************************************************************************
// Function:		read
//
// Description: read in (nothing)
//
// Parameters:  rcIn - reference to istream
//
// Returned:    None
//***************************************************************************
void BackupCmd::read(std::istream &rcIn) {

}
//***************************************************************************
// Function:		action
//
// Description: perform execute on bank
//
// Parameters:  rcTheBank - refernce to the bank
//
// Returned:    None
//***************************************************************************
void BackupCmd::action(Bank &rcTheBank) {
	rcTheBank.backup(mCheckingFile, mSavingsFile);
}