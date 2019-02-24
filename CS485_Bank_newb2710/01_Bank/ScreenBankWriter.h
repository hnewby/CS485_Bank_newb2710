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

class ScreenBankWriter : IBankWriter {
	public:
		virtual bool open(std::ostream);
		virtual bool writeAcctOut(Account &rcTheAccount);
		virtual bool close();
	private:

};