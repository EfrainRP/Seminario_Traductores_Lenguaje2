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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
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
    QAction *actionTodo;
    QAction *actionL_xico;
    QAction *actionSint_tico;
    QAction *actionSem_ntico;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *analizar;
    QPlainTextEdit *numberLine;
    QTextEdit *textSintatico;
    QPushButton *buttonSintatico;
    QLabel *labelTablaLexico;
    QPushButton *buttonLexico;
    QTextEdit *textSemantico;
    QTableView *TablaLexico;
    QLabel *labelinsertar;
    QPlainTextEdit *inputCode;
    QPushButton *buttonSemantico;
    QWidget *generador;
    QTextEdit *textGenerator;
    QMenuBar *menuBar;
    QMenu *menuGuardar;
    QMenu *menuAnalizar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(738, 632);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(738, 599));
        MainWindow->setSizeIncrement(QSize(1, 1));
        QPalette palette;
        QBrush brush(QColor(255, 170, 0, 255));
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
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush3(QColor(70, 70, 70, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(54, 54, 54, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
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
        actionTodo = new QAction(MainWindow);
        actionTodo->setObjectName("actionTodo");
        actionL_xico = new QAction(MainWindow);
        actionL_xico->setObjectName("actionL_xico");
        actionSint_tico = new QAction(MainWindow);
        actionSint_tico->setObjectName("actionSint_tico");
        actionSem_ntico = new QAction(MainWindow);
        actionSem_ntico->setObjectName("actionSem_ntico");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 741, 611));
        QPalette palette1;
        QBrush brush5(QColor(218, 218, 218, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(106, 106, 106, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(56, 56, 56, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush7);
        QBrush brush8(QColor(74, 74, 74, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush8);
        QBrush brush9(QColor(124, 124, 124, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        QBrush brush10(QColor(91, 91, 91, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush10);
        QBrush brush11(QColor(95, 95, 95, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        tabWidget->setPalette(palette1);
        analizar = new QWidget();
        analizar->setObjectName("analizar");
        numberLine = new QPlainTextEdit(analizar);
        numberLine->setObjectName("numberLine");
        numberLine->setEnabled(true);
        numberLine->setGeometry(QRect(20, 40, 31, 291));
        QFont font;
        font.setPointSize(12);
        numberLine->setFont(font);
        numberLine->setContextMenuPolicy(Qt::DefaultContextMenu);
        numberLine->setAcceptDrops(false);
        numberLine->setLineWidth(0);
        numberLine->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        numberLine->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        numberLine->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        numberLine->setUndoRedoEnabled(false);
        numberLine->setReadOnly(true);
        numberLine->setCursorWidth(0);
        numberLine->setTextInteractionFlags(Qt::TextSelectableByMouse);
        numberLine->setMaximumBlockCount(0);
        numberLine->setBackgroundVisible(true);
        numberLine->setCenterOnScroll(false);
        textSintatico = new QTextEdit(analizar);
        textSintatico->setObjectName("textSintatico");
        textSintatico->setEnabled(true);
        textSintatico->setGeometry(QRect(370, 40, 351, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Link, brush);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        QBrush brush12(QColor(255, 170, 0, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        textSintatico->setPalette(palette2);
        QFont font1;
        font1.setPointSize(11);
        textSintatico->setFont(font1);
        textSintatico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        textSintatico->setReadOnly(true);
        buttonSintatico = new QPushButton(analizar);
        buttonSintatico->setObjectName("buttonSintatico");
        buttonSintatico->setGeometry(QRect(370, 10, 81, 24));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush13(QColor(153, 153, 153, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush13);
        QBrush brush14(QColor(127, 127, 127, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(111, 111, 111, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(68, 68, 68, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush17(QColor(51, 51, 51, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        QBrush brush18(QColor(255, 255, 220, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush18);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush19(QColor(255, 255, 255, 127));
        brush19.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush19);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush19);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush20(QColor(102, 102, 102, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush21(QColor(51, 51, 51, 127));
        brush21.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush21);
#endif
        buttonSintatico->setPalette(palette3);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        buttonSintatico->setFont(font2);
        buttonSintatico->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        labelTablaLexico = new QLabel(analizar);
        labelTablaLexico->setObjectName("labelTablaLexico");
        labelTablaLexico->setGeometry(QRect(290, 340, 141, 20));
        labelTablaLexico->setFont(font2);
        buttonLexico = new QPushButton(analizar);
        buttonLexico->setObjectName("buttonLexico");
        buttonLexico->setGeometry(QRect(10, 340, 75, 24));
        QPalette palette4;
        QBrush brush22(QColor(15, 15, 15, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush22);
        QBrush brush23(QColor(59, 59, 59, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush23);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush23);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush22);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush22);
        QBrush brush24(QColor(47, 47, 47, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush24);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush23);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush23);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        buttonLexico->setPalette(palette4);
        buttonLexico->setFont(font2);
        buttonLexico->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 15, 15);"));
        textSemantico = new QTextEdit(analizar);
        textSemantico->setObjectName("textSemantico");
        textSemantico->setGeometry(QRect(370, 160, 351, 171));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Link, brush);
        palette5.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        textSemantico->setPalette(palette5);
        textSemantico->setFont(font1);
        textSemantico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        textSemantico->setReadOnly(true);
        TablaLexico = new QTableView(analizar);
        TablaLexico->setObjectName("TablaLexico");
        TablaLexico->setEnabled(true);
        TablaLexico->setGeometry(QRect(10, 370, 711, 201));
        TablaLexico->setMinimumSize(QSize(711, 201));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush25(QColor(71, 71, 71, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush25);
        QBrush brush26(QColor(255, 255, 255, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush26);
        QBrush brush27(QColor(77, 77, 77, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush27);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush28(QColor(72, 72, 72, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush28);
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        QBrush brush29(QColor(83, 83, 83, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush29);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush26);
        QBrush brush30(QColor(255, 255, 255, 128));
        brush30.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush30);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush25);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush26);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush27);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush28);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush29);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush26);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush30);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush25);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush26);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush27);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush28);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush28);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush29);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush26);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush30);
#endif
        TablaLexico->setPalette(palette6);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        TablaLexico->setFont(font3);
        TablaLexico->setLayoutDirection(Qt::LeftToRight);
        TablaLexico->setStyleSheet(QString::fromUtf8(""));
        TablaLexico->setFrameShadow(QFrame::Plain);
        TablaLexico->setLineWidth(2);
        TablaLexico->setMidLineWidth(2);
        TablaLexico->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TablaLexico->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TablaLexico->setAutoScrollMargin(2);
        TablaLexico->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TablaLexico->setAlternatingRowColors(true);
        TablaLexico->setTextElideMode(Qt::ElideMiddle);
        TablaLexico->setGridStyle(Qt::SolidLine);
        labelinsertar = new QLabel(analizar);
        labelinsertar->setObjectName("labelinsertar");
        labelinsertar->setGeometry(QRect(150, 10, 121, 20));
        labelinsertar->setFont(font2);
        inputCode = new QPlainTextEdit(analizar);
        inputCode->setObjectName("inputCode");
        inputCode->setGeometry(QRect(50, 40, 311, 291));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush31(QColor(0, 255, 0, 255));
        brush31.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush31);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush31);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        inputCode->setPalette(palette7);
        inputCode->setFont(font);
        inputCode->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        inputCode->setTabChangesFocus(true);
        inputCode->setCursorWidth(1);
        buttonSemantico = new QPushButton(analizar);
        buttonSemantico->setObjectName("buttonSemantico");
        buttonSemantico->setGeometry(QRect(370, 130, 91, 24));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush22);
        QBrush brush32(QColor(138, 138, 138, 255));
        brush32.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush32);
        QBrush brush33(QColor(112, 112, 112, 255));
        brush33.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush33);
        QBrush brush34(QColor(104, 104, 104, 255));
        brush34.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush34);
        QBrush brush35(QColor(63, 63, 63, 255));
        brush35.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush35);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush22);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush22);
        QBrush brush36(QColor(107, 107, 107, 255));
        brush36.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush36);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush22);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush32);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush33);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush34);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush35);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush22);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush36);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush32);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush33);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush34);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush35);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush36);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        buttonSemantico->setPalette(palette8);
        buttonSemantico->setFont(font2);
        buttonSemantico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"background-color: rgb(15, 15, 15);"));
        tabWidget->addTab(analizar, QString());
        generador = new QWidget();
        generador->setObjectName("generador");
        textGenerator = new QTextEdit(generador);
        textGenerator->setObjectName("textGenerator");
        textGenerator->setGeometry(QRect(20, 20, 691, 551));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush31);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Link, brush);
        palette9.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush31);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        textGenerator->setPalette(palette9);
        textGenerator->setFont(font1);
        textGenerator->setStyleSheet(QString::fromUtf8(""));
        textGenerator->setReadOnly(true);
        tabWidget->addTab(generador, QString());
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 738, 22));
        menuGuardar = new QMenu(menuBar);
        menuGuardar->setObjectName("menuGuardar");
        menuAnalizar = new QMenu(menuBar);
        menuAnalizar->setObjectName("menuAnalizar");
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(inputCode, buttonLexico);
        QWidget::setTabOrder(buttonLexico, textSintatico);
        QWidget::setTabOrder(textSintatico, TablaLexico);

        menuBar->addAction(menuGuardar->menuAction());
        menuBar->addAction(menuAnalizar->menuAction());
        menuGuardar->addAction(leer);
        menuGuardar->addAction(guardar);
        menuGuardar->addSeparator();
        menuGuardar->addAction(actionLimpiar);
        menuAnalizar->addAction(actionTodo);
        menuAnalizar->addSeparator();
        menuAnalizar->addAction(actionL_xico);
        menuAnalizar->addAction(actionSint_tico);
        menuAnalizar->addAction(actionSem_ntico);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
        actionTodo->setText(QCoreApplication::translate("MainWindow", "Todo", nullptr));
#if QT_CONFIG(shortcut)
        actionTodo->setShortcut(QCoreApplication::translate("MainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionL_xico->setText(QCoreApplication::translate("MainWindow", "L\303\251xico", nullptr));
#if QT_CONFIG(shortcut)
        actionL_xico->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSint_tico->setText(QCoreApplication::translate("MainWindow", "Sint\303\241tico", nullptr));
#if QT_CONFIG(shortcut)
        actionSint_tico->setShortcut(QCoreApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSem_ntico->setText(QCoreApplication::translate("MainWindow", "Sem\303\241ntico", nullptr));
#if QT_CONFIG(shortcut)
        actionSem_ntico->setShortcut(QCoreApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_CONFIG(shortcut)
        numberLine->setPlainText(QString());
        buttonSintatico->setText(QCoreApplication::translate("MainWindow", "Sintatico", nullptr));
        labelTablaLexico->setText(QCoreApplication::translate("MainWindow", "Tabla de Simbolos", nullptr));
        buttonLexico->setText(QCoreApplication::translate("MainWindow", "Lexico", nullptr));
#if QT_CONFIG(tooltip)
        TablaLexico->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        TablaLexico->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        labelinsertar->setText(QCoreApplication::translate("MainWindow", "Insertar Codigo", nullptr));
        buttonSemantico->setText(QCoreApplication::translate("MainWindow", "Semantico", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(analizar), QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(generador), QCoreApplication::translate("MainWindow", "Generador", nullptr));
        menuGuardar->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuAnalizar->setTitle(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
