#include "tasks.h"

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
	size_t size;
	cout << "Enter even size of vector: ";
	cin >> size;

	if (size <= 0 || size % 2 != 0)
	{
		cerr << "Error: Size must be a positive even number.\n";
		return;
	}

	vector<double> V(size);
	cout << "Enter " << size << " real numbers:\n";
	for (size_t i = 0; i < size; ++i)
		cin >> V[i];

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
}

// Input:
// -4 2 -3 5 6 -1 -7 8

// Output:
// -1 2 -1 5 1 -1 -7 1
