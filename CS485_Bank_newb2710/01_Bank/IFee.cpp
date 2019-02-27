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
//std::istream& operator >> (std::istream &rcIn, IFee &rcFee) {
//	rcIn >> rcFee.mAmount >> 
//}