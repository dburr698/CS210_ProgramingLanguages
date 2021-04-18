/*
 * Calculator.cpp
 *
 *  Date: 3/12/2021
 *  Author: David Burrell
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer{};

	cout << "Would you like to evaluate and expression? (y/n)" << endl;
	cin >> answer;

	while (answer == 'y')
	{
		cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2;
		if (operation == '+') {
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		}
		if (operation == '-') {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
		}
		if (operation == '*') {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
		}
		if (operation == '/') {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
		}
	

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}
}