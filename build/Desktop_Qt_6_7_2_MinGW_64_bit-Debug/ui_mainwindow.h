/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *input;
    QPushButton *s4;
    QPushButton *s5;
    QPushButton *s3;
    QPushButton *s2;
    QPushButton *s1;
    QPushButton *s6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        input = new QTextEdit(centralwidget);
        input->setObjectName("input");
        input->setGeometry(QRect(150, 380, 481, 181));
        s4 = new QPushButton(centralwidget);
        s4->setObjectName("s4");
        s4->setGeometry(QRect(170, 340, 131, 31));
        s5 = new QPushButton(centralwidget);
        s5->setObjectName("s5");
        s5->setGeometry(QRect(320, 340, 121, 31));
        s3 = new QPushButton(centralwidget);
        s3->setObjectName("s3");
        s3->setGeometry(QRect(470, 310, 121, 31));
        s2 = new QPushButton(centralwidget);
        s2->setObjectName("s2");
        s2->setGeometry(QRect(320, 310, 121, 31));
        s1 = new QPushButton(centralwidget);
        s1->setObjectName("s1");
        s1->setGeometry(QRect(170, 310, 131, 31));
        s6 = new QPushButton(centralwidget);
        s6->setObjectName("s6");
        s6->setGeometry(QRect(470, 340, 121, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        s4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        s5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        s3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        s2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        s1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        s6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
