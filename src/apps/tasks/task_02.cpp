#include "tasks.h"

#include <iostream>
#include <list>

using namespace std;

void task_02()
{
	list<double> L;
	int n;

	cout << "Input number of elements: ";
	cin >> n;

	cout << "Input " << n << " elements:\n";
	for (int i = 0; i < n; ++i)
	{
		double val;
		cin >> val;
		L.push_back(val);
	}

	if (L.empty())
	{
		cout << "List is empty. Product = 0\n";
		return;
	}

	auto front = L.begin();
	auto back = L.rbegin();
	double product = 1;

	for (int i = 0; i < n / 2; ++i)
	{
		product *= (*front - *back);
		++front;
		++back;
	}

	cout << "\nList L:\n";
	for (const auto &val : L)
		cout << val << " ";

	cout << "\nResult: " << product << endl;
}

// 1 2 3 4
// (1 - 4) (2 - 3) = 3

// 3 2 1
// (3 - 1) (2 - 1) = 2