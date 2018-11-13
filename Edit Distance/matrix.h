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

}