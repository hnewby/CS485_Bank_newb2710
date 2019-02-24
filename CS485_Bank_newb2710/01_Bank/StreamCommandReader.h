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
#include "ICommandReader.h"

class StreamCommandReader : public ICommandReader{
	public:
		bool open(std::string);
		bool read(ICommand &rcCmd);
		bool close();
	private:
		std::istream mcInFile;
};