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
    QAction *actionLimpiar;
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
        QPalette palette;
        QBrush brush(QColor(212, 212, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(62, 62, 62, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush3(QColor(170, 170, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(70, 70, 70, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(54, 54, 54, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush6(QColor(170, 170, 127, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        MainWindow->setPalette(palette);
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
        actionLimpiar = new QAction(MainWindow);
        actionLimpiar->setObjectName("actionLimpiar");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/limpiar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLimpiar->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TablaLexico = new QTableView(centralwidget);
        TablaLexico->setObjectName("TablaLexico");
        TablaLexico->setEnabled(true);
        TablaLexico->setGeometry(QRect(10, 370, 681, 201));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TablaLexico->sizePolicy().hasHeightForWidth());
        TablaLexico->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush7(QColor(71, 71, 71, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(94, 94, 94, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(77, 77, 77, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush10(QColor(0, 255, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush11(QColor(72, 72, 72, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush11);
        QBrush brush12(QColor(88, 88, 88, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush12);
        QBrush brush13(QColor(58, 58, 58, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        TablaLexico->setPalette(palette1);
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
        QPalette palette2;
        QBrush brush14(QColor(15, 15, 15, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush14);
        QBrush brush15(QColor(59, 59, 59, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush14);
        QBrush brush16(QColor(47, 47, 47, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush16);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        buttonLexico->setPalette(palette2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        buttonLexico->setFont(font1);
        buttonLexico->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 15, 15);"));
        inputCode = new QTextEdit(centralwidget);
        inputCode->setObjectName("inputCode");
        inputCode->setGeometry(QRect(10, 40, 311, 291));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        inputCode->setPalette(palette3);
        QFont font2;
        font2.setPointSize(12);
        inputCode->setFont(font2);
        inputCode->setTabChangesFocus(true);
        textSintatico = new QTextEdit(centralwidget);
        textSintatico->setObjectName("textSintatico");
        textSintatico->setEnabled(true);
        textSintatico->setGeometry(QRect(340, 40, 351, 81));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        textSintatico->setPalette(palette4);
        QFont font3;
        font3.setPointSize(11);
        textSintatico->setFont(font3);
        textSintatico->setReadOnly(true);
        textSemantico = new QTextEdit(centralwidget);
        textSemantico->setObjectName("textSemantico");
        textSemantico->setGeometry(QRect(340, 160, 351, 171));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        textSemantico->setPalette(palette5);
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
        buttonSintatico->setGeometry(QRect(340, 10, 81, 24));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush17(QColor(153, 153, 153, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush17);
        QBrush brush18(QColor(127, 127, 127, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush18);
        QBrush brush19(QColor(111, 111, 111, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush19);
        QBrush brush20(QColor(68, 68, 68, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush21(QColor(102, 102, 102, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush22(QColor(51, 51, 51, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        QBrush brush23(QColor(255, 255, 220, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush23);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush24(QColor(255, 255, 255, 127));
        brush24.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush17);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush18);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush19);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush23);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush24);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush17);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush18);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush20);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush19);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush23);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush25(QColor(51, 51, 51, 127));
        brush25.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush25);
#endif
        buttonSintatico->setPalette(palette6);
        buttonSintatico->setFont(font1);
        buttonSintatico->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        buttonSemantico = new QPushButton(centralwidget);
        buttonSemantico->setObjectName("buttonSemantico");
        buttonSemantico->setGeometry(QRect(340, 130, 91, 24));
        QPalette palette7;
        QBrush brush26(QColor(202, 202, 0, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush26);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush14);
        QBrush brush27(QColor(138, 138, 138, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush27);
        QBrush brush28(QColor(112, 112, 112, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush28);
        QBrush brush29(QColor(104, 104, 104, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush29);
        QBrush brush30(QColor(63, 63, 63, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush26);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush26);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush14);
        QBrush brush31(QColor(107, 107, 107, 255));
        brush31.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush31);
        QBrush brush32(QColor(202, 202, 0, 128));
        brush32.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush32);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush27);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush28);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush29);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush31);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush32);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush27);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush28);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush31);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush32);
#endif
        buttonSemantico->setPalette(palette7);
        buttonSemantico->setFont(font1);
        buttonSemantico->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 15, 15);\n"
"color: rgb(202, 202, 0);"));
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
        menuGuardar->addSeparator();
        menuGuardar->addAction(actionLimpiar);

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
        actionLimpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
#if QT_CONFIG(shortcut)
        actionLimpiar->setShortcut(QCoreApplication::translate("MainWindow", "F3", nullptr));
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
