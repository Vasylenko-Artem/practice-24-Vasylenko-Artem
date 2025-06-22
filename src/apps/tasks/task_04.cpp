#include "tasks.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void task_04()
{
	cout << "Enter at least two real numbers:\n";
	istream_iterator<double> in(cin), end;
	vector<double> numbers(in, end);

	if (numbers.size() < 2)
	{
		cerr << "Error: Need at least two elements.\n";
		return;
	}

	vector<double> even_indexed;
	int index = 0;

	remove_copy_if(
		numbers.begin(),
		numbers.end(),
		back_inserter(even_indexed),
		[&index](double)
		{ return ++index % 2 != 0; });

	cout << "Elements with even positions:\n";
	ostream_iterator<double> out(cout, " ");
	copy(even_indexed.begin(), even_indexed.end(), out);
}
