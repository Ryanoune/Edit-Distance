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
	this->fWord_length = fword.length()+1;
	this->sWord_length = sword.length() + 1;
}

int matrix::getflength() {
	return fWord_length;
}

int matrix::getslength() {
	return sWord_length;
}
void matrix::createEditMatrix() {
	this->edit_matrix = new int*[getslength()];
	for (int i = 0; i < getslength(); i++) {
		edit_matrix[i] = new int[getflength()];
		for (int j = 0; j < getflength(); i++) {
			cout << " X ";
		}
		cout << endl;
	}
}
void matrix::displayEditDistance() {
	cout << "The matrix:" << endl;

}