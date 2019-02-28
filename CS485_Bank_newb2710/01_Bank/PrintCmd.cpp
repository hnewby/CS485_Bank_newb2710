#include "PrintCmd.h"
#include "ScreenBankWriter.h"
PrintCmd::PrintCmd(){

}
PrintCmd::~PrintCmd() {

}
void PrintCmd::read(std::istream &rcIn) {
	//not using this assignment
}
void PrintCmd::action(Bank &rcTheBank) {
	IBankWriter* pcWriter = new ScreenBankWriter;
	rcTheBank.writeBank(*pcWriter);
}