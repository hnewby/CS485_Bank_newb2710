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
#include "MapAccountsContainer.h"
#include "CurrencyMismatchException.h"
#include "BackupVisitor.h"
#include "MonthVisitor.h"
#include "PrintVisitor.h"
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
	mpcAccounts = new MapAccountsContainer();
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
	IAccountVisitor *pcAcctVisitor;

	pcAcctVisitor = new PrintVisitor();
	mpcAccounts->applyVisitor(pcAcctVisitor);
	rcOut.displayLines(std::cout);
	delete pcAcctVisitor;
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
		(mpcAccounts->findAccount(acctNum))->deposit(amount);
		
	}
	catch (const CurrencyMismatchException &e) {
		e.what();//swallow
		//std::cout << e.what() << '\n';
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
		(mpcAccounts->findAccount(acctNum))->withdraw(amount);
	}
	catch (const CurrencyMismatchException &e) {
		e.what();//swallow
		//std::cout << e.what() << '\n';
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
		throw std::bad_array_new_length();
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
	IBankWriter* pcWriter = new ScreenBankWriter; 
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

	IAccountVisitor *pcAcctVisitor;
	try {
		pcAcctVisitor = new MonthVisitor();
		mpcAccounts->applyVisitor(pcAcctVisitor);
		delete pcAcctVisitor;
	}
	catch (const std::range_error &e) {
		std::cout << e.what() << '\n';
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
			delete &*(*mpcAccounts).getAccount(i);
		}
		catch (const std::range_error &e) {
			std::cout << e.what() << '\n';
		}
	}
	delete mpcAccounts;
}
//***************************************************************************
// Function:		backup
//
// Description: creates a backup visitor
//
// Parameters:  checkingFile - name of file to send checking accounts
//							savingFile	 - name of file to send savings accounts
//
// Returned:    None
//***************************************************************************
void Bank::backup(std::string checkingFile, std::string savingFile)
{
	IAccountVisitor *pcAcctVisitor;
	
	pcAcctVisitor = new BackupVisitor(checkingFile, savingFile);
	mpcAccounts->applyVisitor(pcAcctVisitor);
	delete pcAcctVisitor;
}
