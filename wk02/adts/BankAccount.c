
#include <stdio.h>
#include <stdlib.h>

#include "BankAccount.h"

struct bankAccount {
	int amount;
};

BankAccount newBankAccount(void) {
	BankAccount new = malloc(sizeof(*new));
	if (new == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	new->amount = 0;
	return new;
}

void deposit(BankAccount acc, int amount) {
	if (amount <= 0) {
		fprintf(stderr, "Invalid deposit amount!\n");
		exit(EXIT_FAILURE);
	}
	
	acc->amount += amount;
}

void withdraw(BankAccount acc, int amount) {
	if (amount <= 0) {
		fprintf(stderr, "Invalid withdrawal amount!\n");
		exit(EXIT_FAILURE);
	}
	
	if (amount > acc->amount) {
		fprintf(stderr, "Insufficient funds!\n");
		exit(EXIT_FAILURE);
	}
	
	acc->amount -= amount;
}

int getBalance(BankAccount acc) {
	return acc->amount;
}
