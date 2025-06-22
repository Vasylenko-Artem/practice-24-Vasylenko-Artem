#include "tasks.h"

// Задача_2_10.Дано вектор V з парною кількістю елементів.У першій половині
// вихідного вектора замінити всі негативні числа на −1,
// а другий – все позитивні
// числа на 1. Використовувати два виклики алгоритму replace_if з різними
// параметрами – функціональними об'єктами.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Functor for checking negative values
struct IsNegative
{
	bool operator()(double x) const { return x < 0; }
};

// Functor for checking positive values
struct IsPositive
{
	bool operator()(double x) const { return x > 0; }
};

void task_05()
{
	vector<double> V;

	cout << "Enter an even number of elements:\n";
	double num;
	while (cin >> num)
		V.push_back(num);

	if (V.size() % 2 != 0)
	{
		cerr << "Error: The number of elements must be even.\n";
		// return 1;
	}

	// Dividing a vector into two halves
	auto mid = V.begin() + V.size() / 2;

	// First half: replace negatives with -1
	replace_if(V.begin(), mid, IsNegative(), -1);

	// Second half: replace positives with 1
	replace_if(mid, V.end(), IsPositive(), 1);

	// Result
	cout << "\nModified vector:\n";
	for (double val : V)
		cout << val << " ";

	// return 0;
}

// Input:
// -4 2 -3 5 6 -1 -7 8

// Output:
// -1 2 -1 5 1 -1 -7 1
