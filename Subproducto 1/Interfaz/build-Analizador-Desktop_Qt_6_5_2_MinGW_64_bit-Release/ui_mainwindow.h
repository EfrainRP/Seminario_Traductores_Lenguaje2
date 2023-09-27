/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *TablaLexico;
    QPushButton *analizar;
    QTextEdit *inputCode;
    QTextEdit *textEdit_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TablaLexico = new QTableView(centralwidget);
        TablaLexico->setObjectName("TablaLexico");
        TablaLexico->setGeometry(QRect(20, 320, 761, 251));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        TablaLexico->setFont(font);
        TablaLexico->setLayoutDirection(Qt::LeftToRight);
        TablaLexico->setFrameShadow(QFrame::Plain);
        TablaLexico->setLineWidth(2);
        TablaLexico->setMidLineWidth(2);
        TablaLexico->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TablaLexico->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TablaLexico->setAlternatingRowColors(true);
        TablaLexico->setTextElideMode(Qt::ElideMiddle);
        analizar = new QPushButton(centralwidget);
        analizar->setObjectName("analizar");
        analizar->setGeometry(QRect(360, 30, 75, 24));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        analizar->setFont(font1);
        inputCode = new QTextEdit(centralwidget);
        inputCode->setObjectName("inputCode");
        inputCode->setGeometry(QRect(20, 10, 331, 291));
        QFont font2;
        font2.setPointSize(12);
        inputCode->setFont(font2);
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(450, 10, 331, 291));
        textEdit_2->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(inputCode, analizar);
        QWidget::setTabOrder(analizar, textEdit_2);
        QWidget::setTabOrder(textEdit_2, TablaLexico);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        TablaLexico->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        TablaLexico->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        analizar->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
