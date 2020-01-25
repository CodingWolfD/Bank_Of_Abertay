#pragma once

#include <string>

class Customer
{
	public:
		Customer(std::string name);
		~Customer();

		std::string getName();
		int getCustomerID();
	
	private:
		std::string name;
		int ID;
};