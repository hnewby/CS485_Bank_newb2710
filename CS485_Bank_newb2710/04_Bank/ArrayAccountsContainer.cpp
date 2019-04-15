//***************************************************************************
// File name:  ArrayAccountsContainer.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: ArrayAccountsClass
// Purpose:    ArrayAccountsClass class implamentation
//***************************************************************************
#include "ArrayAccountsContainer.h"
#include <exception>
//***************************************************************************
// Constructor: ArrayAccountsContainer
//
// Description: Initialize Array container
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ArrayAccountsContainer::ArrayAccountsContainer() {
	mNumAccts = 0;
}
//***************************************************************************
// Destructor:  ArrayAccountsContainter
//
// Description: Deconstructor for ArrayAccountsContainer
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ArrayAccountsContainer::~ArrayAccountsContainer() {

}
//***************************************************************************
// Function:		addAccount
//
// Description: adds account to array
//
// Parameters:  pcTheAccount - pointer to the account to add
//
// Returned:    None
//***************************************************************************
void ArrayAccountsContainer::addAccount(IAccount *pcTheAccount) {
	if (mNumAccts < mMAX_ACCOUNTS) {
		mapcAccounts[mNumAccts] = pcTheAccount;
		mNumAccts++;
		sort();
	}
	else {
		throw std::bad_array_new_length();
	}
}
//***************************************************************************
// Function:		counts
//
// Description: returns how many accounts in array
//
// Parameters:  None
//
// Returned:    int
//***************************************************************************
int ArrayAccountsContainer::count() {
	return mNumAccts;
}
//***************************************************************************
// Function:		findAccount
//
// Description: find account in array given account num
//
// Parameters:  acctNum - account number searching for
//
// Returned:    int
//***************************************************************************
IAccount * ArrayAccountsContainer::findAccount(unsigned int acctNum) {
	bool bIsFound = false;
	int index = 0;
	while (!bIsFound && index < mNumAccts) // can use isFull
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
	return mapcAccounts[index];
}
//***************************************************************************
// Function:		isFull
//
// Description: checks if array is full
//
// Parameters:  None
//
// Returned:    bool
//***************************************************************************
bool ArrayAccountsContainer::isFull() {
	bool bIsFull = false;
	if (mNumAccts >= mMAX_ACCOUNTS)
	{
		bIsFull = true;
	}
	return bIsFull;
}
//***************************************************************************
// Function:		applyVisitor
//
// Description: applys visitor pattern to every element in array
//
// Parameters:  pcAcctVisitor - pointer to account visitor using
//
// Returned:    None
//***************************************************************************
void ArrayAccountsContainer::applyVisitor(IAccountVisitor *pcAcctVisitor)
{
	for (int i = 0; i < mNumAccts; i++) {
		mapcAccounts[i]->accept(pcAcctVisitor);
	}
}
//***************************************************************************
// Function:		getAccount
//
// Description: get account at given index
//
// Parameters:  index - index in array
//
// Returned:    IAccount *
//***************************************************************************
IAccount * ArrayAccountsContainer::getAccount(int index){
	return mapcAccounts[index];
}
//***************************************************************************
// Function:		sort
//
// Description: sort the array by acct # accending
//
// Parameters:  None
//
// Returned:		None
//***************************************************************************
void ArrayAccountsContainer::sort(){
	IAccount *pTemp;
	for (int i = 0; i < mNumAccts; i++) {
		for (int j = 1; j < mNumAccts - 1; j++) {
			if (mapcAccounts[j]->getAcctNum() > mapcAccounts[i]->getAcctNum()) {
				pTemp = mapcAccounts[j];
				mapcAccounts[j] = mapcAccounts[i];
				mapcAccounts[i] = pTemp;
			}
		}
	}
}
