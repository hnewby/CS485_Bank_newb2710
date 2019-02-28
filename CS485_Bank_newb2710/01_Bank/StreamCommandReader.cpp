#include "StreamCommandReader.h"
#include "WithdrawCmd.h"
#include "DepositCmd.h"
#include "PrintCmd.h"
#include "MonthCmd.h"

//***************************************************************************
// Function:		openCommands
//
// Description: open file to read commands
//
// Parameters:  file - file name to read
//
// Returned:		bool
//***************************************************************************
bool StreamCommandReader::openCommands(std::string file) {
	bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;
	return false;
}

//why is this a bool?
ICommand* StreamCommandReader::read() {
	char commandType;
	ICommand *pcCmd = nullptr;

	if (mcInFile >> commandType)
	{
		switch (commandType) {
		case 'W':
			pcCmd = new WithdrawCmd();
			break;
		case 'D':
			pcCmd = new DepositCmd();
			break;
		case 'P':
			pcCmd = new PrintCmd();
			break;
		case 'M':
			pcCmd = new MonthCmd();
			break;
		}
		mcInFile >> *pcCmd;
	}
	return pcCmd;
}
bool StreamCommandReader::closeCommands() {
	mcInFile.close();
	return false;
}