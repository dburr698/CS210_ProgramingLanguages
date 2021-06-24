/*  Chada Tech Digital Clocks
	CS-210 Programming Languages
	Southern New Hampshire University
	Author: David Burrell
	Date: March 19, 2021
*/
 
#include<iostream>
#include<ctime>
#include<iomanip>


using namespace std;

// Create the Clock class with variable for hour, minute, second
class Clock {
public:
	int hour;
	int minute;
	int second;
};

//Create class for 12 hour format
class standardTime : public Clock{
public:
	string meridian;
	standardTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		second = ltm->tm_sec;
		if (hour > 12) {
			hour -= 12;
		}
	}
	// Method to add one hour
	void addOneHour() {
		if (hour == 12) {
			hour = 1;
			if (meridian == "AM") {
				meridian = "PM";
			}
			else if (meridian == "PM") {
				meridian = "AM";
			}
		}
		else {
			hour += 1;
		}
	 }
	// Method to add one minute
	void addOneMinute() {
		if (minute == 59) {
			minute = 0;
			addOneHour();
		}
		else {
			minute += 1;
		}
	}
	// Method to add one second
	void addOneSecond() {
		if (second == 59) {
			second = 0;
			addOneMinute();
		}
		else {
			second += 1;
		}
	}
};

// Create class for 24 hour format
class militaryTime : public Clock {
public:
	militaryTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		second = ltm->tm_sec;
	}
	// Method to add one hour
	void addOneHour() {
		if (hour == 23) {
			hour = 0;
		}
		else {
			hour += 1;
		}
	}
	// Method to add one minute
	void addOneMinute() {
		if (minute == 59) {
			minute = 0;
			addOneHour();
		}
		else {
			minute += 1;
		}
	}
	// Mehtod to add one second
	void addOneSecond() {
		if (second == 59) {
			second = 0;
			addOneMinute();
		}
		else {
			second += 1;
		}
	}
};

// Display the time in 12-hour and 24-hour format
void displayTime(standardTime h1, militaryTime h2) {
	cout << "\t\t************************\t\t";
	cout << "************************\n";
	cout << "\t\t*\t12-hour Clock\t*\t\t";
	cout << "*\t24-hour Clock\t*\n";
	cout << "\t\t*\t" << setw(2) << setfill('0') << h1.hour << ":" << setw(2) << setfill('0') << h1.minute << ":" << setw(2)
		<< setfill('0') << h1.second << h1.meridian << "\t*\t\t";
	cout << "*\t" << setw(2) << setfill('0') << h2.hour << ":" << setw(2) << setfill('0') << h2.minute << ":" << setw(2)
		<< setfill('0') << h2.second << "\t*\n";
	cout << "\t\t************************\t\t";
	cout << "************************\n";
}

int main() {
	standardTime h1;
	militaryTime h2;
	displayTime(h1, h2);
	int choice = 0;
	// Menu with options to add one hour, minute, or second or to exit program
	while (choice != 4) {
		cout << "\n\n*************************\n";
		cout << "* 1 - Add One Hour\t*\n";
		cout << "* 2 - Add One Minute\t*\n";
		cout << "* 3 - Add One Second\t*\n";
		cout << "* 4 - Exit Program\t*\n";
		cout << "*************************\n";

		cin >> choice;
		switch (choice) {
		case 1:
			h1.addOneHour();
			h2.addOneHour();
			break;
		case 2:
			h1.addOneMinute();
			h2.addOneMinute();
			break;
		case 3:
			h1.addOneSecond();
			h2.addOneSecond();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Enter valid option:";
		}
		system("cls");
		displayTime(h1, h2);
	}
}