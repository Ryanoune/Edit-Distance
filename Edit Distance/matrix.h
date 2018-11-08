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
	int fWord_length;
	int sWord_length;
	int** edit_matrix;
};

#endif

matrix::matrix(string fword, string sword) {
	this->fWord = fword;
	this->sWord = sword;
	this->fWord_length = fword.length();
	this->sWord_length = sword.length();
}

int matrix::getflength() {
	return fWord_length;
}

int matrix::getslength() {
	return sWord_length;
}

int matrix::leastValue(int tl, int t, int l) {
	return min({ tl, t, l });
}

void matrix::createEditMatrix() {
	cout << "First word: " << this->fWord << endl;
	cout << "Length: " << getflength() << endl;
	cout << "Second word: " << this->sWord << endl;
	cout << "Length: " << getslength() << endl;

	int width = getslength() + 1;
	int height = getflength() + 1;
	int** matrix = new int*[width];

	for (int i = 0; i < width; ++i) {
		matrix[i] = new int[height];
	}

	int num = 0;
	for (int i = 0; i < width; ++i) {
		matrix[0][i] = num;
		num++;
	}

	num = 0;
	for (int i = 0; i < height; ++i) {
		matrix[i][0] = num;
		num++;
	}

	for (int i = 1; i < width; i++) {
		for (int j = 1; j < height; j++) {
			//set values to top-left, top, and left of current index
			int top_left = matrix[i - 1][j - 1];
			int top = matrix[i][j - 1];
			int left = matrix[i - 1][j];
			
			//set possible values for index
			int tlSum;
			int tSum;
			int lSum;

			//top-left sum
			//if character is a match
			if (sWord.at(i-1) == fWord.at(j-1)) {
				tlSum = top_left;
			}
			else {
				tlSum = top_left + 1;
			}

			//top sum
			tSum = top + 1;
			//left sum
			lSum = left + 1;

			cout << "tlsum: " << tlSum << endl;
			cout << "tsum: " << tSum << endl;
			cout << "lsum: " << lSum << endl;
			matrix[i][j] = leastValue(tlSum, tSum, lSum);
			cout << matrix[i][j] << endl;
		}
		
	}



	this->edit_matrix = matrix;
}
void matrix::displayEditDistance() {
	cout << "The matrix:" << endl;

	int width = getslength() + 1;
	int height = getflength() + 1;



	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cout << this->edit_matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "The edit distance is: " << this->edit_matrix[width-1][height-1] << endl;

}