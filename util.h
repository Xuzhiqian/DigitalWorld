#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
using namespace std;

void log(const char *message) {
    cout << ": " << message << endl;
}

void crash(const char *message) {
    cout << "! " << message << endl;
    exit(-1);
}

#endif
