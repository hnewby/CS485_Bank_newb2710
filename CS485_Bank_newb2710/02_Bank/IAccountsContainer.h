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
		IAccountsContainer();
		~IAccountsContainer();
		virtual void addAccount(IAccount *pcTheAccount) = 0;
		virtual int count() = 0;
		virtual int findAccount(unsigned int) = 0;
		virtual bool isFull() = 0;
		virtual IAccount& operator[] (std::size_t index) = 0;
		virtual IAccount& operator[](std::size_t index) const = 0;

	private:

};
#endif