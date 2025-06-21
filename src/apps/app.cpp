#include "app.h"
#include "menu.h"
#include "tasks.h"

#include <iostream>

using namespace std;

void app::run()
{
	menu m(tasks);
	m.show();
}
