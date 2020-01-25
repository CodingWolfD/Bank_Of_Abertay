#include "Account.h"

Account::Account(std::string name, float balance)
{
	this->name = name;
	this->balance = balance;
}

Account::~Account() {}

void Account::addToBalance(float moneyAdded)
{
	this->balance += moneyAdded;
}

void Account::removeFromBalance(float moneyRemoved)
{
	this->balance -= moneyRemoved;
}

void Account::setAccountHolder(Customer* customer)
{
	this->accountHolder = customer->getName();
	this->ID = customer->getCustomerID();
}

int Account::getCustomersID()
{
	return this->ID;
}

void Account::setCustomersID(int newID)
{
	this->ID = newID;
}

std::string Account::getAccountHolder()
{
	return this->accountHolder;
}

float Account::getBalance()
{
	return this->balance;
}

std::string Account::getAccountName()
{
	return this->name;
}