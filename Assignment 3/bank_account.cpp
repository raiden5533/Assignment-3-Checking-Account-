#include "stdafx.h"
#include "bank_account.h"
#include <iostream>
#include <iomanip>

int bank_account::createdAcc = 0;

// Default Constructor 
bank_account::bank_account() {
	customerName = "John Smith";
	balance = 0;
	interestRate = 0;
	accountNum = createdAcc;
	return;
}

// Overloaded Constructor sets customerName to the sum of firstName and last name.  Sets balance and interestRate to the parameter values.
// PostCondition Customer information is created and set.
bank_account::bank_account(std::string firstName, std::string lastName, float startBal, float interest) {
	customerName = firstName + " " + lastName;
	balance = startBal;
	interestRate = interest;
	accountNum = createdAcc;
	return;
}

// Paremeters set values to the variables.  first and last are added to create customer name.
void bank_account::addCustomer(bank_account yourBank[], int input) {
	std::string first;
	std::string last;
	float startBal;
	float interest;

	// Checks to see if there is space to add another customer. If there is not sends the user back to the main menu.
	if (createdAcc >= 20) {
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

	yourBank[createdAcc].customerName = first + " " + last;
	yourBank[createdAcc].balance = startBal;
	yourBank[createdAcc].interestRate = (interest / 100);
	yourBank[createdAcc].accountNum = createdAcc;
	++createdAcc;
	return;	
}

// Loops through all customer accounts created and their variables and displays all information to the console.
void bank_account::printCustomerList(bank_account yourBank[]) {

	for (int i = 0; i < createdAcc; ++i) {

		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "Account Number:  " << yourBank[i].accountNum << std::endl
			<< "Customer Name:   " << yourBank[i].customerName << std::endl
			<< "Balance:         " << std::fixed << std::setprecision(2) << yourBank[i].balance << std::endl
			<< "Interest:        " << std::fixed << std::setprecision(2) << yourBank[i].interestRate << std::endl;
	}
	return;
}

void bank_account::deposit(bank_account yourBank, float amount) {

	yourBank.balance += amount;
	return;
}

// Takes the user amount  checks to see if it is more than the acccount balance if not it subtracts.
void bank_account::withdraw(bank_account& yourBank, float amount) {

	if (yourBank.balance < amount) {
		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "You are requesting more money than available in the account. \n"
			<< "You have been returned to the Sub Menu." << std::endl;
		return;
	}
	else {
		yourBank.balance -= amount;
		return;
	}
}

// Displays the account select balance to the console
void bank_account::printBalance(bank_account &yourBank) {

	std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
		<< "Customer Name:   " << yourBank.customerName << std::endl
		<< "Account Balance: " << std::fixed << std::setprecision(2) << yourBank.balance << std::endl << std::endl;
	return;
}

// Takes the users balance and determines the new balance based off the interest rate.
void bank_account::calculateInterest(bank_account yourBank[], int i) {

	yourBank[i].balance += (yourBank[i].balance * yourBank[i].interestRate);
}

// Function used for the monthly service charge in the checking_account class
void bank_account::updateBalance(bank_account& yourBank, float amount) {
	yourBank.balance -= amount;
}

float bank_account::getBalance(bank_account &yourBank) {
	return yourBank.balance;
}

void bank_account::setBalance(bank_account &yourBank, float startBal) {
	yourBank.balance = startBal;
}

std::string bank_account::getCustomerName(bank_account &yourBank) {
	return yourBank.customerName;
}

void bank_account::setCustomerName(bank_account &yourBank, std::string first, std::string last) {
	yourBank.customerName = first + " " + last;
	return;
}
int bank_account::getAccountNum(bank_account &yourBank) {
	return yourBank.accountNum;
}

float bank_account::getInterestRate(bank_account &yourBank) {
	return yourBank.interestRate;
}

void bank_account::setInterestRate(bank_account &yourBank, float interest) {
	yourBank.interestRate = interest;
	return;
}

int bank_account::getNumOfAccounts() {
	return createdAcc;
}

void bank_account::setAccountNum(bank_account &yourBank) {
	yourBank.accountNum = createdAcc;
	return;
}

void bank_account::incrementNumOfAccounts() {
	++createdAcc;
	return;
}

bank_account& bank_account::operator+ (float amount) {
	this->balance = this->balance + amount;
	return *this;
}