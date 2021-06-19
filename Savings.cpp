#include <iostream>
#include <iomanip>

using namespace std;

#include "Savings.h"

// Constructor
Savings::Savings(double t_openingAmount, double t_monthlyDeposit, double t_interestRate, int t_numYears) {

	this->m_openingAmount = t_openingAmount;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_interestRate = t_interestRate;
	this->m_numYears = t_numYears;
}

void Savings::reportWithMonthlyDeposits() {

	// Create variables
	double yearEndSavings, interestEarned, monthEndSavings;
	interestEarned = 0;
	yearEndSavings = this->m_openingAmount;
	monthEndSavings = this->m_openingAmount;

	// Print header for first chart
	cout << "----------------------------------------------------------------" << endl;
	cout << "     Balance and Interest With Additional Monthly Deposits      " << endl;
	cout << "================================================================" << endl;
	cout << setw(6) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop for numYears entered by user
	for (int i = 1; i <= this->m_numYears; i++) {

		// set interest earned to 0
		interestEarned = 0;

		// For loop for 12 months
		for (int m = 1; m <= 12; m++) {

			// Add monthly deposit to monthEndSavings
			monthEndSavings += this->m_monthlyDeposit;

			// Caclulate monthly Interest
			double monthlyInterest = (monthEndSavings * this->m_interestRate * 0.01) / 12;

			// Add monthlyInterest to interestEarned and monthEndSavings
			interestEarned += monthlyInterest;
			monthEndSavings += monthlyInterest;
		}

		// Set yearEndSavings to monthEndSavings
		yearEndSavings = monthEndSavings;

		// Print out year, yearEndSavings, and interestEarned in a formatted manner
		cout << setw(6) << i << fixed << setprecision(2) << right << setw(25) << yearEndSavings << setw(30) << interestEarned << endl << endl;

	}

	cout << endl;

}

void Savings::reportWithoutMonthlyDeposits() {

	// Create variables
	double yearEndSavings, interestEarned;
	yearEndSavings = this->m_openingAmount;

	// Print header for second chart
	cout << "----------------------------------------------------------------" << endl;
	cout << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << "================================================================" << endl;
	cout << setw(6) << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop for user numYears
	for (int i = 1; i <= this->m_numYears; i++) {

		// Calculate interestEarned, add to yearEndSavings, print in a formatted manner
		interestEarned = this->m_interestRate * 0.01 * yearEndSavings;
		yearEndSavings += interestEarned;
		cout << setw(6) << i << fixed << setprecision(2) << right << setw(25) << yearEndSavings << setw(30) << interestEarned << endl << endl;

	}
}