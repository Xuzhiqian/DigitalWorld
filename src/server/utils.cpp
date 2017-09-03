#include <iostream>
#include <string>
using namespace std;

#include "config.h"

extern "C" void log(const char *message) {
    cerr << ": " << message << endl;
}

extern "C" void crash(const char *message) {
    cerr << "! " << message << endl;
    exit(-1);
}
