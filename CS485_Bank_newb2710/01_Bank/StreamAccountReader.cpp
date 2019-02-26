#include "StreamAccountReader.h"

bool StreamAccountReader::openAccountsDB(std::string file) {
	bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;
}
bool StreamAccountReader::read(IAccount &rcCmd) {

}
bool StreamAccountReader::closeAccountsDB() {
	mcInFile.close();
}