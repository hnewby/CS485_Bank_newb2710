//***************************************************************************
// File name:  IBankWriter.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IBankWriter class header
//***************************************************************************
#ifndef IBankWriter_h
#define IBankWriter_h
#include <iostream>
#include "IAccount.h"

class IBankWriter {
	public:
		virtual void displayLines(std::ostream &rcOut) = 0;
		virtual void write(std::ostream &rcOut, IAccount &rcTheAccount) = 0;
		//virtual std::ofstream getStream() = 0;
	private:
		
};
#endif