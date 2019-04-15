//***************************************************************************
// File name:  IAccountsContainer.h
// Author:     Hannah Newby
// Date:       3/9/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IAccountsContainer class header
//***************************************************************************
#pragma once
#ifndef IAccountsContainer_h
#define IAccountsContainer_h
#include "IAccount.h"

class IAccountsContainer {
	public:
		virtual ~IAccountsContainer();
		virtual void addAccount(IAccount *pcTheAccount) = 0;
		virtual int count() = 0;
		virtual IAccount * findAccount(unsigned int) = 0;
		virtual bool isFull() = 0;
		virtual void applyVisitor(IAccountVisitor *pcAccountVisitor) = 0;
		virtual IAccount * getAccount(int index) = 0;
	
	private:

};
#endif