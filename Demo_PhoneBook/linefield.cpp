#include "linefield.h"


lineField::lineField(int height, QWidget *parent)
{
    Name = new QLineEdit(parent);
    Name->setObjectName(QString::fromUtf8("Name"));
    Name->setGeometry(QRect(10, height, 110, 20)); // X Y width height
    Name->show();

    Surname = new QLineEdit(parent);
    Surname->setObjectName(QString::fromUtf8("Surname"));
    Surname->setGeometry(QRect(140, height, 100, 20)); // X Y width height
    Surname->show();

    Zip = new QLineEdit(parent);
    Zip->setObjectName(QString::fromUtf8("Zip"));
    Zip->setGeometry(QRect(260, height, 60, 20)); // X Y width height
    Zip->show();
}

lineField::~lineField()
{
    delete Name;
    delete Surname;
    delete Zip;
}

