
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "BankAccount.h"

int main(void) {
	BankAccount account = newBankAccount();
	
	// account->balance = 1000000;
	// ^ You can't do this. Why?
	
	printf("Current amount is %d\n", getBalance(account));
	assert(getBalance(account) ==   0);
	// It's better to assert than print when testing
	
	deposit(account, 150);
	
	printf("Current amount is %d\n", getBalance(account));
	assert(getBalance(account) == 150);
	// It's better to assert than print when testing
	
	withdraw(account, 60);
	assert(getBalance(account) ==  90);
}
