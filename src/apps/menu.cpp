#include "menu.h"
#include <ncurses.h>

using namespace std;

menu::menu(const map<char, pair<string, function<void()>>> &options)
	: options_(options) {}

menu::~menu() {}

void menu::show()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	int highlight = 0;

	vector<char> keys;
	vector<string> labels;

	for (const auto &opt : options_)
	{
		keys.push_back(opt.first);
		labels.push_back(opt.second.first);
	}

	while (true)
	{
		clear();
		mvprintw(0, 0, "Use arrows to navigate, Enter to select, 'q' to quit.");

		for (int i = 0; i < labels.size(); ++i)
		{
			if (i == highlight)
				attron(A_REVERSE);
			mvprintw(i + 2, 2, "%c - %s", keys[i], labels[i].c_str());
			if (i == highlight)
				attroff(A_REVERSE);
		}

		int input = getch();

		switch (input)
		{
		case KEY_UP:
			highlight = (highlight - 1 + labels.size()) % labels.size();
			break;
		case KEY_DOWN:
			highlight = (highlight + 1) % labels.size();
			break;
		case '\n':
		{
			clear();
			refresh();
			endwin();

			options_[keys[highlight]].second();

			cout << "\nPress Enter to return to menu...";
			cout.flush();

			cin.sync();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();

			initscr();
			noecho();
			cbreak();
			keypad(stdscr, TRUE);
			curs_set(0);
			break;
		}

		case 'q':
			endwin();
			return;
		}
	}
}
