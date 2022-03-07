#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() {
	this->balance = 0;
	this->total = 0;
}
BankAccount::BankAccount(int input) {
	this->balance = input;
	this->total = 0;
}
void BankAccount::withdraw(int output) {
	this->balance -= output;
	this->total -= output;
}
void BankAccount::save(int input) {
	this->balance += input;
	this->total += input;
}
int BankAccount::getBalance() {
	return this->balance;
}
static int BankAccount::getAllMoneyInBank() {
	return total;
}