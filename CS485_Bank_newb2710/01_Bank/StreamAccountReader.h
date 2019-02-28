//***************************************************************************
// File name:  StreamAccountReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamAccountReader class header
//***************************************************************************
#pragma once
#include "IAccountReader.h"
#include <fstream>
class StreamAccountReader : public IAccountReader{
	public:
		bool openAccountsDB(std::string file);
		bool read(Bank &rcTheBank);
		bool closeAccountsDB();
	private:
		std::ifstream mcInFile;
};