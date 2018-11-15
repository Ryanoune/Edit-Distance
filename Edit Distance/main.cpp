/*
Name:Ryan Oune
Class: CPSC 485
Last 4 CWID: 1343
How to compile:
Create a project in visual studio and add the main.cpp and matrix.h files to the project and debug.

Note:Added full solution folder to email.
*/

#include "matrix.h"

using namespace std;

int main() {
	string fword;
	string sword;
	cout << "Please enter first word: \n";
	cin >> fword;
	cout << "Please enter second word: \n";
	cin >> sword;
	
	//creates an object for creating the edit matrix
	matrix edit_matrix(fword, sword);

	//creates the edit matrix for the object
	edit_matrix.createEditMatrix();

	//backtraces to see where edits are being made in the strings
	edit_matrix.backtrace();

	//displays information
	edit_matrix.displayEditDistance();

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cin.get();
}