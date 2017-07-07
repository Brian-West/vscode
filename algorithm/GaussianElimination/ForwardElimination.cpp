#include<stdlib.h>
#include<iostream>
using namespace std;

double absolute(double n) {
	if (n < 0)
		n = 0 - n;
	return n;
}

void ForwardElimination(double** index, int n) {
	for (int i = 0;i < n-1;i++) {
		for (int j = i + 1;j < n;j++) {
			for (int k = n;k >= i;k--) {
				index[j][k] -= index[i][k] * index[j][i] / index[i][i];
			}
		}
	}
}

void BetterForwardElimination(double** index, int n) {
	for (int i = 0;i < n-1;i++) {
		int pivotrow = i;
		for (int j = i + 1;j < n;j++) {
			if (absolute(index[j][i]) > absolute(index[pivotrow][i]))
				pivotrow = j;
		}
		for (int k = 0;k <= n;k++) {
			double temp = index[i][k];
			index[i][k] = index[pivotrow][k];
			index[pivotrow][k] = temp;
		}
		for (int j = i + 1;j < n;j++) {
			double temp = index[j][i] / index[i][i];
			for (int k = 0;k <= n;k++) {
				index[j][k] -= index[i][k] * temp;
			}
		}
	}
}

double* BackSubstitution(double** index, int n) {
	double* solution = new double[n];
	for (int i = 0; i < n; i++) {
		double result = index[n - 1 - i][n];
		for (int j = 0; j < i; j++) {
			result -= solution[j] * index[n - 1 - i][n - 1 - j];
		}
		solution[i] = 1.0 * result / index[n - 1 - i][n - 1 - i];
	}
	return solution;
}

int main() {
	double** index = new double*[3];
	for (int i = 0; i < 3; i++) {
		index[i] = new double[4];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> index[i][j];
		}
	}

	BetterForwardElimination(index, 3);
	double* result = BackSubstitution(index, 3);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << "\t";
	}

	for (int i = 0; i < 3; i++) {
		delete[] index[i];
	}
	delete[] index;
	delete[] result;
	system("pause");
	return 0;
}