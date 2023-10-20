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
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *leer;
    QAction *guardar;
    QWidget *centralwidget;
    QTableView *TablaLexico;
    QPushButton *buttonLexico;
    QTextEdit *inputCode;
    QTextEdit *textSintatico;
    QTextEdit *textSemantico;
    QLabel *labelTablaLexico;
    QLabel *labelinsertar;
    QPushButton *buttonSintatico;
    QPushButton *buttonSemantico;
    QMenuBar *menuBar;
    QMenu *menuGuardar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 599);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/compilador.png"), QSize(), QIcon::Active, QIcon::On);
        MainWindow->setWindowIcon(icon);
        leer = new QAction(MainWindow);
        leer->setObjectName("leer");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/read.png"), QSize(), QIcon::Normal, QIcon::Off);
        leer->setIcon(icon1);
        guardar = new QAction(MainWindow);
        guardar->setObjectName("guardar");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        guardar->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TablaLexico = new QTableView(centralwidget);
        TablaLexico->setObjectName("TablaLexico");
        TablaLexico->setGeometry(QRect(10, 370, 681, 201));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TablaLexico->sizePolicy().hasHeightForWidth());
        TablaLexico->setSizePolicy(sizePolicy);
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
        TablaLexico->setShowGrid(false);
        TablaLexico->setGridStyle(Qt::SolidLine);
        buttonLexico = new QPushButton(centralwidget);
        buttonLexico->setObjectName("buttonLexico");
        buttonLexico->setGeometry(QRect(10, 340, 75, 24));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        buttonLexico->setFont(font1);
        inputCode = new QTextEdit(centralwidget);
        inputCode->setObjectName("inputCode");
        inputCode->setGeometry(QRect(10, 40, 331, 291));
        QFont font2;
        font2.setPointSize(12);
        inputCode->setFont(font2);
        inputCode->setTabChangesFocus(true);
        textSintatico = new QTextEdit(centralwidget);
        textSintatico->setObjectName("textSintatico");
        textSintatico->setEnabled(true);
        textSintatico->setGeometry(QRect(360, 40, 331, 81));
        QFont font3;
        font3.setPointSize(11);
        textSintatico->setFont(font3);
        textSintatico->setReadOnly(true);
        textSemantico = new QTextEdit(centralwidget);
        textSemantico->setObjectName("textSemantico");
        textSemantico->setGeometry(QRect(360, 160, 331, 171));
        textSemantico->setFont(font3);
        textSemantico->setReadOnly(true);
        labelTablaLexico = new QLabel(centralwidget);
        labelTablaLexico->setObjectName("labelTablaLexico");
        labelTablaLexico->setGeometry(QRect(280, 340, 141, 20));
        labelTablaLexico->setFont(font1);
        labelinsertar = new QLabel(centralwidget);
        labelinsertar->setObjectName("labelinsertar");
        labelinsertar->setGeometry(QRect(110, 10, 121, 20));
        labelinsertar->setFont(font1);
        buttonSintatico = new QPushButton(centralwidget);
        buttonSintatico->setObjectName("buttonSintatico");
        buttonSintatico->setGeometry(QRect(360, 10, 81, 24));
        buttonSintatico->setFont(font1);
        buttonSemantico = new QPushButton(centralwidget);
        buttonSemantico->setObjectName("buttonSemantico");
        buttonSemantico->setGeometry(QRect(360, 130, 91, 24));
        buttonSemantico->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        menuGuardar = new QMenu(menuBar);
        menuGuardar->setObjectName("menuGuardar");
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(inputCode, buttonLexico);
        QWidget::setTabOrder(buttonLexico, textSintatico);
        QWidget::setTabOrder(textSintatico, TablaLexico);

        menuBar->addAction(menuGuardar->menuAction());
        menuGuardar->addAction(leer);
        menuGuardar->addAction(guardar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        leer->setText(QCoreApplication::translate("MainWindow", "Leer", nullptr));
#if QT_CONFIG(shortcut)
        leer->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
#if QT_CONFIG(shortcut)
        guardar->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        TablaLexico->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        TablaLexico->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        buttonLexico->setText(QCoreApplication::translate("MainWindow", "Lexico", nullptr));
        labelTablaLexico->setText(QCoreApplication::translate("MainWindow", "Tabla de Simbolos", nullptr));
        labelinsertar->setText(QCoreApplication::translate("MainWindow", "Insertar Codigo", nullptr));
        buttonSintatico->setText(QCoreApplication::translate("MainWindow", "Sintatico", nullptr));
        buttonSemantico->setText(QCoreApplication::translate("MainWindow", "Semantico", nullptr));
        menuGuardar->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
