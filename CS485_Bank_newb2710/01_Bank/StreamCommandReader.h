//***************************************************************************
// File name:  StreamCommandReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamCommandReader class header
//***************************************************************************
#pragma once
#include <iostream>
#include <fstream>
#include "ICommandReader.h"

class StreamCommandReader : public ICommandReader{
	public:
		bool openCommands(std::string file);
		bool read(ICommand &rcCmd);
		bool closeCommands();
	private:
		std::istream mcInFile;
};