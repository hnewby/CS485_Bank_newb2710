//***************************************************************************
// File name:  CurrencyMismatchException.cpp
// Author:     Hannah Newby
// Date:       3/22/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CurrencyMismatchException class implamentation
//***************************************************************************
#include "CurrencyMismatchException.h"
#include <string>

//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Initalize Currency Exception
//
// Parameters:  mes - string with message to print when exception happens
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException(std::string mes) {
	std::string errMessage = "CurrencyMismatchException: " + mes;

	mpszMessage = new char[errMessage.size() + 1];

	strncpy_s(mpszMessage, errMessage.size() + 1, errMessage.c_str(),
		errMessage.size() + 1);

}
//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Initalize Currency Exception
//
// Parameters:  rcOther - other exception to copy
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException
(const CurrencyMismatchException & rcOther) {
	int size;
	if (nullptr != rcOther.mpszMessage)
	{
		size = static_cast<int>(strlen(rcOther.mpszMessage) + 1);
		mpszMessage = new char[size];

		strncpy_s(mpszMessage, size, rcOther.mpszMessage, size);
	}

}
//***************************************************************************
// Destructor:  CurrencyMismatchException
//
// Description: Deconstructor for CurrencyMismatchException
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
CurrencyMismatchException::~CurrencyMismatchException() {
	if (nullptr != mpszMessage)
	{
		delete mpszMessage;
		mpszMessage = nullptr;
	}

}
//***************************************************************************
// Function:		operator =
//
// Description: sets currency exception to current exception
//
// Parameters:  rcOther - exception to set equal to
//
// Returned:    CurrencyMismatchException&
//***************************************************************************
CurrencyMismatchException& CurrencyMismatchException::operator=
(CurrencyMismatchException cOther) {
	using std::swap;

	std::swap(this->mpszMessage, cOther.mpszMessage);

	return *this;

}
//***************************************************************************
// Function:		what
//
// Description: returns message to display for exception
//
// Parameters:  none
//
// Returned:    const char *
//***************************************************************************
const char* CurrencyMismatchException::what() const {
	return mpszMessage;
}