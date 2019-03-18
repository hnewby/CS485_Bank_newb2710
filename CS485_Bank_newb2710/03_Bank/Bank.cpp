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
	for (int i = 0; i < mpcAccounts->count(); i++) {
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
// Function:		addAccount
//
// Description: add account* to array of accounts
//
// Parameters:  pcTheAccount - pointer to account
//
// Returned:    None
//***************************************************************************
void Bank::addAccount(IAccount *pcTheAccount) {
	mpcAccounts->addAccount(pcTheAccount);
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
	for (int i = 0; i < mpcAccounts->count(); i++)
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
	for (int i = 0; i < mpcAccounts->count(); i++)
	{
		delete &(*mpcAccounts)[i];
	}
	delete mpcAccounts;
}