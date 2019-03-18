//***************************************************************************
// File name:  StreamCommandReader.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamCommandReader class implamentation
//***************************************************************************
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
//***************************************************************************
// Function:		read
//
// Description: read in from stream and create command
//
// Parameters:  None
//
// Returned:    ICommand*
//***************************************************************************
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
//***************************************************************************
// Function:		closeCommands
//
// Description: close file read from
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void StreamCommandReader::closeCommands() {
	mcInFile.close();
}