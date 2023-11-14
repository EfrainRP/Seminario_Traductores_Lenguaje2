#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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
    QWidget *Analizar;
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
    QWidget *tab_2;
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
        tabWidget->setGeometry(QRect(0, 0, 721, 611));
        Analizar = new QWidget();
        Analizar->setObjectName("tab");
        numberLine = new QPlainTextEdit(Analizar);
        numberLine->setObjectName("numberLine");
        numberLine->setEnabled(true);
        numberLine->setGeometry(QRect(10, 40, 31, 291));
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
        textSintatico = new QTextEdit(Analizar);
        textSintatico->setObjectName("textSintatico");
        textSintatico->setEnabled(true);
        textSintatico->setGeometry(QRect(360, 40, 351, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(0, 255, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush5);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush5);
        QBrush brush6(QColor(255, 170, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        textSintatico->setPalette(palette1);
        QFont font1;
        font1.setPointSize(11);
        textSintatico->setFont(font1);
        textSintatico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        textSintatico->setReadOnly(true);
        buttonSintatico = new QPushButton(Analizar);
        buttonSintatico->setObjectName("buttonSintatico");
        buttonSintatico->setGeometry(QRect(360, 10, 81, 24));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush7(QColor(153, 153, 153, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush7);
        QBrush brush8(QColor(127, 127, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush8);
        QBrush brush9(QColor(111, 111, 111, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush9);
        QBrush brush10(QColor(68, 68, 68, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush11(QColor(51, 51, 51, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush12);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        QBrush brush13(QColor(255, 255, 255, 127));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush14(QColor(102, 102, 102, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        QBrush brush15(QColor(51, 51, 51, 127));
        brush15.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        buttonSintatico->setPalette(palette2);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        buttonSintatico->setFont(font2);
        buttonSintatico->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        labelTablaLexico = new QLabel(Analizar);
        labelTablaLexico->setObjectName("labelTablaLexico");
        labelTablaLexico->setGeometry(QRect(280, 340, 141, 20));
        labelTablaLexico->setFont(font2);
        buttonLexico = new QPushButton(Analizar);
        buttonLexico->setObjectName("buttonLexico");
        buttonLexico->setGeometry(QRect(0, 340, 75, 24));
        QPalette palette3;
        QBrush brush16(QColor(15, 15, 15, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush16);
        QBrush brush17(QColor(59, 59, 59, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush16);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush16);
        QBrush brush18(QColor(47, 47, 47, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush18);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        buttonLexico->setPalette(palette3);
        buttonLexico->setFont(font2);
        buttonLexico->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 15, 15);"));
        textSemantico = new QTextEdit(Analizar);
        textSemantico->setObjectName("textSemantico");
        textSemantico->setGeometry(QRect(360, 160, 351, 171));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Link, brush5);
        palette4.setBrush(QPalette::Active, QPalette::LinkVisited, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Link, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Link, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        textSemantico->setPalette(palette4);
        textSemantico->setFont(font1);
        textSemantico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        textSemantico->setReadOnly(true);
        TablaLexico = new QTableView(Analizar);
        TablaLexico->setObjectName("TablaLexico");
        TablaLexico->setEnabled(true);
        TablaLexico->setGeometry(QRect(0, 370, 711, 201));
        TablaLexico->setMinimumSize(QSize(711, 201));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush19(QColor(71, 71, 71, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush19);
        QBrush brush20(QColor(255, 255, 255, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush20);
        QBrush brush21(QColor(77, 77, 77, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush21);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush22(QColor(72, 72, 72, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush22);
        QBrush brush23(QColor(88, 88, 88, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush23);
        QBrush brush24(QColor(83, 83, 83, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush20);
        QBrush brush25(QColor(255, 255, 255, 128));
        brush25.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush25);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush20);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush21);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush23);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush20);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush19);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush20);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush23);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush20);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush25);
#endif
        TablaLexico->setPalette(palette5);
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
        labelinsertar = new QLabel(Analizar);
        labelinsertar->setObjectName("labelinsertar");
        labelinsertar->setGeometry(QRect(140, 10, 121, 20));
        labelinsertar->setFont(font2);
        inputCode = new QPlainTextEdit(Analizar);
        inputCode->setObjectName("inputCode");
        inputCode->setGeometry(QRect(40, 40, 311, 291));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        inputCode->setPalette(palette6);
        inputCode->setFont(font);
        inputCode->setCursorWidth(1);
        buttonSemantico = new QPushButton(Analizar);
        buttonSemantico->setObjectName("buttonSemantico");
        buttonSemantico->setGeometry(QRect(360, 130, 91, 24));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush16);
        QBrush brush26(QColor(138, 138, 138, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush26);
        QBrush brush27(QColor(112, 112, 112, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush27);
        QBrush brush28(QColor(104, 104, 104, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush28);
        QBrush brush29(QColor(63, 63, 63, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush29);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush16);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush16);
        QBrush brush30(QColor(107, 107, 107, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush30);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush27);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush28);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush29);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush30);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush27);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush28);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush30);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        buttonSemantico->setPalette(palette7);
        buttonSemantico->setFont(font2);
        buttonSemantico->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"background-color: rgb(15, 15, 15);"));
        tabWidget->addTab(Analizar, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
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
        tabWidget->setTabText(tabWidget->indexOf(Analizar), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menuGuardar->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuAnalizar->setTitle(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

