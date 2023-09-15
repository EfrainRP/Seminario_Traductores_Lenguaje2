#include <iostream>
#include <string>
#include <vector>
//Lexical Analyzer
using namespace std;

int main() {
    string cadena0 = " ,int invar var_2!!= >=<><= 1234243=== breakif else while and elif return*/+-%[]{}():strbool global";
    //vector<string> elements;
    vector<string> lexemas;
    vector<string> tokens;
    int state = 1;
    int index = 0;
    string cadena = cadena0 + "$";

    while (index <= (cadena.length() - 1) && state == 1) {  //Mientras no sea el fin de la cadena y el estado = 1
        string lexema = "";                                 //Inicialmente el lexema no es reconocido
        string token = "Unidentified";

        while (index <= (cadena.length() - 1) && state != 0) { //Mientras no sea el fin de la cadena y el estado sea distinto del ultimo
            if (state == 1) {
                if (isspace(cadena[index])) {    //Evalua si el caracter contiene un espacio en blanco
                    state = 1;
                } else if (isalpha(cadena[index]) || cadena[index] == '_') { //Evalua si el caracter es una letra o "_"
                    state = 2;
                    lexema += cadena[index];
                    token = "Identifier";
                }
                else if (isdigit(cadena[index])) { //Evalua si el caracter es un digito \d
                    state = 0;
                    lexema += cadena[index];
                    token = "Constants";
                }
                else if (cadena[index] == '%') { //Evalua si el caracter es "%"
                    state = 0;
                    lexema += cadena[index];
                    token = "ModuleOpe";
                }
                 else if (cadena[index] == '+' || cadena[index] == '-') { //Evalua si el caracter es "+" o "-"
                    state = 0;
                    lexema += cadena[index];
                    token = "AdditionOp";
                }
                else if (cadena[index] == '*' || cadena[index] == '/') { //Evalua si el caracter es "*" o "/"
                    state = 0;
                    lexema += cadena[index];
                    token = "MultiplOp";
                }
                 else if (cadena[index] == '<' || cadena[index] == '>') { //Evalua si el caracter es "<" o ">"
                    state = 3;
                    lexema += cadena[index];
                    token = "RelationalOp";
                }
                else if (cadena[index] == '!') { //Evalua si el caracter es "!"
                    state = 3;
                    lexema += cadena[index];
                    token = "Unidentified";
                }
                 else if (cadena[index] == ',') { //Evalua si el caracter es ","
                    state = 0;
                    lexema += cadena[index];
                    token = "Comma\t";
                }
                else if (cadena[index] == ':') { //Evalua si el caracter es ":"
                    state = 0;
                    lexema += cadena[index];
                    token = "TwoPoints";
                }
                else if (cadena[index] == '(') { //Evalua si el caracter es "("
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftParent";
                }
                else if (cadena[index] == ')') { //Evalua si el caracter es ")"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightParent";
                }
                else if (cadena[index] == '{') { //Evalua si el caracter es "{"
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftKey\t";
                }
                else if (cadena[index] == '}') { //Evalua si el caracter es "}"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightKey\t";
                }
                 else if (cadena[index] == '[') { //Evalua si el caracter es "["
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftBrack";
                }
                else if (cadena[index] == ']') { //Evalua si el caracter es "]"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightBrack";
                }
                else if (cadena[index] == '$') {    //Evalua si el caracter contiene $
                    state = 0;
                    lexema += cadena[index];
                    token = "End\t";
                } else if (cadena[index] == '=') {   //Evalua si el caracter es "="
                    lexema += cadena[index];
                    token = "Assignment";
                    state = 3;
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
                    index++;
                } else {
                    state = 0;                    //Sino, continua evaluando
                }
            } else if (state == 3) {             //Evalua si el estado es 3
                if (cadena[index] == '=') {      //Evalua si el caracter es el OpRelacional "==, <=, >=, !="
                    lexema += cadena[index];
                    token = "RelationalOp";
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            }
        }
        state = 1;
        //elements.push_back("" + token + "\t\t\t" + lexema);
        tokens.push_back(token);                 //Tokens vector
        lexemas.push_back(lexema);               //Lexemes vector
    }

    //Identifica las palabras reservadas y tipos de datos
    for(size_t i(0); i < lexemas.size(); ++i)
    {
        if (lexemas[i].find("if") != string::npos){
            tokens[i] = "Reserved word";
            lexemas[i] = "si";
        }
        else if (lexemas[i].find("elif") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "sinsi";
        }
        else if (lexemas[i].find("else") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "sino";
        }
         else if (lexemas[i].find("while") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "mientras";
        }
        else if (lexemas[i].find("def") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "definir";
        }
        else if (lexemas[i].find("for") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "para";
        }
        else if (lexemas[i].find("range") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "rango";
        }
        else if (lexemas[i].find("break") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "romper";
        }
        else if (lexemas[i].find("continue") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "continuar";
        }
        else if (lexemas[i].find("global") != string::npos) {
            tokens[i] = "Reserved word";
        }
        else if (lexemas[i].find("not") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "no";
        }
        else if (lexemas[i].find("and") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "ademas";
        }
        else if (lexemas[i].find("or") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "alternativa";
        }
        else if (lexemas[i].find("True") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "Verdadero";
        }
        else if (lexemas[i].find("False") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "Falso";
        }
        else if (lexemas[i].find("print") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "imprimir";
        }
        else if (lexemas[i].find("input") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "entrada";
        }
        else if (lexemas[i].find("return") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "retorno";
        }
        else if (lexemas[i].find("int") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "entero";
        }
        else if (lexemas[i].find("in") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "en";
        }
        else if (lexemas[i].find("float") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "flotante";
        }
        else if (lexemas[i].find("str") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "cadena";
        }
        else if (lexemas[i].find("bool") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "booleano";
        }
        cout <<"Token: "<<tokens[i];
        cout <<"\t\tLexema: "<<lexemas[i] << endl;

    }

     /*
    for (const string& element : elements)
        {
        if (element.find("Lexema: if") != string::npos) {
            cout << "Token: condicional SI, Lexema: if" << endl;
        }
        else if (element.find("Lexema: else") != string::npos) {
            cout << "Token: SINO, Lexema: else" << endl;
        }
        else if (element.find("Lexema: while") != string::npos) {
            cout << "Token: estructura MIENTRAS, Lexema: while" << endl;
        }
        else {
            cout << element << endl;

        }
       }
*/
    return 0;
}

