#pragma once

#include <iostream> 
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
using std::ifstream;
using std::ofstream;

void displayInt(void* i);
void displayStr(void* i);
int compare_ints(void* arg1, void* arg2);
int compare_strs(void* arg1, void* arg2);