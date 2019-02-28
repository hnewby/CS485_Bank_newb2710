//***************************************************************************
// File name:  ICommandReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ICommandReader class header
//***************************************************************************
#ifndef ICommandReader_h
#define ICommandReader_h
#include <string>
#include "ICommand.h"
//class ICommand;
class ICommandReader {
	public:
		//ICommandReader() {};
		virtual bool openCommands(std::string file) = 0;
		virtual ICommand* read() = 0;
		virtual void closeCommands() = 0;
	private:

};
#endif