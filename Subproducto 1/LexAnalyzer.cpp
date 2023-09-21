#include <iostream>
#include <string>
#include <vector>

//Lexical Analyzer
using namespace std;

int main() {
    string cadena0 = " ,int =01.96< invar _2 var_2!!= >=<><= 1234243=== breakif else while and elif 58.25 return*/+-%[]{}():strbool global 21.89";
    //string cadena0;
    //getline(cin,cadena0);
    //cin.ignore();
    //vector<string> elements;
    vector<string> lexemas;
    vector<string> tokens;
    vector<int> tipo;
    int state = 1;
    int index = 0;
    int intTipo = -1;
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
                }
                 else if (cadena[index] == '+' || cadena[index] == '-') { //Evalua si el caracter es "+" o "-"
                    state = 0;
                    lexema += cadena[index];
                    token = "AdditionOp";
                    intTipo = 5;
                }
                else if (cadena[index] == '*' || cadena[index] == '/') { //Evalua si el caracter es "*" o "/"
                    state = 0;
                    lexema += cadena[index];
                    token = "MultiplOp";
                    intTipo = 6;
                }
                 else if (cadena[index] == '<' || cadena[index] == '>') { //Evalua si el caracter es "<" o ">"
                    state = 3;
                    lexema += cadena[index];
                    token = "RelationalOp";
                    intTipo = 7;
                }
                else if (cadena[index] == '|') { //Evalua si el caracter es "|"
                    state = 5;
                    lexema += cadena[index];
                    intTipo = 8;
                }
                else if (cadena[index] == '|') { //Evalua si el caracter es "|"
                    state = 6;
                    lexema += cadena[index];
                }
                else if (cadena[index] == '!') { //Evalua si el caracter es "!"
                    state = 7;
                    lexema += cadena[index];
                    token = "opNOT";
                    intTipo = 10;
                }
                 else if (cadena[index] == ',') { //Evalua si el caracter es ","
                    state = 0;
                    lexema += cadena[index];
                    token = "Comma";
                    intTipo = 13;
                }
                else if (cadena[index] == ';') { //Evalua si el caracter es ";"
                    state = 0;
                    lexema += cadena[index];
                    token = "Punto y coma";
                    intTipo = 12;
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
                    intTipo = 14;
                }
                else if (cadena[index] == ')') { //Evalua si el caracter es ")"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightParent";
                    intTipo = 15;
                }
                else if (cadena[index] == '{') { //Evalua si el caracter es "{"
                    state = 0;
                    lexema += cadena[index];
                    token = "LeftKey";
                    intTipo = 16;
                }
                else if (cadena[index] == '}') { //Evalua si el caracter es "}"
                    state = 0;
                    lexema += cadena[index];
                    token = "RightKey";
                    intTipo = 17;
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
                    token = "End";
                    intTipo = 23;
                } else if (cadena[index] == '=') {   //Evalua si el caracter es "="
                    lexema += cadena[index];
                    token = "Assignment";
                    state = 7;
                    intTipo = 18;
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
                    intTipo = 7;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if(state == 4){              //Evalua si el estado es 3
                if (isdigit(cadena[index])) {      //Evalua si es otro numero
                    lexema += cadena[index];
                    token = "Integer";
                    state = 4;
                    intTipo = 1;
                    index++;
                } else if (cadena[index] == '.'){    //Si es un punto
                    lexema += cadena[index];
                    token = "Real";
                    state = 4;
                    intTipo = 2;
                    index++;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 5) {             //Evalua si el estado es 5
                if (cadena[index] == '|') {      //Evalua si el caracter es "|"
                    lexema += cadena[index];
                    token = "opOR";
                    intTipo = 8;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 6) {             //Evalua si el estado es 6
                if (cadena[index] == '&') {      //Evalua si el caracter es "&"
                    lexema += cadena[index];
                    token = "opAND";
                    intTipo = 9;
                    index++;
                    state = 0;
                } else {                         //Sino, continua evaluando
                    state = 0;
                }
            } else if (state == 7) {             //Evalua si el estado es 7
                if (cadena[index] == '=') {      //Evalua si se completa el "== !="
                    lexema += cadena[index];
                    token = "opIgualdad";
                    intTipo = 11;
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
        tipo.push_back(intTipo);                 //Tipo vector
    }

    //Identifica las palabras reservadas y tipos de datos
    for(size_t i(0); i < lexemas.size(); ++i)
    {
        if (lexemas[i].find("if") != string::npos){
            tokens[i] = "Reserved word";
            lexemas[i] = "si";
            tipo[i] = 19;
        }
        else if (lexemas[i].find("elif") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "sinsi";
        }
        else if (lexemas[i].find("else") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "sino";
            tipo[i] = 22;
        }
        else if (lexemas[i].find("while") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "mientras";
            tipo[i] = 20;
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
            tipo[i] = 21;
        }
        else if (lexemas[i].find("int") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "entero";
            tipo[i] = 4;
        }
        else if (lexemas[i].find("in") != string::npos) {
            tokens[i] = "Reserved word";
            lexemas[i] = "en";
        }
        else if (lexemas[i].find("float") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "flotante";
            tipo[i] = 4;
        }
        else if (lexemas[i].find("str") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "cadena";
            tipo[i] = 3;
        }
        else if (lexemas[i].find("bool") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "booleano";
        }
        else if (lexemas[i].find("void") != string::npos) {
            tokens[i] = "Data type";
            lexemas[i] = "void";
            tipo[i] = 4;
        }
        tokens[i].resize(20,' ');
        lexemas[i].resize(15, ' ');
        cout <<"Token: "<<tokens[i];
        cout <<"Lexema: "<<lexemas[i];
        cout << "Tipo: "<<to_string(tipo[i])<<endl;

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

