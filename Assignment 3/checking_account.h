#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bank_account.h"
#include <iostream>

class checking_account : public bank_account {
	friend std::ostream &operator << (std::ostream& os, checking_account *yourBank);
public:
	checking_account();
	checking_account(float, float);
	void setMinBalance(checking_account &yourBank, float tempMinBal);
	float getMinBalance(checking_account yourBank);
	void applyMonthlycharge(checking_account &yourBank);
	void setMonthlyCharge(checking_account &yourBank, float tempMonthlyChrg);
	float getMonthlyCharge(checking_account yourBank);
	void withdraw(float amount, checking_account &yourBank);
	void addCustomer(checking_account yourBank[], int input);
private:
	float minBalance;
	float monthlyCharge;
};

#endif
