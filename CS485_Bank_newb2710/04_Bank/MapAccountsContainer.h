//***************************************************************************
// File name:  MapAccountsContainer.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    MapAccountsContainer class header
//***************************************************************************
#pragma once
#ifndef MapAccountsContainer_h
#define MapAccountsContainer_h
#include "IAccountVisitor.h"
#include "IAccountsContainer.h"
#include <map>
class MapAccountsContainer : public IAccountsContainer {
public:
	MapAccountsContainer();
	~MapAccountsContainer();
	void addAccount(IAccount *pcTheAccount);
	int count();
	int findAccount(unsigned int);
	bool isFull();
	void applyVisitor(IAccountVisitor *);
	IAccount * getAccount(int index);

private:
	std::map<int, IAccount*> mpcAccounts;
};
#endif
