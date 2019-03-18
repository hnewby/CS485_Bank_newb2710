#pragma once
//***************************************************************************
// File name:  CurrencyMismatchException.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CurrencyMismatchException class header
//***************************************************************************
#ifndef CurrencyMismatchException_h
#define CurrencyMismatchException_h
#include <exception>

class CurrencyMismatchException : public std::exception{
public:
	CurrencyMismatchException(int value = 0);
	CurrencyMismatchException(const CurrencyMismatchException & rcOther);
	~CurrencyMismatchException();

	CurrencyMismatchException& operator= (CurrencyMismatchException cOther);

	virtual const char* what() const override;

private:
	int mValue;
	char *mpszMessage = nullptr;
};
#endif