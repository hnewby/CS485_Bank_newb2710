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
		virtual void action(Bank &rcTheBank) = 0;
	private:

};