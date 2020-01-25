#include <iostream>
#include "Bank.h"

Customer* customer1 = new Customer("Bob");;
Account* baseAccount = new Account("Classic Account", 1000);

void Bank::start()
{
	int menuChoice = 0;

	baseAccount->setAccountHolder(customer1);

	std::cout << "\nHello and welcome to the Bank of Abertay!";
	std::cout << "\nHow can i help you today?";

	std::cout << "\n1) Display your current balance \n2) Add money to your account \n3) Withdraw money from your account \n4) Apply for a loan\n";
	std::cin >> menuChoice;

	switch (menuChoice)
	{
		case 1:
		{
			system("CLS");
			displayBalance(baseAccount);
		}
			break;
		case 2:
		{
			depositMoney(baseAccount);
		}
			break;
		case 3:
		{
			withdrawMoney(baseAccount);
		}
			break;
		case 4:
		{
			applyForLoan(baseAccount);
		}
			break;
	}
}

void Bank::displayBalance(Account* account)
{
	std::cout << "\nAccount Type: " << account->getAccountName();
	std::cout << "\nCustomers Bank ID: " << account->getCustomersID();
	std::cout << "\nAccount Holder: " << account->getAccountHolder();
	std::cout << "\nYour current account balance is: \n" << char(156) << account->getBalance() << "\n";

	Bank::start();
}

void Bank::withdrawMoney(Account* customer)
{
	std::cout << "Enter how much money you would like to withdraw: \n" << char(156);
	std::cin >> customer->money;

	while (customer->money > customer->getBalance())
	{
		std::cout << "Unavaliable funds: \n" << char(156);
		std::cin >> customer->money;
	}

	std::cout << "You withdrew: " << char(156) << customer->money;
	customer->removeFromBalance(customer->money);

	displayBalance(customer);
}

void Bank::depositMoney(Account* customer)
{
	std::cout << "Enter how much money you would like to deposit: \n" << char(156);
	std::cin >> customer->money;
	customer->addToBalance(customer->money);

	displayBalance(customer);
}

void Bank::applyForLoan(Account* account)
{
	std::cout << "Enter how much you would like to borrow: \n" << char(156);
	std::cin >> account->borrowAmount;

	if (checkIfEligibleForLoan(account->borrowAmount, account))
	{
		std::cout << "\nCongratulations " << account->getAccountHolder();
		std::cout << "\nYou have been approved for your loan of - " << char(156) << account->borrowAmount;
	
		std::cout << "\nHow long would you like to borrow -" << char(156) << account->borrowAmount;
		std::cout << "\n1) 1 year \n2) 2 years \n3) 3 years\n";

		std::cin >> account->yearsToBorrow;

		calculateInterest(account->yearsToBorrow, account);

		std::cout << "Your total borrowed amount is: " << char(156) << account->totalMoneyBorrowed << " for " << account->yearsToBorrow;
		account->addToBalance(account->borrowAmount);
		displayBalance(account);
	}
	else
	{
		std::cout << "\nUnfortunately " << account->getAccountHolder();
		std::cout << "\nYou have been declined for your loan of - " << char(156)  << account->borrowAmount;

		displayBalance(account);
	}
}

bool Bank::checkIfEligibleForLoan(float loanAmount, Account* customer)
{
	if (loanAmount < customer->getBalance() * 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Bank::calculateInterest(int yearsChosen, Account* customer)
{
	float loanMoney = customer->borrowAmount;
	loanMoney += customer->borrowAmount * 0.1f * yearsChosen;
	customer->totalMoneyBorrowed = loanMoney;
}