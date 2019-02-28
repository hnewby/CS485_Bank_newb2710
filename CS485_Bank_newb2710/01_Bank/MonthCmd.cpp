#include "MonthCmd.h"

MonthCmd::MonthCmd() {

}
MonthCmd::~MonthCmd() {

}
void MonthCmd::read(std::istream &rcIn) {
	//not using this assignment
}
void MonthCmd::action(Bank &rcTheBank) {
	rcTheBank.endOfMonthForAll();
	//do things
}