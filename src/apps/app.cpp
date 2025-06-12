#include "app.h"
#include "menu.h"

#include <iostream>

using namespace std;

app::app(/* args */)
{
	run();
}

app::~app()
{
}

void app::run()
{
	cout << "Running app..." << endl;

	Menu m;
}