/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
	int id;
	string owner;
	string cardNumber;
	long ballance = 0;
	string startDate;
	string endDate;
	string bankName;
	// hành động:
	void checkBallance();		// kiểm tra số dư
	bool withdraw(long amount);	// rút tiền
	bool transfer(BankAccount other, long amount); // chuyển tiền
	bool deposit(long amount);	// nạp tiền
};

void BankAccount::checkBallance() {
	cout << "=========================================\n";
	cout << "Owner: " << owner << endl;
	cout << "Card Number: " << cardNumber << endl;
	cout << "Ballance: " << ballance << endl;
	cout << "End Date: " << endDate << endl;
}

bool BankAccount::withdraw(long amount) {
	cout << "=========================================\n";
	if (amount > 0 && amount <= ballance) {
		ballance -= amount;
		cout << "Withdrawn successfully." << endl;
		cout << "Account " << cardNumber << " -" << amount << endl;
		cout << "Your current ballance is: " << ballance << endl;
		return true; 
	}
	else {
		cout << "Your ballance is not enough. "
			<< "Please try other amount." << endl;
		return false;
	}
}

bool BankAccount::deposit(long amount) {
	cout << "=========================================\n";
	if (amount > 0) {
		ballance += amount;
		cout << "Deposit successfully." << endl;
		cout << "Transaction +" << amount << endl;
		cout << "Account " << cardNumber << endl;
		cout << "Your current ballance is " << ballance << endl;
		return true;
	}
	else {
		cout << "Invalid deposit amount. Please check again." << endl;
		return false;
	}
}

bool BankAccount::transfer(BankAccount other, long amount) {
	cout << "======================================\n";
	if (amount < ballance) {
		other.ballance += amount;
		ballance -= amount;
		cout << "Transferred successfully." << endl;
		cout << "Account " << cardNumber << " -" << amount << endl;
		cout << "Account " << other.cardNumber << " +" << amount << endl;
		cout << "Your current ballance is " << ballance << endl;
		return true;
	}
	else {
		cout << "Transfer failed. Ballance is not enough." << endl;
		return false;
	}
}

void initData(BankAccount& acc, int id, string owner,
	string bankName, string cardNum, long ballance,
	string startDate, string endDate) {
	acc.id = id;
	acc.owner = owner;
	acc.ballance = ballance;
	acc.bankName = bankName;
	acc.startDate = startDate;
	acc.endDate = endDate;
	acc.cardNumber = cardNum;
}



int main() {
	BankAccount acc1;
	BankAccount acc2;
	initData(acc1, 1, "LE VIET HUNG", "Vietcombank",
		"9704 3668 1450 3266 098", 99825000, "01/01/2023", "01/01/2028");
	initData(acc2, 2, "HOANG TRONG TU", "Vietcombank",
		"9704 3668 1450 3266 338", 5925000, "01/05/2023", "01/05/2028");
	int choice = 0;
	do {
		cout << "==================== MENU ====================\n";
		cout << "1. Check ballance\n2. Deposit\n3. Withdraw\n";
		cout << "4. Bank transfer\n0. Exit\n";
		cout << "Your choice? ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "<== Thank you for using our service! ==>\n";
			break;
		case 1: {
			cout << "Enter card number: ";
			string cardNumber;
			getline(cin, cardNumber);
			if (cardNumber.compare(acc1.cardNumber) == 0) {
				acc1.checkBallance();
			}
			else if (cardNumber.compare(acc2.cardNumber) == 0) {
				acc2.checkBallance();
			}
			else {
				cout << "Card number mismatch. Please try again!\n";
			}
			break;
		}
		case 2: { // giả định nạp tiền vào tk acc1
			long amount;
			cout << "Enter amount you want to deposit: ";
			cin >> amount;
			acc1.deposit(amount);
			break;
		}
		case 3: { // giả định rút tiền trên tk acc1
			long amount;
			cout << "Enter amount you want to with draw: ";
			cin >> amount;
			acc1.withdraw(amount);
			break;
		}
		case 4: { // giả định chuyển tiền từ tk acc1 sang tài khoản khác
			BankAccount* accPtr = nullptr;
			cout << "Enter card number: ";
			string cardNumber;
			getline(cin, cardNumber);
			if (cardNumber.compare(acc1.cardNumber) == 0) {
				accPtr = &acc1;
			}
			else if (cardNumber.compare(acc2.cardNumber) == 0) {
				accPtr = &acc2;
			}
			else {
				cout << "Card number mismatch. Please try again!\n";
			}
			if (accPtr != nullptr) {
				long amount;
				cout << "Enter amount you want to transfer: ";
				cin >> amount;
				acc1.transfer(*accPtr, amount);
			}
			break;
		}
		default:
			cout << "Invalid choice. Please try again!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}