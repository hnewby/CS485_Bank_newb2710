//***************************************************************************
// File name:  MonthCmd.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MonthCmd class header
//***************************************************************************
#pragma once
#include "ICommand.h"

class MonthCmd : public ICommand {
	public:
		MonthCmd();
		~MonthCmd();
		void read(std::istream &rcIn); //not using for this assignment
		void action(Bank &rcTheBank);
	private:

};