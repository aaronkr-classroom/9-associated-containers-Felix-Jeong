// factorial.cpp

#include <iostream>

using namespace std;

int factorial(int n);

int main() {
	int num;
	cout << "Enter a positive int: ";
	cin >> num;
	cout << "num! is " << factorial(num) << endl;
	return 0;
}

int factorial(int n) {
	if (n == 0 || n == 1) // �⺻ ���
		return 1;
	else
		return n* factorial(n - 1); 
}