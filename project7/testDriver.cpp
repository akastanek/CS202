#include <iostream>
#include <fstream>
#include "Polynomial.h"

using namespace std;

bool checkEntry(int, int); //checks to see the number the user entered is less than the amount of polynomials and greater than zero

int main() {
	
	char* fileName = new char[20];
	int userChoice, num;
	Polynomial poly1;
	Polynomial poly2;
	Polynomial result;
	ifstream fin;
	
	cout << "Please enter the name of the file: ";
	cin >> fileName;

	//cout << poly1;

	fin.open(fileName);

	fin >> num; //gets the number of polynomial objects

	Polynomial* poly = new Polynomial[num];

	for (int i = 0; i < num; i++) {
		fin >> poly[i];
	}

	fin.close();

	do { //menu loop

		cout << "===========================================" << endl;
		cout << "Please choose one of the following options: " << endl;
		cout << "1) Print all polynomials" << endl;
		cout << "2) Solve a polynomial" << endl;
		cout << "3) Compare two polynomials" << endl;
		cout << "4) Add two polynomials" << endl;
		cout << "5) Subtract two polynomials" << endl;
		cout << "6) Multiply a polynomial by a constant" << endl;
		cout << "7) Mulitply two polynomials" << endl;
		cout << "8) End program" << endl; 
		cin >> userChoice;
		cout << "-------------------------------------------" << endl;

		switch (userChoice) {

			case 1:
				for (int i = 0; i < num; i++) {
					cout << i + 1 << ") " << poly[i] << endl; //calls << function
				}
				break;
			case 2:
				int solve, solution, var;
				do { //loops until input is valid
					cout << "Please choose which polynomial you would like to solve: ";
					cin >> solve;
					solve--;
				} while (!checkEntry(solve, num));
				cout << "Please enter the number you would like to plug in for x: ";
				cin >> var;
				solution = poly[solve].solve(var); //calls solve function
				cout << "f(" << var << ") = " << solution << endl;
				break;
			case 3:
				int comp1, comp2;
				do { //loops until input is valid
					cout << "Please choose the number of the first polynomial: ";
					cin >> comp1;
					comp1--;
				} while (!checkEntry(comp1, num));
				do { //loops until input is valid
					cout << "Please choose the number of the second polynomial: ";
					cin >> comp2;
					comp2--;
				} while (!checkEntry(comp2, num));
				if (poly[comp1] == poly[comp2]) { //calls == function
					cout << "These two polynomials are equal to each other." << endl;
				} else if (poly[comp1] != poly[comp2]) { //calls != function
					cout << "These two polynomials are not equal to each other." << endl;
				}
				break;
			case 4:
				int add1, add2;
				do { //loops until input is valid
					cout << "Please choose the number of the first polynomial addend: ";
					cin >> add1;
					add1--;
				} while (!checkEntry(add1, num));
				do { //loops until input is valid
					cout << "Please choose the number of the second polynomial addend: ";
					cin >> add2;
					add2--;
				} while (!checkEntry(add2, num));
				result = poly[add1] + poly[add2]; //calls + function which adds two polynomials
				cout << result << endl;
				break;
			case 5:
				int sub1, sub2;
				do { //loops until input is valid
					cout << "Please choose the number of the first polynomial subtractor: ";
					cin >> sub1;
					sub1--;
				} while (!checkEntry(sub1, num));
				do { //loops until input is valid
					cout << "Please choose the number of the second polynomial subtractor: ";
					cin >> sub2;
					sub2--;
				} while (!checkEntry(sub2, num));
				result = poly[sub1] - poly[sub2]; //calls - function which adds two polynomials
				cout << result << endl;
				break;
			case 6:
				int mult1, mult2;
				do { //loops until input is valid
					cout << "Please choose the number of the polynomial multiple: ";
					cin >> mult1;
					mult1--;
				} while (!checkEntry(mult1, num));
				cout << "Please choose a constant integer as a multiplier: ";
				cin >> mult2;
				result = poly[mult1] * mult2; //calls * function which adds a polynomials and a constant
				cout << result << endl;
				break;
			case 7:
				int multA, multB;
				do { //loops until input is valid
					cout << "Please choose the number of the first polynomial multiple: ";
					cin >> multA;
					multA--;
				} while (!checkEntry(multA, num));
				do { //loops until input is valid
					cout << "Please choose the number of the second polynomial multiple: ";
					cin >> multB;
					multB--;
				} while (!checkEntry(multB, num));
				result = poly[multA] * poly[multB]; //calls * function which adds two polynomials
				cout << result << endl;
				break;
			case 8:
				cout << "Exiting program" << endl;
				break;
			default:
				cout << "Invalid entry" << endl;

		}

	} while (userChoice != 8);

	delete[] poly;
	poly = NULL;
	delete[] fileName;
	fileName = NULL;

	return 0;
}

bool checkEntry(int a, int max) {

	if (a >= max || a < 0) {
		cout << "Invalid entry" << endl;
		return false;
	} else return true;

}