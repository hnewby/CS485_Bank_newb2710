#include "ICommand.h"

ICommand::ICommand() {

}
ICommand::~ICommand() {

}

std::istream& operator >> (std::istream &rcIn, ICommand &rcCmd) {
	return (rcIn);
}