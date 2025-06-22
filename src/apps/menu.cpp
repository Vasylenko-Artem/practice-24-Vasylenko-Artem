#include "menu.h"

using namespace std;

menu::menu(const map<char, pair<string, function<void()>>> &options)
	: options_(options) {}

menu::~menu() {}

void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pauseConsole()
{
	cout << "\nPress any key to continue...\n";
	getchar();
	getchar();
	clearConsole();
}

void newLine() { cout << endl; }

bool checkChoiceInput(char ch, const vector<char> &validChoices)
{
	for (char validCh : validChoices)
		if (ch == validCh)
			return true;

	return false;
}

void menu::show()
{
	clearConsole();
	char ch;

	vector<char> validChoices = {'q'};
	for (const auto &option : options_)
		validChoices.push_back(option.first);

	while (true)
	{
		cout << "Tasks:";
		for (const auto &option : options_)
			cout
				<< "\n"
				<< option.first
				<< " - "
				<< option.second.first;

		newLine();
		cout << "\nq - Quit";

		newLine();
		cout << "\nYour choice: ";

		cin >> ch;
		clearConsole();

		if (ch == 'q')
		{
			cout << "Goodbye!\n";
			pauseConsole();
			break;
		}

		if (!checkChoiceInput(ch, validChoices))
		{
			cout << "Invalid choice. Please try again.\n";
			pauseConsole();
			continue;
		}

		clearConsole();
		cout << "Task" << ch << " selected\n";
		newLine();

		options_.at(ch).second();

		pauseConsole();
	}
}
