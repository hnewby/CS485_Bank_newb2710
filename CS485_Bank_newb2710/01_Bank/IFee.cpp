#include "IFee.h"

IFee::IFee() {

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