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
#include "Account.h"
class IAccountReader {
	public:
		virtual bool open(std::string file) = 0;
		virtual bool read(Account &rcTheAccount) = 0;
		virtual bool close() = 0;
	private:

};