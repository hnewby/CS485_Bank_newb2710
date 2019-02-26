//***************************************************************************
// File name:  IAccountReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IAccountReader class header
//***************************************************************************
#pragma once
#include <string>
#include "IAccount.h"
class IAccountReader {
	public:
		virtual bool openAccountsDB(std::string file) = 0;
		virtual bool read(IAccount &rcTheAccount) = 0;
		virtual bool closeAccountsDB() = 0;
	private:

};