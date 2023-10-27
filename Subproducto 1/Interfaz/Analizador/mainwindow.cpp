#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <string.h>
#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_analizar_clicked()
{
    QString cadena0 = ui->inputCode->toPlainText();
    ui->textEdit_2->clear();
    vector<string> lexemas;
    vector<string> tokens;
    vector<int> tipo;
    int state = 1;
    int index = 0;
    int intTipo = -1;

    string cadena = cadena0.toStdString() + "$";

    ///Automata finito
    while ((index <= (cadena.length() - 1)) && state == 1) {  //Mientras no sea el fin de la cadena y el estado = 1
        string lexema = "";                                 //Inicialmente el lexema no es reconocido
        string token = "Unidentified";

        while ((index <= (cadena.length() - 1)) && state != 0) { //Mientras no sea el fin de la cadena y el estado sea distinto del ultimo
            if (state == 1) {
                if (isspace(cadena[index])) {    //Evalua si el caracter contiene un espacio en blanco
                    state = 1;
                } else if (isalpha(cadena[index]) || cadena[index] == '_') { //Evalua si el caracter es una letra o "_"
                    state = 2;
                    lexema += cadena[index];
                    token = "Identifier";
                    intTipo = 0;
                }
                else if (isdigit(cadena[index])) { //Evalua si el caracter es un digito \d
                    state = 4;
                    lexema += cadena[index];
                    token = "Integer";
                    intTipo = 1;
                }
                else if (cadena[index] == '%') { //Evalua si el caracter es "%"
                    state = 0;
                    lexema += cadena[index];
                    token = "ModuleOpe";
                    intTipo = 12;
                }
                else if (cadena[index] == '+' || cadena[index] == '-') { //Evalua si el caracter es "+" o "-"
                    state = 0;
                    lexema += cadena[index];
                    token = "AdditionOp";
                    intTipo = 4;
                }
                else if (cadena[index] == '*' || cadena[index] == '/') { //Evalua si el caracter es "*" o "/"
                    state = 0;
                    lexema += cadena[index];
                    token = "MultiplOp";
                    intTipo = 5;
                }
                else if (cadena[index] == '<' || cadena[index] == '>') { //Evalua si el caracter es "<" o ">"
                    state = 3;
                    lexema += cadena[index];
                    token = "RelationalOp";
                    intTipo = 6;
                }
                else if (cadena[index] == '|') { //Evalua si el caracter es "|"
                    state = 5;
                    lexema += cadena[index];
                }
                else if (cadena[index] == '&') { //Evalua si el caracter es "|"
                    state = 6;
                    lexema += cadena[index];
                }
                else if (cadena[index] == '!') { //Evalua si el caracter es "!"
                    state = 7;
                    lexema += cadena[index];
                    token = "opNOT";
                    intTipo = 9;
                }
                else if (cadena[index] == ',') { //Evalua si el caracter es ","
                    state = 0;
                    lexema += cadena[index];
                    token = "Comma";
                    intTipo = 14;
                }
                else if (cadena[index] == ';') { //Evalua si el caracter es ";"
                    state = 0;
                    lexema += cadena[index];
                    token = "Semicolon";
                    intTipo = 13;
                }
                else if (cadena[index] == ':') { //Evalua si el caracter es ":"
                    state = 0;
                    lexema += cadena[index];
                    intTipo = 11;
                    token = "TwoPoints";
                }
                else if (cadena[index] == '(') { //Evalua si el caracter es "("
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftParent";
                    intTipo = 15;
                }
                else if (cadena[index] == ')') { //Evalua si el caracter es ")"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightParent";
                    intTipo = 16;
                }
                else if (cadena[index] == '{') { //Evalua si el caracter es "{"
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftKey";
                    intTipo = 17;
                }
                else if (cadena[index] == '}') { //Evalua si el caracter es "}"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightKey";
                    intTipo = 18;
                }
                else if (cadena[index] == '[') { //Evalua si el caracter es "["
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftBrack";
                    intTipo = 19;
                }
                else if (cadena[index] == ']') { //Evalua si el caracter es "]"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightBrack";
                    intTipo = 20;
                }
                else if (cadena[index] == '$') {    //Evalua si el caracter contiene $
                    state = 0;
                    lexema += cadena[index];
                    token = "End";
                    intTipo = 38;
                } else if (cadena[index] == '=') {   //Evalua si el caracter es "="
                    lexema += cadena[index];
                    token = "Assignment";
                    state = 7;
                    intTipo = 21;
                } else if (cadena[index] == '.') {   //Evalua si el caracter es "."
                    lexema += cadena[index];
                    state = 8;
                } else {                             //Si no encuentra alguna coincidencia, el lexema no es reconocido.
                    state = 0;
                    token = "Unidentified";
                    lexema = cadena[index];
                }
                index++;
            } else if (state == 2) {                //Evalua si el estado es 2
                if (isdigit(cadena[index]) || isalpha(cadena[index]) || cadena[index] == '_') { //Evalua si el caracter contiene \w o "_"
                    state = 2;
                    lexema += cadena[index];
                    token = "Identifier";
                    intTipo = 0;
                    index++;
                } else {
                    state = 0;                    //Sino, continua evaluando
                }
            } else if (state == 3) {             //Evalua si el estado es 3
                if (cadena[index] == '=') {      //Evalua si el caracter es el OpRelacional "==, <=, >=, !="
                    lexema += cadena[index];
                    token = "RelationalOp";
                    intTipo = 6;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if(state == 4){              //Evalua si el estado es 3
                if (isdigit(cadena[index])) {      //Evalua si es otro numero
                    lexema += cadena[index];
                    //token = "Integer";
                    state = 4;
                    intTipo = 1;
                    index++;
                } else if (cadena[index] == '.'){    //Si es un punto
                    lexema += cadena[index];
                    state = 8;
                    intTipo = 2;
                    index++;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 5) {             //Evalua si el estado es 5
                if (cadena[index] == '|') {      //Evalua si el caracter es "|"
                    lexema += cadena[index];
                    token = "opOR";
                    intTipo = 7;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 6) {             //Evalua si el estado es 6
                if (cadena[index] == '&') {      //Evalua si el caracter es "&"
                    lexema += cadena[index];
                    token = "opAND";
                    intTipo = 8;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 7) {             //Evalua si el estado es 7
                if (cadena[index] == '=') {      //Evalua si se completa el "== !="
                    lexema += cadena[index];
                    token = "opIgualdad";
                    intTipo = 10;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 8) {             //Evalua si el estado es 8
                if (isdigit(cadena[index])) {      //Evalua si es numero real
                    lexema += cadena[index];
                    token = "Real";
                    intTipo = 2;
                    state = 8;
                    index++;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            }
        }
        state = 1;

        //elements.push_back("" + token + "\t\t\t" + lexema);
        tokens.push_back(token);                 //Tokens vector
        lexemas.push_back(lexema);               //Lexemes vector
        tipo.push_back(intTipo);                 //Tipo vector
    }

    ///Tabla de simbolos
    //Identifica las palabras reservadas y tipos de datos
    for(size_t i(0); i < lexemas.size(); ++i)
    {
        if (lexemas[i].find("elif") != string::npos && lexemas[i].length() == 4){
            tokens[i] = "Reserved word";
            lexemas[i] = "sinsi";
            tipo[i] = 23;
        }
        else if (lexemas[i].find("else") != string::npos && lexemas[i].length() == 4) {
            tokens[i] = "Reserved word";
            lexemas[i] = "sino";
            tipo[i] = 24;
        }
        else if (lexemas[i].find("if") != string::npos && lexemas[i].length() == 2) {
            tokens[i] = "Reserved word";
            lexemas[i] = "si";
            tipo[i] = 22;
        }
        else if (lexemas[i].find("while") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "mientras";
            tipo[i] = 25;
        }
        else if (lexemas[i].find("def") != string::npos&& lexemas[i].length() == 3) {
            tokens[i] = "Reserved word";
            lexemas[i] = "definir";
            tipo[i] = 34;
        }
        else if (lexemas[i].find("for") != string::npos && lexemas[i].length() == 3) {
            tokens[i] = "Reserved word";
            lexemas[i] = "para";
            tipo[i] = 26;
        }
        else if (lexemas[i].find("range") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "rango";
            tipo[i] = 35;
        }
        else if (lexemas[i].find("break") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "romper";
            tipo[i] = 28;
        }
        else if (lexemas[i].find("continue") != string::npos && lexemas[i].length() == 8) {
            tokens[i] = "Reserved word";
            lexemas[i] = "continuar";
            tipo[i] = 33;
        }
        else if (lexemas[i].find("global") != string::npos && lexemas[i].length() == 6) {
            tokens[i] = "Reserved word";
            lexemas[i] = "global";
            tipo[i] = 30;
        }
        else if (lexemas[i].find("not") != string::npos && lexemas[i].length() == 3) {
            tokens[i] = "Reserved word";
            lexemas[i] = "no";
            tipo[i] = 9;
        }
        else if (lexemas[i].find("and") != string::npos && lexemas[i].length() == 3) {
            tokens[i] = "Reserved word";
            lexemas[i] = "ademas";
            tipo[i] = 8;
        }
        else if (lexemas[i].find("or") != string::npos && lexemas[i].length() == 2) {
            tokens[i] = "Reserved word";
            lexemas[i] = "alternativa";
            tipo[i] = 7;
        }
        else if (lexemas[i].find("True") != string::npos && lexemas[i].length() == 4) {
            tokens[i] = "Reserved word";
            lexemas[i] = "Verdadero";
            tipo[i] = 36;
        }
        else if (lexemas[i].find("False") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "Falso";
            tipo[i] = 37;
        }
        else if (lexemas[i].find("print") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "imprimir";
            tipo[i] = 32;
        }
        else if (lexemas[i].find("input") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Reserved word";
            lexemas[i] = "entrada";
            tipo[i] = 31;
        }
        else if (lexemas[i].find("return") != string::npos && lexemas[i].length() == 6) {
            tokens[i] = "Reserved word";
            lexemas[i] = "retorno";
            tipo[i] = 27;
        }
        else if (lexemas[i].find("int") != string::npos && lexemas[i].length() == 3) {
            tokens[i] = "Data type";
            lexemas[i] = "entero";
            tipo[i] = 3;
        }
        else if (lexemas[i].find("in") != string::npos && lexemas[i].length() == 2) {
            tokens[i] = "Reserved word";
            lexemas[i] = "en";
            tipo[i] = 29;
        }
        else if (lexemas[i].find("float") != string::npos && lexemas[i].length() == 5) {
            tokens[i] = "Data type";
            lexemas[i] = "flotante";
            tipo[i] = 3;
        }
        else if (lexemas[i].find("str") != string::npos && lexemas[i].length() == 3) {
            tokens[i] = "Data type";
            lexemas[i] = "cadena";
            tipo[i] = 3;
        }
        else if (lexemas[i].find("bool") != string::npos && lexemas[i].length() == 4) {
            tokens[i] = "Data type";
            lexemas[i] = "booleano";
            tipo[i] = 3;
        }

        tokens[i].resize(20,' ');
        lexemas[i].resize(15, ' ');
        //cout <<"Token: "<<tokens[i];
        //cout <<"Lexema: "<<lexemas[i];
        //cout << "Type: "<<to_string(tipo[i])<<endl;

    }

    ///Mostreo en la interfaz
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels(QStringList() << "Lexema" << "Token" << "Tipo");
    QFont headerFont = model->horizontalHeaderItem(0)->font();  // Obtén la fuente actual de la cabecera
    headerFont.setBold(true);  // Establece la fuente en negritas
    model->horizontalHeaderItem(0)->setFont(headerFont);
    model->horizontalHeaderItem(1)->setFont(headerFont);
    model->horizontalHeaderItem(2)->setFont(headerFont);

    int countlexema = lexemas.size();
    int rowCount= 0;
    //for(int row = countlexema;row<model->rowCount();row++){//Elimina las filas sobrantes del lexemas
        //rowCount = model->removeRow(countlexema);
    //}
    for (int row = 0; row < countlexema; row++) {
        rowCount = model->rowCount();
        if (rowCount<=row){
            model->insertRow(rowCount);

            QStandardItem *itemLex = new QStandardItem(QString::fromStdString(lexemas[row]));
            itemLex->setTextAlignment(Qt::AlignCenter);
            model->setItem(row,0,itemLex);

            QStandardItem *itemTok = new QStandardItem(QString::fromStdString(tokens[row]));
            itemTok->setTextAlignment(Qt::AlignCenter);
            model->setItem(row,1,itemTok);

            QStandardItem *itemT = new QStandardItem(QString::fromStdString(to_string(tipo[row])));
            itemT->setTextAlignment(Qt::AlignCenter);
            model->setItem(row,2,itemT);
        }/*else{
            QStandardItem *itemLex = new QStandardItem(QString::fromStdString(lexemas[row]));
            model->setItem(row,0,itemLex);
            QStandardItem *itemTok = new QStandardItem(QString::fromStdString(tokens[row]));
            model->setItem(row,1,itemTok);
            QStandardItem *itemT = new QStandardItem(tipo[row]);
            model->setItem(row,2,itemT);
        }*/

    }

    ui->TablaLexico->setModel(model);
    //ui->TablaLexico->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");
    ui->TablaLexico->setColumnWidth(0,242);
    ui->TablaLexico->setColumnWidth(1,262);
    ui->TablaLexico->setColumnWidth(2,238);

}

