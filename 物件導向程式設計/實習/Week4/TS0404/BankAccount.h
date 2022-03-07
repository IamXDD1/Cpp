
class BankAccount {
private:
	int balance;
	static int total;
public:
	BankAccount() {
		this->balance = 0;
	}
	BankAccount(int input) {
		this->balance = input;
		this->total += input;
	}
	void withdraw(int output) {
		this->balance -= output;
		this->total -= output;
	}
	void save(int input) {
		this->balance += input;
		this->total += input;
	}
	int getBalance() {
		return this->balance;
	}
	static int getAllMoneyInBank() {
		return total;
	}
};
int BankAccount::total = 0;
