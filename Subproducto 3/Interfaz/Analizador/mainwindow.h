#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct tablaSimbolo{
    std::string lexema;
    std::string token;
    int tipo;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonLexico_clicked();

    void on_leer_triggered();

    void on_guardar_triggered();

    void on_buttonSintatico_clicked();

    void on_actionLimpiar_triggered();

    void on_buttonSemantico_clicked();

private:
    Ui::MainWindow *ui;
    //std::vector<tablaSimbolo> funcionLexico(QString);
};
#endif // MAINWINDOW_H
