#include <time.h>
#include <cstdlib>

#include "Bank.h"

Bank* bank;

int main()
{
	srand(time(0));
	bank->start();
	delete bank;
}