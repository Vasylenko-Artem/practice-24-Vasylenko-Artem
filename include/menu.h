#pragma once

#include <map>
#include <string>
#include <functional>
#include <iostream>

class menu
{
public:
	menu(const std::map<char, std::pair<std::string, std::function<void()>>> &options);
	~menu();

	void show();

private:
	std::map<char, std::pair<std::string, std::function<void()>>> options_;
};
