#include "MonthCmd.h"

MonthCmd::MonthCmd() {

}
MonthCmd::~MonthCmd() {

}
void MonthCmd::action(Bank &rcTheBank) {
	rcTheBank.endOfMonthForAll();
	//do things
}