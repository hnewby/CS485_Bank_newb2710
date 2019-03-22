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
#include "CurrencyMismatchException.h"
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
		try {
			rcOut.write(std::cout, (*mpcAccounts)[i]);
		}
		catch (const std::range_error &e) {
			std::cout << e.what() << '\n';
		}
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
	try {
		int index;
		index = mpcAccounts->findAccount(acctNum);
		(*mpcAccounts)[index].deposit(amount);
	}
	catch (const CurrencyMismatchException &e) {
		std::cout << e.what() << '\n';
	}
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
	try {
		int index;
		index = mpcAccounts->findAccount(acctNum);
		(*mpcAccounts)[index].withdraw(amount);
	}
	catch (const CurrencyMismatchException &e) {
		std::cout << e.what() << '\n';
	}

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
	try {
		mpcAccounts->addAccount(pcTheAccount);
	}
	catch (const std::bad_array_new_length &e) {
		delete pcTheAccount;
		std::cout << e.what() << '\n';
	}
	
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
		try {
			(*mpcAccounts)[i].endOfMonth();
		}
		catch (const std::range_error &e) {
			std::cout << e.what() << '\n';
		}
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
		try {
			delete &(*mpcAccounts)[i];
		}
		catch (const std::range_error &e) {
			std::cout << e.what() << '\n';
		}
	}
	delete mpcAccounts;
}