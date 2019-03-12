//***************************************************************************
// File name:  Bank.cpp
// Author:     Hannah Newby
// Date:       2/28/19
// Class:      CS485
// Assignment: Bank
// Purpose:    Bank class implamentation
//***************************************************************************
#include "Bank.h"
#include "ScreenBankWriter.h"
#include "ArrayAccountsContainer.h"
//***************************************************************************
// Constructor: Bank
//
// Description: Initialize Bank
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Bank::Bank() {
	mNumAccts = 0;
	mpcAccounts = new ArrayAccountsContainer();

}
//***************************************************************************
// Destructor:  Bank
//
// Description: Deconstructor for Bank
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Bank::~Bank() {
	
}
//***************************************************************************
// Function:		writeBank
//
// Description: write bank out
//
// Parameters:  rcOut - ostream to write to
//
// Returned:    None
//***************************************************************************
void Bank::writeBank(IBankWriter &rcOut) {
	rcOut.displayLines(std::cout);
	for (int i = 0; i < mpcAccounts->count(); i++)
	{
		rcOut.write(std::cout, (*mpcAccounts)[i]);
		std::cout << '\n';
	}
	rcOut.displayLines(std::cout);
}
//***************************************************************************
// Function:		deposit
//
// Description: deposit money into account
//
// Parameters:  acctNum - the account number
//							amount	- amount to be depoisted
//
// Returned:    None
//***************************************************************************
void Bank::deposit(int acctNum, Money amount) {
	int index;
	index = mpcAccounts->findAccount(acctNum);
	(*mpcAccounts)[index].deposit(amount);
}
//***************************************************************************
// Function:		withdraw
//
// Description: withdraw money from account
//
// Parameters:  acctNum - the account number
//							amount	- amount to be withdrawn
//
// Returned:    None
//***************************************************************************
void Bank::withdraw(int acctNum, Money amount) {
	int index;
	index = mpcAccounts->findAccount(acctNum);
	(*mpcAccounts)[index].withdraw(amount);
}
//***************************************************************************
// Function:		getAccount
//
// Description: given account number find index in array
//
// Parameters:  acctNum - the account number
//
// Returned:    int
//***************************************************************************
//int Bank::getAccount(int acctNum) {
//	bool bIsFound = false;
//	int index = 0;
//
//	while (!bIsFound && index < mMAX_ACCOUNTS)
//	{
//		if (mpcAccounts[index]->getAcctNum() == acctNum)
//		{
//			bIsFound = true;
//		}
//		else
//		{
//			index++;
//		}
//	}
//	return index;
//}
//***************************************************************************
// Function:		addAccount
//
// Description: add account* to array of accounts
//
// Parameters:  pcTheAccount - pointer to account
//
// Returned:    None
//***************************************************************************
void Bank::addAccount(IAccount *pcTheAccount) {
	//IAccount* pcAccount;
	
	/*if (mNumAccts <= mMAX_ACCOUNTS)
	{*/
		mpcAccounts->addAccount(pcTheAccount);
		//(*mpcAccounts)[mNumAccts].addAccount(pcTheAccount));
		/*&(*mpcAccounts)[mNumAccts] = pcTheAccount;
		pcAccount = &(*mpcAccounts)[mNumAccts];
		pcAccount = pcTheAccount;*/
	/*	mNumAccts++;
	}*/
}
//***************************************************************************
// Function:		print
//
// Description: prints Accounts to screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Bank::print() {
	IBankWriter* pcWriter = new ScreenBankWriter; // where am I deleteing?

	writeBank(*pcWriter);
	delete pcWriter;
}
//***************************************************************************
// Function:		endOfMonthForAll
//
// Description: runs end of month commands for all accounts
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Bank::endOfMonthForAll() {
	for (int i = 0; i < mNumAccts; i++)
	{
		(*mpcAccounts)[i].endOfMonth();
	}
}
//***************************************************************************
// Function:		deleteAll
//
// Description: runs through all accounts and deletes them
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Bank::deleteAll () {
	/*for (int i = 0; i < mNumAccts; i++)
	{
		delete (*mpcAccounts)[i];
	}*/
}