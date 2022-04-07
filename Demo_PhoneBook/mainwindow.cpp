#include "PBEntry.h"
#include "mainwindow.h"
#include "linefield.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <algorithm>
#include <qtextstream.h>
#include <QtWidgets/QScrollBar>

string strToUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

void printV(vector<Person> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i].name << std::endl;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NbrOfLines = 1; // Start with one entry

    lineField *MyLineField = new lineField(25 * NbrOfLines + offset, ui->scrollArea);
    QScrollBar *QSC = ui->scrollArea->verticalScrollBar();
    QSC->setValue(25 * NbrOfLines + offset);
    QSC->show();

    Fields.push_back(MyLineField);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEntry()
{
    cout << "Entry added." << endl;
    NbrOfLines++;
    // Add 3 UI element
    lineField *MyLineField = new lineField(25 * NbrOfLines + offset, ui->scrollArea);
    Fields.push_back(MyLineField);
    // Reset scroll bar
    QScrollBar *QSC = ui->scrollArea->verticalScrollBar();
    QSC->setValue(25 * NbrOfLines + offset);
}

void MainWindow::delEntry()
{

    // Only if more than one entry
    if (NbrOfLines > 1)
    {
        cout << "Entry removed." << endl;
        NbrOfLines--;
        // Remove last entry
        delete Fields.back();
        Fields.pop_back();
        // Update UI
        QScrollBar *QSC = ui->scrollArea->verticalScrollBar();
        QSC->setValue(25 * NbrOfLines + offset);
    }
}

void MainWindow::sort()
{

    if (NbrOfLines > 1)
    {

        vector<Person> toSort;

        for (auto i = Fields.begin(); i != Fields.end(); i++)
        {
            Person p;
            p.name = (*i)->Name->displayText().toStdString();
            p.surname = (*i)->Surname->displayText().toStdString();
            p.zip = (*i)->Zip->displayText().toStdString();
            toSort.push_back(p);
        }

        int myvar = ui->SortSelector->currentIndex(); // which thing to sort
        // QTextStream(stdout) << myvar << QString(" ") << QString((int)toSort.size());

        std::sort(toSort.begin(), toSort.end(),
                  [myvar](Person P1, Person P2) -> bool {
                      switch (myvar)
                      {
                      case 0:
                          return strToUpper(P1.name) < strToUpper(P2.name);
                          break;
                      case 1:
                          return strToUpper(P1.surname) < strToUpper(P2.surname);
                          break;
                      case 2:
                          return strToUpper(P1.zip) < strToUpper(P2.zip);
                          break;
                      }
                      return false;
                  });

        int line = 0;
        for (auto i = Fields.begin(); i != Fields.end(); i++)
        {
            (*i)->Name->setText(QString::fromStdString(toSort[line].name));
            (*i)->Surname->setText(QString::fromStdString(toSort[line].surname));
            (*i)->Zip->setText(QString::fromStdString(toSort[line].zip));
            line++;
        }
    }

    //    sort(book.begin(), book.end(), [](Person a, Person b) { return strToUpper(a.name) < strToUpper(a.name); });

    //    sort(book.begin(), book.end(), [](Person a, Person b) { return strToUpper(a.surname) < strToUpper(b.surname); });

    //    sort(book.begin(), book.end(), [](Person a, Person b) { return strToUpper(a.postalcode) < strToUpper(b.postalcode); });
}
