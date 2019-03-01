//***************************************************************************
// File name:  StreamCommandReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamCommandReader class header
//***************************************************************************
#pragma once
#include "ICommandReader.h"
#include <fstream>

class StreamCommandReader : public ICommandReader{
	public:
		bool openCommands(std::string file);
		ICommand* read();
		void closeCommands();
	private:
		std::ifstream mcInFile;
};