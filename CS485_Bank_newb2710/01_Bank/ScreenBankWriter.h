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
	//	virtual bool openBankDB(std::ostream &rcOut);
		virtual bool write(std::ostream, IAccount &rcTheAccount);
		virtual bool closeBankDB();
	private:

};