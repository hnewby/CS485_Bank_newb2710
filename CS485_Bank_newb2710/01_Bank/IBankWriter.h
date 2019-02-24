//***************************************************************************
// File name:  IBankWriter.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IBankWriter class header
//***************************************************************************
#pragma once
#include <iostream>
#include "Account.h"
class IBankWriter {
	public:
		virtual bool open(std::ostream) = 0;
		virtual bool writeAcctOut(Account &rcTheAccount) = 0;
		virtual bool close() = 0;
	private:

};