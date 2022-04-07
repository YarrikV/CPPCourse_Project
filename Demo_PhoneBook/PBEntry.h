#ifndef PBENTRY_H
#define PBENTRY_H

#include <string>
using namespace std;

class PBEntry {
public:
    string name;
    string surname;
    string zip;
    PBEntry() {}
    ~PBEntry() = default;
};

#endif // PBENTRY_H
