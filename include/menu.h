#pragma once

#include <map>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

class menu
{
public:
	menu(const map<char, pair<string, function<void()>>> &options);
	~menu();

	void show();

private:
	map<char, pair<string, function<void()>>> options_;
};
