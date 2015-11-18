// Assignment 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "checking_account.h"
#include <iostream>
#include <iomanip>

void menu(checking_account yourBank[]);
// Sub menu where you get the options to pick deposit, withdraw, print, calculate interest, or quit.
// PostCondition:  List the options available to the user.
void subMenu(checking_account yourBank[], int input);

int main()
{
	checking_account yourBank[20];
	menu(yourBank);
	return 0;
}

// Main Menu where all other class functions are called based on user input.
// PostCondition displays to the console options for the user to select.
void menu(checking_account yourBank[]) {

	// Variable to allow users to tell the application what option they want.
	int input;
	std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
		<< "Hello and welcome to your bank" << std::endl
		<< "Please use numbers 1-5 to select your options throughout the menu." << std::endl
		<< "What would you like to do? \n"
		<< "(1) Add a customer. \n"
		<< "(2) Print all customers. \n"
		<< "(3) Update customer data. \n"
		<< "(4) Exit Application." << std::endl;
	std::cin >> input;

	// If statement to figure out what function needs to be called based on user input
	// This conditional checks to see if there is space to add another customer and if so, asks the user for customer info and then calls addCustomer
	if (input == 1) {
		// If the user continues to choose to add more customers the while loop will continue to add them.
		while (input == 1) {
			yourBank[0].addCustomer(yourBank, input);
			// Asks the user if the would like to add another customer or return to the main menu.
			std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
				<< "Would you like to add another customer? \n"
				<< "(1) Add another customer. \n"
				<< "(2) Return to main menu. \n";
			std::cin >> input;
		}
		//  If the user chooses to go back to main.
		if (input == 2) {
			menu(yourBank);
		}
		// If the user does not know how to follow instructions.
		else {
			return;
		}
	}
	// Calls printCustomerList based off user input and then after returns the user to main.
	else if (input == 2) {
		std::cout << yourBank;
		menu(yourBank);
	}
	// Ask the user for the account number of the customer they would like to update and then calls the subMenu function.
	else if (input == 3) {

		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
			<< "Please enter the account number of the customer you would like to update." << std::endl;
		std::cin >> input;

		subMenu(yourBank, input);
		menu(yourBank);

	}
	// Closes application
	else if (input == 4) {
		return;
	}
	return;
}

// The Sub-Menu where the functions of a specific customer are called.  The user selects the options they would like to choose.
void subMenu(checking_account yourBank[], int input) {

	// The amount that the user inputs that will be either withdrawn or deposited
	float amount;

	// Int i will keep track of the current account being manipulated and pass the value to the other functions.  
	// The loops checks the user input and tries to match it to the appropriate account number.
	for (int i = 0; i <= yourBank[0].getNumOfAccounts(); ++i) {
		if (input == yourBank[0].getAccountNum(yourBank[i])) {
			std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
				<< "Customer Name:  " << yourBank[i].getCustomerName(yourBank[i]) << std::endl
				<< "Account Number: " << yourBank[i].getAccountNum(yourBank[i]) << std::endl << std::endl
				<< "What woud you like to do? \n"
				<< "(1) Make a deposit. \n"
				<< "(2) Make a withdrawal. \n"
				<< "(3) Print balance. \n"
				<< "(4) Process interest for current balance for the month. \n"
				<< "(5) Exit to Main Menu." << std::endl;
			std::cin >> input;

			// Ask the user for how much they would like to deposit and then calls deposit.
			if (input == 1) {
				std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
					<< "How much would you like to deposit? " << std::endl;
				std::cin >> amount;
				yourBank[i] + amount;
				input = yourBank[i].getAccountNum(yourBank[i]);
				subMenu(yourBank, input);
			}
			// Ask the user for how much they would like to withdraw and then calls withdraw.
			else if (input == 2) {
				std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl
					<< "How much would you like to withdraw? " << std::endl;
				std::cin >> amount;
				yourBank[0].withdraw(amount, yourBank[i]);
				input = yourBank[i].getAccountNum(yourBank[i]);
				subMenu(yourBank, input);
			}
			// Calls print balance to display the current account's balance
			else if (input == 3) {
				yourBank[0].printBalance(yourBank[i]);
				input = yourBank[0].getAccountNum(yourBank[i]);
				subMenu(yourBank, input);
			}
			// Calls calculateInterest for the current account.
			else if (input == 4) {
				yourBank[0].calculateInterest(yourBank, i);
				input = yourBank[i].getAccountNum(yourBank[i]);
				subMenu(yourBank, input);
			}
			// Returns the user to the main menu.
			else if (input == 5) {
				menu(yourBank);
			}
			// Error message when the account number does not match.
			else {
				return;
			}
		}
		// If another key is pressed the application is closed.
	}
}

