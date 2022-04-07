#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "linefield.h"
#include <QMainWindow>
#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<lineField *> Fields;
    int NbrOfLines;
    int offset = -16;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addEntry();
    void delEntry();
    void sort();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
