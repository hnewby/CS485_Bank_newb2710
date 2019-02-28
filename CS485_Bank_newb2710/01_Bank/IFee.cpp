#include "IFee.h"

IFee::IFee() : IFee(0) {

}
IFee::IFee(long long amount){
	mAmount = amount;
}
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
	rcOut << mAmount << ' ';
}