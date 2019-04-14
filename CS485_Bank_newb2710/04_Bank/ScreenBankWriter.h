//***************************************************************************
// File name:  ScreenBankWriter.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    ScreenBankWriter class header
//***************************************************************************
#pragma once

#include "IBankWriter.h"

class ScreenBankWriter : public IBankWriter {
	public:
		void displayLines(std::ostream &rcOut);
		void write(std::ostream &rcOut, IAccount &rcTheAccount);
		//std::ofstream getStream();
	private:
};