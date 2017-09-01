#include <iostream>
#include <string>
using namespace std;

#include "config.h"

void log(const char *message) {
    cerr << ": " << message << endl;
}

void crash(const char *message) {
    cerr << "! " << message << endl;
    exit(-1);
}
