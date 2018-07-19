/********************************************************************************
** Form generated from reading UI file 'guicreator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUICREATOR_H
#define UI_GUICREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUICreator
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUICreator)
    {
        if (GUICreator->objectName().isEmpty())
            GUICreator->setObjectName(QStringLiteral("GUICreator"));
        GUICreator->resize(476, 368);
        GUICreator->setMinimumSize(QSize(476, 368));
        GUICreator->setMaximumSize(QSize(476, 368));
        centralWidget = new QWidget(GUICreator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 70, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 110, 75, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 20, 331, 211));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 150, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 250, 75, 23));
        pushButton_5->setAutoDefault(false);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 250, 113, 20));
        GUICreator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUICreator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 476, 23));
        GUICreator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUICreator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUICreator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUICreator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUICreator->setStatusBar(statusBar);

        retranslateUi(GUICreator);

        pushButton_5->setDefault(false);


        QMetaObject::connectSlotsByName(GUICreator);
    } // setupUi

    void retranslateUi(QMainWindow *GUICreator)
    {
        GUICreator->setWindowTitle(QApplication::translate("GUICreator", "GUICreator", nullptr));
        pushButton->setText(QApplication::translate("GUICreator", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QApplication::translate("GUICreator", "\347\273\223\346\235\237", nullptr));
        pushButton_3->setText(QApplication::translate("GUICreator", "\346\213\215\347\205\247", nullptr));
        pushButton_4->setText(QApplication::translate("GUICreator", "\347\211\271\345\276\201\345\200\274\346\232\202\345\255\230", nullptr));
        pushButton_5->setText(QApplication::translate("GUICreator", "\347\211\271\345\276\201\345\200\274\346\257\224\350\276\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUICreator: public Ui_GUICreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUICREATOR_H
