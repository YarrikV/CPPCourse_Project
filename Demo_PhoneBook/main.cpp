#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

#include "mainwindow.h"
#include "linefield.h"
#include <QApplication>
#include <QString>

using namespace std;





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
