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
#include <string>
class CurrencyMismatchException : public std::exception{
public:
	CurrencyMismatchException(std::string mes);
	CurrencyMismatchException(const CurrencyMismatchException & rcOther);
	~CurrencyMismatchException();

	CurrencyMismatchException& operator= (CurrencyMismatchException cOther);

	virtual const char* what() const override;

private:
	char *mpszMessage = nullptr;
};
#endif