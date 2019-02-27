#include "StreamCommandReader.h"


// SOMEWHERE IN HERE NEED TO MAKE COMMAND OBJECT I THINK


bool StreamCommandReader::openCommands(std::string file) {
	/*bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;*/
	return false;
}
bool StreamCommandReader::read(ICommand &rcCmd) {
	return false;
}
bool StreamCommandReader::closeCommands() {
	//mcInFile.close();
	return false;
}