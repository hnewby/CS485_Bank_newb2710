#include "Bank.h"
#include "ScreenBankWriter.h"

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
	for (int i = 0; i < mNumAccts; i++)
	{
		rcOut.write(std::cout, *mapcAccounts[i]);
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
void Bank::deposit(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->deposit(amount);
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
void Bank::withdraw(int acctNum, long long amount) {
	mapcAccounts[getAccount(acctNum)]->withdraw(amount);
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
int Bank::getAccount(int acctNum) {
	bool bIsFound = false;
	int index = 0;

	while (!bIsFound && index < mMAX_ACCOUNTS)
	{
		if (mapcAccounts[index]->getAcctNum() == acctNum)
		{
			bIsFound = true;
		}
		else
		{
			index++;
		}
	}
	return index;
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
	if (mNumAccts <= mMAX_ACCOUNTS)
	{
		mapcAccounts[mNumAccts] = pcTheAccount;
		mNumAccts++;
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
		mapcAccounts[i]->endOfMonth();
	}
}