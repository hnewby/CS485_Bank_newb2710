//***************************************************************************
// File name:  StreamAccountReader.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamAccountReader class header
//***************************************************************************
#pragma once
#include "IAccountReader.h"
class StreamAccountReader : public IAccountReader{
	public:
		virtual bool open(std::string file);
		virtual bool read(Account &rcTheAccount);
		virtual bool close();
	private:

};