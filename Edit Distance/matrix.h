#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class matrix {
public:
	matrix(string, string);
	int getflength();
	int getslength();
	int leastValue(int, int, int);
	void createEditMatrix();
	void displayEditDistance();
private:
	string fWord;
	string sWord;
	string edit1;
	string edit2;
	int f_length;
	int s_length;
	int** edit_matrix;
};

#endif

matrix::matrix(string fword, string sword) {
	this->fWord = fword;
	this->sWord = sword;
	this->f_length = fWord.length();
	this->s_length = sWord.length();
}

int matrix::getflength() {
	return f_length;
}

int matrix::getslength() {
	return s_length;
}

int matrix::leastValue(int l, int t, int tl) {
	return min({ l, t, tl });
}

void matrix::createEditMatrix() {
	int row = getflength();
	int col = getslength();

	//allocate the array
	int** arr = new int*[row+1];
	for (int i = 0; i < row +1; i++)
		arr[i] = new int[col+1];
	
	string str1 = fWord;
	string str2 = sWord;

//creating the edit matrix
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			// sets first collumn
			if (i == 0) {
				arr[i][j] = j;
			}

			// sets first row
			else if (j == 0) {
				arr[i][j] = i;
			}

			// if character is the same then use value from upper-left
			else if (fWord.at(i - 1) == sWord.at(j - 1)) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			// if the character is different, find the minimum between insert, remove, and replace
			else {
				arr[i][j] = 1 + leastValue(arr[i][j - 1],  // Insert 
					arr[i - 1][j],  // Remove 
					arr[i - 1][j - 1]); // Replace 
			}
		}
	}

	
	this->edit_matrix = arr;
	

	int firstI = getflength();
	int secI = getslength();
	int rowI = f_length;
	int colI = s_length;
	int curr = arr[rowI][colI];
//backtrace
	while (rowI != 0 && colI != 0) {
		curr = leastValue(arr[rowI][colI - 1],  // Insert 
			arr[rowI - 1][colI],  // Remove 
			arr[rowI - 1][colI - 1]); // Replace 

		if (curr == arr[rowI - 1][colI - 1]) {
			rowI = rowI - 1;
			colI = colI - 1;
			firstI = firstI - 1;
			secI = secI - 1;
		}
		else if (curr == arr[rowI - 1][colI]) {
			rowI = rowI - 1;
			colI = colI;
			str2.insert(secI, "_");
			firstI = firstI - 1;
		}
		else if (curr == arr[rowI][colI - 1]) {
			rowI = rowI;
			colI = colI - 1;
			str1.insert(firstI, "_");
			secI = secI - 1;
		}
	}
	
	this->edit1 = str1;
	this->edit2 = str2;
}
void matrix::displayEditDistance() {
	cout << "The matrix:" << endl;

	

	for (int i = 0; i <= f_length; i++)
	{
		for (int j = 0; j <= s_length; j++)
		{
			cout << this->edit_matrix[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "The edit distance is: " << this->edit_matrix[f_length][s_length] << endl;

	cout << "Alignment is: \n";
	cout << edit1 << endl;
	cout << edit2 << endl;
}