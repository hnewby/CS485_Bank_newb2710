//***************************************************************************
// File name:  IFee.h
// Author:     Hannah Newby
// Date:       2/23/19
// Class:      CS485
// Assignment: Bank
// Purpose:    IFee class header
//***************************************************************************
#pragma once

class IFee {
	public:
		IFee();
		IFee(long long amount);
		~IFee();
		virtual long long chargeMonthlyFee(const long long balance) = 0;
		virtual long long chargeDepositFee(const long long balance) = 0;
		virtual long long chargeWithdrawFee(const long long balance) = 0;

protected:
		long long getAmount(); // might not need this

	private:
		long long mAmount;
};