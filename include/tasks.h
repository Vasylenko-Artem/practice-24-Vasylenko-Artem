#pragma once

#include <iostream>

#include <map>
#include <string>
#include <functional>

void task_01();
void task_02();
void task_03();
void task_04();
void task_05();
void task_06();

extern const std::map<char, std::pair<std::string, std::function<void()>>> tasks;
