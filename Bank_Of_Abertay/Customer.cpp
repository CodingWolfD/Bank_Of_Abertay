#include "Customer.h"

Customer::Customer(std::string name)
{
	this->ID = rand() % 10000;
	this->name = name;
}

Customer::~Customer() {}

std::string Customer::getName()
{
	return this->name;
}

int Customer::getCustomerID()
{
	return this->ID;
}