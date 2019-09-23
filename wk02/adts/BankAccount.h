// Interface

#ifndef BANK_ACCOUNT_H // Header Guard
#define BANK_ACCOUNT_H

typedef struct bankAccount *BankAccount;

/**
 * Open a new bank account
 */
BankAccount newBankAccount(void);

/**
 * Deposit some money into the bank account
 * The amount should be positive
 */
void deposit(BankAccount acc, int amount);

/**
 * Withdraw some money from the bank account
 * The amount should be positive and not be
 * greater than the current balance of the
 * account
 */
void withdraw(BankAccount acc, int amount);

/**
 * Get the current balance of the account
 */
int getBalance(BankAccount acc);

#endif
