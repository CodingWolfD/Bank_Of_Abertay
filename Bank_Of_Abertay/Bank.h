#pragma once

#include "Account.h"
#include "Customer.h"

class Bank
{
	public:
		void start();
		void withdrawMoney(Account* account);
		void depositMoney(Account* account);
		void displayBalance(Account* account);

		bool checkIfEligibleForLoan(float loanAmount, Account* customer);
		void applyForLoan(Account* account);
		void calculateInterest(int yearsChosen, Account* customer);

	private:
};