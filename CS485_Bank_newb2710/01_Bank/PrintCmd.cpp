#include "PrintCmd.h"
#include "ScreenBankWriter.h"
PrintCmd::PrintCmd(){

}
PrintCmd::~PrintCmd() {

}
void PrintCmd::action(Bank &rcTheBank) {
	IBankWriter* pcWriter = new ScreenBankWriter;
	rcTheBank.writeBank(*pcWriter);
}