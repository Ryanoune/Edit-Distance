#include "matrix.h"

using namespace std;

int main() {
	string fword;
	string sword;
	cout << "Please enter first word: \n" << endl;
	cin >> fword;
	cout << "Please enter second word: \n" << endl;
	cin >> sword;
	matrix edit_matrix(fword, sword);

	edit_matrix.createEditMatrix();

	edit_matrix.displayEditDistance();
	system("pause");
}