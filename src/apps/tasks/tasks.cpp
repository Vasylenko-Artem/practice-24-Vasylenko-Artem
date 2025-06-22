#include "tasks.h"

using namespace std;

const map<char, pair<string, function<void()>>> tasks = {
	{'1', {"Task 1", task_01}},
	{'2', {"Task 2", task_02}},
	{'3', {"Task 3", task_03}},
	{'4', {"Task 4", task_04}},
	{'5', {"Task 5", task_05}},
	{'6', {"Task 6", task_06}}};
