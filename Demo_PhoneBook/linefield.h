#ifndef LINEFIELD_H
#define LINEFIELD_H

#include <qlineedit.h>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string surname;
    string zip;
    Person() {}
    ~Person() = default;
};

class lineField {
public:
    QLineEdit * Name;
    QLineEdit * Surname;
    QLineEdit * Zip;

    lineField(int height, QWidget * parent);
    ~lineField();
};


#endif // LINEFIELD_H
