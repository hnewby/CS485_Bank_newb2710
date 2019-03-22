//***************************************************************************
// File name:  StreamAccountReader.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    StreamAccountReader class implamentation
//***************************************************************************
#include "StreamAccountReader.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

//***************************************************************************
// Function:		openAccountsDB
//
// Description: open file to read from
//
// Parameters:  file - file to open
//
// Returned:    bool
//***************************************************************************
bool StreamAccountReader::openAccountsDB(std::string file) {
	bool bOpened = true;

	mcInFile.open(file);
	if (mcInFile.fail()) {
		std::cout << "File failed to open";
		bOpened = false;
	}
	return bOpened;
}
//***************************************************************************
// Function:		read
//
// Description: read in from stream and create account
//
// Parameters:  rcTheBank - refernce to bank
//
// Returned:    None
//***************************************************************************
void StreamAccountReader::read(Bank &rcTheBank) {
	char accountType;
	IAccount* pcAccount = nullptr;
	IFee* pcFee = nullptr;
	while (mcInFile >> accountType) {
		switch (accountType) {
			case 'S':
				pcFee = new MonthlyFee();
				pcAccount = new SavingsAccount(0, 0, 0, pcFee);
				break;
			case 'C':
				pcFee = new TransactionalFee();
				pcAccount = new CheckingAccount(0, 0, 0, pcFee);
				break;
		}
		mcInFile >> *pcAccount;

		try {
			rcTheBank.addAccount(pcAccount);
		}
		catch (const std::bad_array_new_length &e) {
			std::cout << e.what() << '\n';
		}
	}
}
//***************************************************************************
// Function:		closeAccountsDB
//
// Description: close file read from
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void StreamAccountReader::closeAccountsDB() {
	mcInFile.close();
}