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
long long IFee::getAmount(){
	return mAmount;
}
void IFee::read(std::istream& rcIn) {
	rcIn >> mAmount;
}
std::istream& operator >> (std::istream &rcIn, IFee &rcFee) {
	rcFee.read(rcIn);
	return rcIn;
}

std::ostream& operator << (std::ostream &rcOut, IFee* pcFee) {
	pcFee->write(rcOut);
	return rcOut;
}

void IFee::write(std::ostream &rcOut) {
	rcOut << mAmount;
}