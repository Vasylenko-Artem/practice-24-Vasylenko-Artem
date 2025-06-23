#include "tasks.h"

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

void task_06()
{
	vector<int> V = {21, 42, 13, 33, 24, 14, 15, 25, 35, 99, 99, 99};

	multimap<int, int> M;

	// Grouping by last digit
	for (auto it = V.begin(); it != V.end(); ++it)
		M.insert({abs(*it) % 10, *it});

	// Creating a map for results (key - last digit, value - sum without the first one)
	map<int, int> result;

	for (auto it = M.begin(); it != M.end();)
	{
		int current_digit = it->first;

		// Get the range of elements with the current key
		auto range = M.equal_range(current_digit);

		vector<int> group;
		for (auto jt = range.first; jt != range.second; ++jt)
			group.push_back(jt->second);

		// Calculate the sum without the first element
		int sum = (group.size() > 1) ? accumulate(group.begin() + 1, group.end(), 0) : 0;

		result[current_digit] = sum;

		// Move to the next group
		it = range.second;
	}

	// Output
	cout << "Result:\n";
	for (auto it = result.begin(); it != result.end(); ++it)
		cout << it->first << " : " << it->second << endl;
}
