//***************************************************************************
// File name:  ICommand.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ICommand class header
//***************************************************************************
#pragma once
#include "Bank.h"
class ICommand {
	public:
		ICommand();
		~ICommand();
		void action(Bank &rcTheBank);
		friend std::istream& operator >> (std::istream &rcIn, ICommand &rcCmd);
	private:

};