#include "tasks.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cctype>

using namespace std;

string clean(const string &word)
{
	string res;
	for (char c : word)
		if (isalnum((unsigned char)c))
			res += static_cast<char>(tolower(c));
	return res;
}

void task_03()
{
	string inFile, outFile;

	cout << "Enter input file name: ";
	getline(cin, inFile);

	cout << "Enter output file name: ";
	getline(cin, outFile);

	ifstream in(inFile);
	ofstream out(outFile);

	unordered_map<string, int> freq;
	string word;
	while (in >> word)
	{
		word = clean(word);
		if (!word.empty())
			++freq[word];
	}

	for (const auto &[w, c] : freq)
		if (c == 1)
			out << w << "\n";

	// return 0;
}
