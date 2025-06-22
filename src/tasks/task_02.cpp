#include "tasks.h"

#include <iostream>
#include <list>

using namespace std;

void task_02()
{
	list<double> L;
	int n;
	double x;

	cout << "Input number of elements: ";
	cin >> n;

	cout << "Input " << n << " elements:\n";
	for (int i = 0; i < n; ++i)
	{
		double val;
		cin >> val;
		L.push_back(val);
	}

	cout << "Input x: ";
	cin >> x;

	if (L.empty())
	{
		cout << "List is empty. Product = 0\n";
		// return 0;
	}

	auto it = L.begin();
	double product = (*it - x); // (x１ - x)
	auto prev = it++;

	while (it != L.end())
	{
		product *= (*it - *prev); // (x2 - x1), (x3 - x2)...
		prev = it++;
	}

	cout << "\nList L:\n";
	for (const auto &val : L)
		cout << val << " ";

	cout << "\nResult: " << product << endl;

	// return 0;
}
