//***************************************************************************
// File name:  ICommandReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ICommandReader class header
//***************************************************************************
#pragma once
#include <string>
#include "ICommand.h"

class ICommandReader {
	public:
		virtual bool openCommands(std::string file) = 0;
		virtual bool read(ICommand &rcCmd) = 0;
		virtual bool closeCommands() = 0;
	private:

};