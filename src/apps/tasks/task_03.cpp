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
			res += static_cast<char>(tolower((unsigned char)c));
	return res;
}

void task_03()
{
	string inFile, outFile;

	cout << "Enter input file name: ";
	cin >> inFile;

	ifstream in("public/" + inFile);
	if (!in)
	{
		cout << "File not found\n";
		return;
	}

	cout << "Enter output file name: ";
	cin >> outFile;

	ofstream out("public/" + outFile);

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
}
