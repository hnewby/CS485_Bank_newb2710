#include "CurrencyMismatchException.h"
#include <string>

CurrencyMismatchException::CurrencyMismatchException(int value) :mValue(value) {
	std::string errMessage = "CurrencyMismatchException: " + std::to_string(value);

	mpszMessage = new char[errMessage.size() + 1];

	strncpy_s(mpszMessage, errMessage.size() + 1, errMessage.c_str(),
		errMessage.size() + 1);

}

CurrencyMismatchException::CurrencyMismatchException(const CurrencyMismatchException & rcOther) {
	int size;
	mValue = rcOther.mValue;
	if (nullptr != rcOther.mpszMessage)
	{
		size = strlen(rcOther.mpszMessage) + 1;
		mpszMessage = new char[size];

		strncpy_s(mpszMessage, size, rcOther.mpszMessage, size);
	}

}
CurrencyMismatchException::~CurrencyMismatchException() {
	if (nullptr != mpszMessage)
	{
		delete mpszMessage;
		mpszMessage = nullptr;
	}

}

CurrencyMismatchException& CurrencyMismatchException::operator= (CurrencyMismatchException cOther) {
	using std::swap;
	mValue = cOther.mValue;

	std::swap(this->mpszMessage, cOther.mpszMessage);

	return *this;

}

const char* CurrencyMismatchException::what() const {
	return mpszMessage;
}