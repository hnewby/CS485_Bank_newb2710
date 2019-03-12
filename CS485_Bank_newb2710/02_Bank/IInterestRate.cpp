#include "IInterestRate.h"

IInterestRate::IInterestRate() {

}
IInterestRate::~IInterestRate() {

}
std::istream& operator >> (std::istream &rcIn, IInterestRate &rcRate) {
	rcRate.read(rcIn);
	return rcIn;
}
std::ostream& operator << (std::ostream &rcOut, IInterestRate *pcRate) {
	pcRate->write(rcOut);
	return rcOut;
}