#include "ICommand.h"

ICommand::ICommand() {

}
ICommand::~ICommand() {

}

std::istream& operator >> (std::istream &rcIn, ICommand &rcCmd) {
	rcCmd.read(rcIn);
	return (rcIn);
}