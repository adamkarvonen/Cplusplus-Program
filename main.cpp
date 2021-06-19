// Adam Karvonen
// Project 2

#include <iostream>
#include <iomanip>

using namespace std;

#include "Savings.h"

int main() {

	// Create variables
	double openingAmount, monthlyDeposit, interestRate;
	int numYears;
	char inputChar = 'y';

	// Print first screen
	cout << "***********************************" << endl;
	cout << "************ Data Input ***********" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of Years:" << endl;

	// Wait for user to press any key
	system("pause");

	cout << endl;

	// While user has not entered n
	while (inputChar != 'n') {

		// Take user input
		cout << "***********************************" << endl;
		cout << "*********** Data Input ************" << endl;

		cout << "Enter Initial Investment Amount: $";
		cin >> openingAmount;

		cout << "Enter Monthly Deposit: $";
		cin >> monthlyDeposit;

		cout << "Enter Annual Interest: %";
		cin >> interestRate;

		cout << "Enter Number of Years: ";
		cin >> numYears;

		// Wait for user to press any key
		system("pause");
		cout << endl;

		// Create new savings object with user input
		Savings savingsObj = Savings(openingAmount, monthlyDeposit, interestRate, numYears);
		// Call reportWithoutMonthlyDeposits function
		savingsObj.reportWithoutMonthlyDeposits();

		cout << endl;

		// If monthly deposit is more than 0, call reportWithMonthlyDeposits function
		if (monthlyDeposit > 0) {
			savingsObj.reportWithMonthlyDeposits();
		}

		cout << endl;

		// Get user input for y or n
		cout << "Enter y to input new values, or n to end the program." << endl;

		cin >> inputChar;

		cout << endl;

	}
}