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

    void on_inputCode_textChanged();

    void on_actionTodo_triggered();

    void on_actionL_xico_triggered();

    void on_actionSint_tico_triggered();

    void on_actionSem_ntico_triggered();

private:
    Ui::MainWindow *ui;
    void showLexicalTable(std::vector<tablaSimbolo>&);
};
#endif // MAINWINDOW_H
