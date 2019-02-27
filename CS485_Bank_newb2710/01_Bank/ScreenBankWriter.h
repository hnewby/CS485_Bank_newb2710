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
	//	virtual bool openBankDB(std::ostream &rcOut);
		bool write(std::ostream &rcOut, IAccount &rcTheAccount);
		bool closeBankDB();
	private:

};