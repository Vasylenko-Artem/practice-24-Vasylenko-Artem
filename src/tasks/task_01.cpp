#include "tasks.h"

#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) { return (n == 0) ? 1 : n * factorial(n - 1); }

double a_k(int k)
{
	if (k == 0)
		return 1;

	double result = fabs(4 * (a_k(k - 1)) + 2);
	return sqrt(result);
}

double sum(int m, int n)
{
	if (m > n)
		return 0;

	double ak = a_k(m);
	double term = pow(-1, m) / factorial(m) * pow(ak / 2.0, m);

	cout << "Term " << m << ": " << term << endl;

	return term + sum(m + 1, n);
}

void task_01()
{
	std::cout << "Task 1 running\n";
	int m, n;
	cout << "Enter m and n: ";
	cin >> m >> n;

	if (m < 0 || n < 0 || m > n)
	{
		cerr << "Invalid input: m and n must be non-negative and m <= n." << endl;
		// return 1;
	}

	double result = sum(m, n);
	cout << "Result: " << result << endl;

	// return 0;
}