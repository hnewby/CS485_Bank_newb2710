//***************************************************************************
// File name:  MapAccountsClass.cpp
// Author:     Hannah Newby
// Date:       4/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MapAccountsClass class implamentation
//***************************************************************************
#include "MapAccountsContainer.h"

//***************************************************************************
// Constructor: MapAccountsContainer
//
// Description: Initialize Map container
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
MapAccountsContainer::MapAccountsContainer(){
}
//***************************************************************************
// Destructor:  MapAccountsContainter
//
// Description: Deconstructor for MapAccountsContainer
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
MapAccountsContainer::~MapAccountsContainer(){
}
//***************************************************************************
// Function:		addAccount
//
// Description: adds account to map
//
// Parameters:  pcTheAccount - pointer to the account to add
//
// Returned:    None
//***************************************************************************
void MapAccountsContainer::addAccount(IAccount * pcTheAccount){
	
	mpcAccounts.insert(pcTheAccount->getAcctNum(), pcTheAccount);
}
//***************************************************************************
// Function:		count
//
// Description: returns how many accounts in map
//
// Parameters:  None
//
// Returned:    int
//***************************************************************************
int MapAccountsContainer::count(){
	
	return mpcAccounts.size();
}
//***************************************************************************
// Function:		findAccount
//
// Description: gets account from Map
//
// Parameters:  acctNum - account number looking for
//
// Returned:    IAccount*
//***************************************************************************
IAccount * MapAccountsContainer::findAccount(unsigned int acctNum) {
	return mpcAccounts.find(acctNum);
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
bool MapAccountsContainer::isFull(){
	return false;
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
void MapAccountsContainer::applyVisitor(IAccountVisitor * pcAcctVisitor){
	for (int i = 0; i < mpcAccounts.size(); i++) {
		mpcAccounts.at(i)->accept(pcAcctVisitor);
	}
}
