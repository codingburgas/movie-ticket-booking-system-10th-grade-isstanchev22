#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void ascii() {
	ifstream f("ascii.txt");
	if (f.is_open())
		cout << f.rdbuf();
}

void printMenu() {
	ascii();
	int choice;
	cout << "1|    Login / Register" << endl;
	cout << "2|    View Top Movies" << endl;
	cout << "3|    Locations     " << endl;
	while (true) {
		cin >> choice;
		switch (choice) {
		case 1:
			ascii();
			break;
		case 2:
			ascii();
			break;
		case 3:
			ascii();
			break;
		}
	}
	}
int main() {
	printMenu();
	}




