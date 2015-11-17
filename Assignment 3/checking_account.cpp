#include "stdafx.h"
#include "checking_account.h"
#include <iomanip>
#include <iostream>

checking_account::checking_account() {
	minBalance = 5.00;
	monthlyCharge = 1.00;
}

checking_account::checking_account(float newBalance, float newCharge) {
	minBalance = newBalance;
	monthlyCharge = newCharge;
}

void checking_account::setMinBalance(checking_account yourAccount[], float newBalance, int i) {
	if (newBalance == 0) {
		yourAccount[i].minBalance = 5.00;
	}
	yourAccount[i].minBalance = newBalance;
}

float checking_account::getMinBalance(checking_account yourAccount) {
	return yourAccount.minBalance;
}

void checking_account::applyMonthlycharge(checking_account& yourAccount) {
	yourAccount.updateBalance(yourAccount, yourAccount.minBalance);
}

void checking_account::setMonthlyCharge(checking_account yourAccount[], float newCharge, int i) {
	if (newCharge == 0) {
		yourAccount[i].monthlyCharge= 1.00;
	}
	yourAccount[i].monthlyCharge = newCharge;
}

float checking_account::getMonthlyCharge(checking_account yourAccount) {
	return yourAccount.monthlyCharge;
}

// Takes in the amount to withdraw, and the specific checking account it wants to alter by reference. 
// 
void checking_account::withdraw(float amount, checking_account &yourAccount) {
	if (yourAccount.getBalance(yourAccount) < (amount + yourAccount.monthlyCharge)) {
		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "You are requesting more money than available in the account. \n"
			<< "You have been returned to the Sub Menu." << std::endl;
		return;
	}
	else if ((yourAccount.getBalance(yourAccount) - amount) <= yourAccount.minBalance) {
		yourAccount.applyMonthlycharge(yourAccount);
	}
	yourAccount.bank_account::withdraw(yourAccount, amount);
	return;
}

std::ostream &operator<< (std::ostream &os, checking_account yourAccount[]) {	
	for (int i = 0; yourAccount[0].getNumOfAccounts(yourAccount[i]); ++i) {
		std::cout << yourAccount[0].getNumOfAccounts(yourAccount[i]);
		os << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "Account Number:  " << yourAccount[i].getAccountNum(yourAccount[i]) << std::endl
			<< "Customer Name:   " << yourAccount[i].getCustomerName(yourAccount[i]) << std::endl
			<< "Account Balance: " << std::fixed << std::setprecision(2) << yourAccount[i].getAccountNum(yourAccount[i]) << std::endl
			<< "Interest:        " << std::fixed << std::setprecision(2) << yourAccount[i].getInterestRate(yourAccount[i]) << std::endl
			<< "Minimum Balance: " << std::fixed << std::setprecision(2) << yourAccount[i].getMinBalance(yourAccount[i]) << std::endl
			<< "Monthly Charge:  " << std::fixed << std::setprecision(2) << yourAccount[i].getMonthlyCharge(yourAccount[i]) << std::endl << std::endl;
	}
	return os;
}