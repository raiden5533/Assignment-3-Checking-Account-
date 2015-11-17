#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bank_account.h"
#include <iostream>

class checking_account : public bank_account {
	friend std::ostream &operator << (std::ostream& os, checking_account *yourAccount);
	public:
		checking_account();
		checking_account(float, float);
		void setMinBalance(checking_account yourAccount [],float newBalance, int i);
		float getMinBalance(checking_account yourAccount);
		void applyMonthlycharge(checking_account& yourAccount);
		void setMonthlyCharge(checking_account yourAccount[],float newCharge, int i);
		float getMonthlyCharge(checking_account yourAccount);
		void withdraw(float amount, checking_account& yourAccount);

	private:
		float minBalance;
		float monthlyCharge;
};

#endif

