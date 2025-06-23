#include "tasks.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

void task_04()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter at least two real numbers:\n";

	vector<double> numbers;

	string line;
	while (true)
	{
		getline(cin, line);
		if (line.empty()) // End of input
			break;

		istringstream iss(line);
		istream_iterator<double> in(iss), end;

		// Add the numbers to the vector
		numbers.insert(numbers.end(), in, end);
	}

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
