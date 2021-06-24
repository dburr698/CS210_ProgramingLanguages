#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	// Variables to store inputs
	float initialInvest, monthlyDeposit, annualInterest, years, months;

	// Variable to store year end total amount
	float totalAmount;

	// Variables to store interest and year end interest
	float interestAmount, yearlyInterest;

	// Display form to user
	cout << "*************************\n";
	cout << "*******Data Input********\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of Years: \n";

	// To get press any key to continue line
	system("PAUSE");

	// Get data from user
	cout << "*************************\n";
	cout << "*******Data Input********\n";
	cout << "Initial Investment Amount: \n";
	cin >> initialInvest;
	cout << "Monthly Deposit: \n";
	cin >> monthlyDeposit;
	cout << "Annual Interest: \n";
	cin >> annualInterest;
	cout << "Number of Years: \n";
	cin >> years;
	months = years * 12;

	system("PAUSE");

	// Set total amount to initial investment to be updated
	totalAmount = initialInvest;

	// Display year data wihtout monthly deposits
	cout << "\nBalance and Interest without Additional Monthy Deposits\n";
	cout << "================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "----------------------------------------------------------------\n";

	for (int i = 0; i < years; ++i) {
		// Calculate yearly interest
		interestAmount = (totalAmount) * (annualInterest / 100);
		// Calculate year end total
		totalAmount = totalAmount + interestAmount;
		// Print results to table rounded to two decimal places
		cout << (i + 1) << "\t\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}

	// Set total amount to initial investment to be updated
	totalAmount = initialInvest;

	// Display year data with monthly deposits
	cout << "\nBalance and Interest with Additional Monthy Deposits\n";
	cout << "================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "----------------------------------------------------------------\n";

	for (int i = 0; i < years; ++i) {
		// Set yearly interest to zero at the start of the year
		yearlyInterest = 0;

		for (int j = 0; j < 12; ++j) {
			// Calculate monthly interest
			interestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

			// Calculate month end interest
			yearlyInterest = yearlyInterest + interestAmount;

			// Calculate month end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyInterest << endl;
	}

	return 0;
}