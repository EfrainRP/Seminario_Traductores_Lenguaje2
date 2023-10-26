#include "mainwindow.h"

using namespace std;

///Lexical Analyzer
vector<tablaSimbolo> funcionLexico(QString cadena0)
{
    vector<tablaSimbolo> TablaSimbolo;

    int state = 1;
    int index = 0;
    tablaSimbolo var;
    string cadena = cadena0.toStdString() + "$";

    ///Automata finito
    while ((index <= (cadena.length() - 1)) && state == 1) {  //Mientras no sea el fin de la cadena y el estado = 1
        var.lexema = "";
        var.token = "Unidentified";
        var.tipo = -1;

        while ((index <= (cadena.length() - 1)) && state != 0) { //Mientras no sea el fin de la cadena y el estado sea distinto del ultimo
            if (state == 1) {
                if (isspace(cadena[index])) {    //Evalua si el caracter contiene un espacio en blanco
                    state = 1;
                } else if (isalpha(cadena[index]) || cadena[index] == '_') { //Evalua si el caracter es una letra o "_"
                    state = 2;
                    var.lexema += cadena[index];
                    var.token = "Identifier";
                    var.tipo = 0;
                }
                else if (isdigit(cadena[index])) { //Evalua si el caracter es un digito \d
                    state = 4;
                    var.lexema += cadena[index];
                    var.token = "Integer";
                    var.tipo = 1;
                }
                else if (cadena[index] == '%') { //Evalua si el caracter es "%"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "ModuleOpe";
                    var.tipo = 12;
                }
                else if (cadena[index] == '+' || cadena[index] == '-') { //Evalua si el caracter es "+" o "-"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "AdditionOp";
                    var.tipo = 4;
                }
                else if (cadena[index] == '*' || cadena[index] == '/') { //Evalua si el caracter es "*" o "/"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "MultiplOp";
                    var.tipo = 5;
                }
                else if (cadena[index] == '<' || cadena[index] == '>') { //Evalua si el caracter es "<" o ">"
                    state = 3;
                    var.lexema += cadena[index];
                    var.token = "RelationalOp";
                    var.tipo = 6;
                }
                else if (cadena[index] == '|') { //Evalua si el caracter es "|"
                    state = 5;
                    var.lexema += cadena[index];
                }
                else if (cadena[index] == '&') { //Evalua si el caracter es "|"
                    state = 6;
                    var.lexema += cadena[index];
                }
                else if (cadena[index] == '\"') { //Evalua si el caracter es "|"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "Comilla";
                }
                else if (cadena[index] == '!') { //Evalua si el caracter es "!"
                    state = 7;
                    var.lexema += cadena[index];
                    var.token = "opNOT";
                    var.tipo = 9;
                }
                else if (cadena[index] == ',') { //Evalua si el caracter es ","
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "Comma";
                    var.tipo = 14;
                }
                else if (cadena[index] == ';') { //Evalua si el caracter es ";"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "Semicolon";
                    var.tipo = 13;
                }
                else if (cadena[index] == ':') { //Evalua si el caracter es ":"
                    state = 0;
                    var.lexema += cadena[index];
                    var.tipo = 11;
                    var.token = "TwoPoints";
                }
                else if (cadena[index] == '(') { //Evalua si el caracter es "("
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "LeftParent";
                    var.tipo = 15;
                }
                else if (cadena[index] == ')') { //Evalua si el caracter es ")"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "RightParent";
                    var.tipo = 16;
                }
                else if (cadena[index] == '{') { //Evalua si el caracter es "{"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "LeftKey";
                    var.tipo = 17;
                }
                else if (cadena[index] == '}') { //Evalua si el caracter es "}"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "RightKey";
                    var.tipo = 18;
                }
                else if (cadena[index] == '[') { //Evalua si el caracter es "["
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "LeftBrack";
                    var.tipo = 19;
                }
                else if (cadena[index] == ']') { //Evalua si el caracter es "]"
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "RightBrack";
                    var.tipo = 20;
                }
                else if (cadena[index] == '$') {    //Evalua si el caracter contiene $
                    state = 0;
                    var.lexema += cadena[index];
                    var.token = "End";
                    var.tipo = 38;
                } else if (cadena[index] == '=') {   //Evalua si el caracter es "="
                    var.lexema += cadena[index];
                    var.token = "Assignment";
                    state = 7;
                    var.tipo = 21;
                } else if (cadena[index] == '.') {   //Evalua si el caracter es "."
                    var.lexema += cadena[index];
                    state = 8;
                } else {                             //Si no encuentra alguna coincidencia, el lexema no es reconocido.
                    state = 0;
                    var.token = "Unidentified";
                    var.lexema = cadena[index];
                }
                index++;
            } else if (state == 2) {                //Evalua si el estado es 2
                if (isdigit(cadena[index]) || isalpha(cadena[index]) || cadena[index] == '_') { //Evalua si el caracter contiene \w o "_"
                    state = 2;
                    var.lexema += cadena[index];
                    var.token = "Identifier";
                    var.tipo = 0;
                    index++;
                } else {
                    state = 0;                    //Sino, continua evaluando
                }
            } else if (state == 3) {             //Evalua si el estado es 3
                if (cadena[index] == '=') {      //Evalua si el caracter es el OpRelacional "==, <=, >=, !="
                    var.lexema += cadena[index];
                    var.token = "RelationalOp";
                    var.tipo = 6;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if(state == 4){              //Evalua si el estado es 3
                if (isdigit(cadena[index])) {      //Evalua si es otro numero
                    var.lexema += cadena[index];
                    //token = "Integer";
                    state = 4;
                    var.tipo = 1;
                    index++;
                } else if (cadena[index] == '.'){    //Si es un punto
                    var.lexema += cadena[index];
                    state = 8;
                    var.tipo = 2;
                    index++;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 5) {             //Evalua si el estado es 5
                if (cadena[index] == '|') {      //Evalua si el caracter es "|"
                    var.lexema += cadena[index];
                    var.token = "opOR";
                    var.tipo = 7;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 6) {             //Evalua si el estado es 6
                if (cadena[index] == '&') {      //Evalua si el caracter es "&"
                    var.lexema += cadena[index];
                    var.token = "opAND";
                    var.tipo = 8;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 7) {             //Evalua si el estado es 7
                if (cadena[index] == '=') {      //Evalua si se completa el "== !="
                    var.lexema += cadena[index];
                    var.token = "opIgualdad";
                    var.tipo = 10;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 8) {             //Evalua si el estado es 8
                if (isdigit(cadena[index])) {      //Evalua si es numero real
                    var.lexema += cadena[index];
                    var.token = "Real";
                    var.tipo = 2;
                    state = 8;
                    index++;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            }
        }
        state = 1;

        TablaSimbolo.push_back(var);    ///Tabla de simbolos

    }

    //Identifica las palabras reservadas y tipos de datos
    for(size_t i(0); i < TablaSimbolo.size(); ++i)
    {
        if (TablaSimbolo[i].lexema.find("elif") != string::npos && TablaSimbolo[i].lexema.length() == 4){
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "sinsi";
            TablaSimbolo[i].tipo = 23;
        }
        else if (TablaSimbolo[i].lexema.find("else") != string::npos && TablaSimbolo[i].lexema.length() == 4) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "sino";
            TablaSimbolo[i].tipo = 24;
        }
        else if (TablaSimbolo[i].lexema.find("if") != string::npos && TablaSimbolo[i].lexema.length() == 2) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "si";
            TablaSimbolo[i].tipo = 22;
        }
        else if (TablaSimbolo[i].lexema.find("while") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "mientras";
            TablaSimbolo[i].tipo = 25;
        }
        else if (TablaSimbolo[i].lexema.find("def") != string::npos&& TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "definir";
            TablaSimbolo[i].tipo = 34;
        }
        else if (TablaSimbolo[i].lexema.find("for") != string::npos && TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "para";
            TablaSimbolo[i].tipo = 26;
        }
        else if (TablaSimbolo[i].lexema.find("range") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "rango";
            TablaSimbolo[i].tipo = 35;
        }
        else if (TablaSimbolo[i].lexema.find("break") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "romper";
            TablaSimbolo[i].tipo = 28;
        }
        else if (TablaSimbolo[i].lexema.find("continue") != string::npos && TablaSimbolo[i].lexema.length() == 8) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "continuar";
            TablaSimbolo[i].tipo = 33;
        }
        else if (TablaSimbolo[i].lexema.find("global") != string::npos && TablaSimbolo[i].lexema.length() == 6) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "global";
            TablaSimbolo[i].tipo = 30;
        }
        else if (TablaSimbolo[i].lexema.find("not") != string::npos && TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "no";
            TablaSimbolo[i].tipo = 9;
        }
        else if (TablaSimbolo[i].lexema.find("and") != string::npos && TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "ademas";
            TablaSimbolo[i].tipo = 8;
        }
        else if (TablaSimbolo[i].lexema.find("or") != string::npos && TablaSimbolo[i].lexema.length() == 2) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "alternativa";
            TablaSimbolo[i].tipo = 7;
        }
        else if (TablaSimbolo[i].lexema.find("True") != string::npos && TablaSimbolo[i].lexema.length() == 4) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "Verdadero";
            TablaSimbolo[i].tipo = 36;
        }
        else if (TablaSimbolo[i].lexema.find("False") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "Falso";
            TablaSimbolo[i].tipo = 37;
        }
        else if (TablaSimbolo[i].lexema.find("print") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "imprimir";
            TablaSimbolo[i].tipo = 32;
        }
        else if (TablaSimbolo[i].lexema.find("input") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "entrada";
            TablaSimbolo[i].tipo = 31;
        }
        else if (TablaSimbolo[i].lexema.find("return") != string::npos && TablaSimbolo[i].lexema.length() == 6) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "retorno";
            TablaSimbolo[i].tipo = 27;
        }
        else if (TablaSimbolo[i].lexema.find("int") != string::npos && TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Data type";
            TablaSimbolo[i].lexema = "entero";
            TablaSimbolo[i].tipo = 3;
        }
        else if (TablaSimbolo[i].lexema.find("in") != string::npos && TablaSimbolo[i].lexema.length() == 2) {
            TablaSimbolo[i].token = "Reserved word";
            TablaSimbolo[i].lexema = "en";
            TablaSimbolo[i].tipo = 29;
        }
        else if (TablaSimbolo[i].lexema.find("float") != string::npos && TablaSimbolo[i].lexema.length() == 5) {
            TablaSimbolo[i].token = "Data type";
            TablaSimbolo[i].lexema = "flotante";
            TablaSimbolo[i].tipo = 3;
        }
        else if (TablaSimbolo[i].lexema.find("str") != string::npos && TablaSimbolo[i].lexema.length() == 3) {
            TablaSimbolo[i].token = "Data type";
            TablaSimbolo[i].lexema = "cadena";
            TablaSimbolo[i].tipo = 3;
        }
        else if (TablaSimbolo[i].lexema.find("bool") != string::npos && TablaSimbolo[i].lexema.length() == 4) {
            TablaSimbolo[i].token = "Data type";
            TablaSimbolo[i].lexema = "booleano";
            TablaSimbolo[i].tipo = 3;
        }
    }

    return TablaSimbolo; ///Tabla de Simbolo
}
