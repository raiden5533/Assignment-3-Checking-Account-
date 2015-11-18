#ifndef bank_account_H
#define bank_account_H

#include <string>

class bank_account {
	private:
		std::string customerName;
		int accountNum;
		float balance;
		float interestRate;
		// To keep track  of the number of user created accounts.
		static int createdAcc;
	public:
		// Default Constructor
		// PostCondition sets all class variables to a default value.
		bank_account();
		// Constructor to create a new customer, combines both first and last name paremeters, and sets balance and interest to parameter
		// PostCondition: Assigns value to the member variables, and generates an account number.
		bank_account(std::string firstName, std::string lastName, float startBal, float interest);
		// Checks to see if maxed out on customers if not to creates a new customer
		// combines both first and last name paremeters, and sets balance and interest to parameter
		// PostConditions:  Calls the constructor if not maxed out.  If maxed out responds informing the user.
		void addCustomer(bank_account yourBank[], int input);
		// Loops through the number of created accounts and prints them to the console.
		// PostCondition:  List all customers to the user.
		void printCustomerList(bank_account yourBank[]);
		// Ask the user for the amount they would like to deposit and adds it to the balance.
		// PostCondition:  balance is added to total
		void deposit(bank_account yourBank, float amount);
		// Ask the user for the amount they would like to withdraw and checks to see if that is available and then proceeds accordingly
		// PostCondition:  balance is compared against the withdrawal that was made and responds accordingly.
		void withdraw(bank_account& yourBank, float amount);
		// Display the balance of the current account selected.
		// PostCondition:  balance is displayed.
		void printBalance(bank_account &yourBank);
		// Calculates the interest accumulated for a month based off the set interstRate
		// PostCondition monthly interst is added to the balance
		void calculateInterest(bank_account yourBank[], int i);
		// Returns the value in the specific bank account balance
		float getBalance(bank_account &yourBank);
		// Takes in parameters for the specific bank account and sets the balance.
		void setBalance(bank_account &yourBank, float startBal);
		// Returns the customers named in the speicif bank acount
		std::string getCustomerName(bank_account &yourBank);

		void setCustomerName(bank_account &yourBank, std::string first, std::string last);
		int getAccountNum(bank_account& yourBank);
		void setAccountNum(bank_account &yourBank);
		float getInterestRate(bank_account &yourBank);
		void setInterestRate(bank_account &yourBank, float interest);
		void updateBalance(bank_account& yourBank, float amount);
		int getNumOfAccounts();
		void incrementNumOfAccounts();
		bank_account& operator+ (float amount);
};

#endif