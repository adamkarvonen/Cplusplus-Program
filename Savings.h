#ifndef SAVINGS_H
#define SAVINGS_H

using namespace std;

class Savings {

// public definitions of constructor and functions
public:
	Savings(double t_openingAmount, double t_monthlyDeposit, double t_interestRate, int t_numYears);

	void reportWithMonthlyDeposits();
	void reportWithoutMonthlyDeposits();

// private definitions of variables
private:
	int m_numYears;
	double m_openingAmount, m_monthlyDeposit, m_interestRate;

};

#endif