#include "app.h"
#include "menu.h"
#include "tasks.h"

#include <iostream>

using namespace std;

app::app(/* args */) { run(); }

app::~app() {}

void app::run()
{
	menu m(tasks);

	m.show();
}
