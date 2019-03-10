//***************************************************************************
// File name:  IFee.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IFee class implamentation
//***************************************************************************
#include "IFee.h"

//***************************************************************************
// Constructor: IFee
//
// Description: Initialize IFee
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
IFee::IFee() : IFee(0) {

}
//***************************************************************************
// Constructor: IFee
//
// Description: Initialize IFee
//
// Parameters:  amount - Amount of fee
//
// Returned:    None
//***************************************************************************
IFee::IFee(long long amount){
	mAmount = amount;
}
//***************************************************************************
// Destructor:  IFee
//
// Description: Deconstructor for IFee
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
IFee::~IFee(){
	
}
//***************************************************************************
// Function:		getAmount
//
// Description: return amount of fee
//
// Parameters:  None
//
// Returned:    long long
//***************************************************************************
long long IFee::getAmount(){
	return mAmount;
}
//***************************************************************************
// Function:		read
//
// Description: read in from stream to amount
//
// Parameters:  rcIn				 - reference to istream
//
// Returned:    None
//***************************************************************************
void IFee::read(std::istream& rcIn) {
	rcIn >> mAmount;
}
//***************************************************************************
// Function:		operator >>
//
// Description: read in from stream to fee
//
// Parameters:  rcIn	- reference to istream
//							rcFee - reference of fee to read into
//
// Returned:    istream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, IFee &rcFee) {
	rcFee.read(rcIn);
	return rcIn;
}
//***************************************************************************
// Function:		operator <<
//
// Description: read into stream from fee
//
// Parameters:  rcOut - reference to ostream
//							pcFee - pointer to Fee
//
// Returned:    istream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, IFee* pcFee) {
	pcFee->write(rcOut);
	return rcOut;
}
//***************************************************************************
// Function:		write
//
// Description: read amount to ostream
//
// Parameters:  rcOut - refernce to ostream
//
// Returned:    None
//***************************************************************************
void IFee::write(std::ostream &rcOut) {
	rcOut << mAmount;
}