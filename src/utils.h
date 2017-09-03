#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
using namespace std;

#include "config.h"

extern "C" void log(const char *message);

extern "C" void crash(const char *message);

#endif
