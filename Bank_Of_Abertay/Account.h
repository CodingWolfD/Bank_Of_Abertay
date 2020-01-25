#pragma once
#include <string>
#include "Customer.h"

class Account
{
public:
	Account(std::string accountName, float balance);
	Account();
	~Account();

	float getBalance();
	void addToBalance(float moneyAdded);
	void removeFromBalance(float moneyRemoved);
	void setAccountHolder(Customer* customer);
	int getCustomersID();
	std::string getAccountName();
	std::string getAccountHolder();

	void setCustomersID(int newID);

	float money;
	float borrowAmount;
	int yearsToBorrow;
	float totalMoneyBorrowed;

	private:
		float balance;
		int newMoney;
		int ID;
		std::string name;
		std::string accountHolder;
};