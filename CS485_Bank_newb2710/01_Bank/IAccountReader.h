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
#include "Bank.h"
class IAccountReader {
	public:
		virtual bool openAccountsDB(std::string file) = 0;
		virtual void read(Bank &rcTheBank) = 0;
		virtual void closeAccountsDB() = 0;
	private:

};