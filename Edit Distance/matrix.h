#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<string>
using namespace std;
class matrix {
public:
	matrix(string, string);
	int getflength();
	int getslength();
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
void matrix::createEditMatrix() {
	cout << "First word: " << this->fWord << endl;
	cout << "Length: " << getflength() << endl;
	cout << "Second word: " << this->sWord << endl;
	cout << "Length: " << getslength() << endl;

	for (int i = 0; i < getslength() + 1; i++) {
		edit_matrix[i] = new int[getflength() + 1];
	}
	this->edit_matrix = new int*[getslength() + 1];
	int setFRow = 0;
	int setFCol = 0;
	for (int i = 0; i < getslength() + 1; i++) {
		for (int j = 0; j < getflength() + 1; j++) {
			if (i == 0) {
				edit_matrix[i][j] = setFRow;
				setFRow++;
			}
			else if (j == 0) {
				edit_matrix[i][j] = setFCol;
				setFCol++;
			}

		}
	}
	cout << endl;
	

	
	
	for (int i = 1; 0 < getslength()+1; i++) {
		
		for (int j = 0; j < getflength()+1; j++) {
			cout << edit_matrix[i][j] << " ";

		}
		cout << endl;
	}
}
void matrix::displayEditDistance() {
	cout << "The matrix:" << endl;


	
}