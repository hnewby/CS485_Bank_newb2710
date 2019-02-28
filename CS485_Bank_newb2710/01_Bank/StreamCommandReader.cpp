#include "StreamCommandReader.h"
#include "WithdrawCmd.h"
#include "DepositCmd.h"
#include "PrintCmd.h"
#include "MonthCmd.h"

// SOMEWHERE IN HERE NEED TO MAKE COMMAND OBJECT I THINK

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

			mcInFile >> *pcCmd;

			//rcTheCollection.addAccount(pcAccount);
			//need to add account to bank
		}
	}
	return pcCmd;
}
bool StreamCommandReader::closeCommands() {
	//mcInFile.close();
	return false;
}