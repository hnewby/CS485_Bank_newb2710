//***************************************************************************
// File name:  ICommand.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ICommand class header
//***************************************************************************
//#pragma once
#ifndef ICommand_h
#define ICommand_h
#include <iostream>
#include "Bank.h"

class ICommand {
	public:
		ICommand();
		virtual ~ICommand();
		virtual void action(Bank &rcTheBank) = 0;
		virtual void read(std::istream &rcIn) = 0;;
		friend std::istream& operator >> (std::istream &rcIn,
			ICommand &rcCmd);

	private:

};
#endif