//***************************************************************************
// File name:  ArrayAccountsClass.cpp
// Author:     Hannah Newby
// Date:       3/12/19
// Class:      CS485
// Assignment: ArrayAccountsClass
// Purpose:    ArrayAccountsClass class implamentation
//***************************************************************************
#include "ArrayAccountsContainer.h"

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
	if (mNumAccts <= mMAX_ACCOUNTS) {
		mapcAccounts[mNumAccts] = pcTheAccount;
		mNumAccts++;
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
int ArrayAccountsContainer::findAccount(unsigned int acctNum) {
	bool bIsFound = false;
	int index = 0;

	while (!bIsFound && index < mMAX_ACCOUNTS) // can use isFull
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
// Function:		operator[]
//
// Description: returns array index
//
// Parameters:  index - index of array we want
//
// Returned:    IAccount &
//***************************************************************************
IAccount& ArrayAccountsContainer::operator[] (std::size_t index) {
	return  *mapcAccounts[index];
}
//***************************************************************************
// Function:		operator[] const
//
// Description: returns array index
//
// Parameters:  index - index of array we want
//
// Returned:    const IAccount &
//***************************************************************************
const IAccount& ArrayAccountsContainer::operator[](std::size_t index) const {
	return *mapcAccounts[index];
}