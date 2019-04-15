//***************************************************************************
// File name:  CurrencyConversion.cpp
// Author:     Hannah Newby
// Date:       4/15/19
// Class:      CS485
// Assignment: Bank
// Purpose:    CurrencyConversion class implamentation
//***************************************************************************
#include "CurrencyConversion.h"

//***************************************************************************
// Constructor: CurrencyConversion
//
// Description: Initialize CurrencyConversion
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CurrencyConversion::CurrencyConversion() {

}
//***************************************************************************
// Destructor:  CurrencyConversion
//
// Description: Deconstructor for CurrencyConversion
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CurrencyConversion::~CurrencyConversion(){
}
//***************************************************************************
// Function:		getInstance
//
// Description: return currency conversion singleton
//
// Parameters:  None
//
// Returned:    CurrencyConversion&
//***************************************************************************
CurrencyConversion& CurrencyConversion::getInstance(){
	static CurrencyConversion instance;
	return instance;
}
//***************************************************************************
// Function:		convert
//
// Description: get conversion rate between two currencies
//
// Parameters:  cCur1 - currency 1
//							cCur2 - currency 2
//
// Returned:    double
//***************************************************************************
double CurrencyConversion::convert(Currency cCur1, Currency cCur2){
	if (mCurrencyConversion.find({ std::make_pair(cCur1, cCur2) })
		== mCurrencyConversion.end()) {
		return -1;
	}
	else {
		return mCurrencyConversion.at({ std::make_pair(cCur1, cCur2) });
	}
}
//***************************************************************************
// Function:		insert
//
// Description: insert a conversion into HT
//
// Parameters:  cCur1		 - first currency in conversion
//							cCur2		 - second currency in conversion
//							exchange - exchnage rate
//
// Returned:    none
//***************************************************************************
void CurrencyConversion::insert(Currency cCur1, Currency cCur2, double exchange){
	mCurrencyConversion.insert({ std::make_pair(cCur1, cCur2), exchange });
}
