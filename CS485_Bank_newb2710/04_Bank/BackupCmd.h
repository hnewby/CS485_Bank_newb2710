//***************************************************************************
// File name:  BackupCmd.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    BackupCmd class header
//***************************************************************************
#pragma once

#include "ICommand.h"
class BackupCmd : public ICommand {
public:
	BackupCmd(std::string checkingFile, std::string savingFile);
	~BackupCmd();
	void read(std::istream &rcIn);
	void action(Bank &rcTheBank);
private:
	std::string mCheckingFile;
	std::string mSavingsFile;
};
};