//***************************************************************************
// File name:  PrintCmd.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    PrintCmd class header
//***************************************************************************
#pragma once
#include "ICommand.h"

class PrintCmd : public ICommand {
	public:
		PrintCmd();
		~PrintCmd();
		void read(std::istream &rcIn); //not using for this assignment
		void action(Bank &rcTheBank);
	private:

};