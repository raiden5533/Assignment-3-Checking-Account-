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

void checking_account::setMinBalance(checking_account &yourBank, float tempMinBal) {
	if (tempMinBal == 0) {
		yourBank.minBalance = 5.00;
		return;
	}
	yourBank.minBalance = tempMinBal;
}

float checking_account::getMinBalance(checking_account yourBank) {
	return yourBank.minBalance;
}

void checking_account::applyMonthlycharge(checking_account& yourBank) {
	yourBank.updateBalance(yourBank, yourBank.minBalance);
}

void checking_account::setMonthlyCharge(checking_account &yourBank, float tempMonthlyChrg) {
	if (tempMonthlyChrg == 0) {
		yourBank.monthlyCharge = 1.00;
		return;
	}
	yourBank.monthlyCharge = tempMonthlyChrg;
}

float checking_account::getMonthlyCharge(checking_account yourBank) {
	return yourBank.monthlyCharge;
}

// Takes in the amount to withdraw, and the specific checking account it wants to alter by reference. 
// 
void checking_account::withdraw(float amount, checking_account &yourBank) {
	if (yourBank.getBalance(yourBank) < (amount + yourBank.monthlyCharge)) {
		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "You are requesting more money than available in the account. \n"
			<< "You have been returned to the Sub Menu." << std::endl;
		return;
	}
	else if ((yourBank.getBalance(yourBank) - amount) <= yourBank.minBalance) {
		yourBank.applyMonthlycharge(yourBank);
	}
	yourBank.bank_account::withdraw(yourBank, amount);
	return;
}

void checking_account::addCustomer(checking_account yourBank[], int input) {
	std::string first;
	std::string last;
	float startBal;
	float interest;
	float tempMinBal;
	float tempMonthlyChrg;
	int currentAccount = yourBank[0].getNumOfAccounts();

	// Checks to see if there is space to add another customer. If there is not sends the user back to the main menu.
	if (currentAccount >= 20) {
		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "The account list is full." << std::endl;
		return;
	}
	std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl;
	std::cout << "What is the customer's first name?" << std::endl;
	std::cin >> first;
	std::cout << "What is the customer's last name?" << std::endl;
	std::cin >> last;
	std::cout << "What is the customer's balance?" << std::endl;
	std::cin >> startBal;
	std::cout << "What is the customer's interest rate?" << std::endl;
	std::cin >> interest;
	std::cout << "What is the Minimum Balance for the account?" << std::endl;
	std::cin >> tempMinBal;
	std::cout << "What is the Monthly Charge for the account if it falls below the minimum balance?" << std::endl;
	std::cin >> tempMonthlyChrg;

	yourBank[0].setCustomerName(yourBank[currentAccount], first, last);
	yourBank[0].setBalance(yourBank[currentAccount], startBal);
	yourBank[0].setInterestRate(yourBank[currentAccount], interest);
	yourBank[0].setAccountNum(yourBank[currentAccount]);
	yourBank[0].setMinBalance(yourBank[currentAccount], tempMinBal);
	yourBank[0].setMonthlyCharge(yourBank[currentAccount], tempMonthlyChrg);
	yourBank[0].incrementNumOfAccounts();
	return;
}

std::ostream &operator<< (std::ostream &os, checking_account yourBank[]) {
	for (int i = 0; i < yourBank[0].getNumOfAccounts(); ++i) {
		os << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "Account Number:  " << yourBank[i].getAccountNum(yourBank[i]) << std::endl
			<< "Customer Name:   " << yourBank[i].getCustomerName(yourBank[i]) << std::endl
			<< "Account Balance: " << std::fixed << std::setprecision(2) << yourBank[i].getBalance(yourBank[i]) << std::endl
			<< "Interest:        " << std::fixed << std::setprecision(2) << yourBank[i].getInterestRate(yourBank[i]) << std::endl
			<< "Minimum Balance: " << std::fixed << std::setprecision(2) << yourBank[i].getMinBalance(yourBank[i]) << std::endl
			<< "Monthly Charge:  " << std::fixed << std::setprecision(2) << yourBank[i].getMonthlyCharge(yourBank[i]) << std::endl << std::endl;
	}
	return os;
}