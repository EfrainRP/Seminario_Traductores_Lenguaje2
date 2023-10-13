#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>

//Lexical Analyzer
using namespace std;
string msjsintaxError = "";


//DataType
bool type(const std::string &cadena) {
    if (cadena.empty()) {
        // Si la cadena está vacía, consideramos que tiene el mismo tipo.
        return true;
    }
    char primerCaracter = cadena[0];
    for (size_t i = 1; i < cadena.length(); ++i) {
        if (cadena[i] != primerCaracter) {
            return false;
        }
    }
    return true;
}
//Remueve los espacios en blanco de los tokens
string space(const string& cadena) {
    std::string resultado;

    for (char caracter : cadena) {
        if (caracter != ' ') {
            resultado += caracter;
        }
    }

    return resultado;
}
  //SintaxError
void agregarError(vector<string>& sintaxErrors, vector<int>& sentenciasErrors, int& line, string& sentencia, int& stat,int& i, string& lexemas) {
    msjsintaxError = ">SyntaxError: invalid syntax "+msjsintaxError+sentencia+" LINE --> <"+to_string(line)+">";
   //string aux = space(lexemas);
    //sentencia = sentencia + aux + " ";
    sintaxErrors.push_back(sentencia);
    sentenciasErrors.push_back(line);
    line++;
    i=500;
    sentencia = "";
    stat = 0;
}
  //NoErrors
void procesarDatos(string& lexemas, string& sentencia,
                   vector<string>& sintaxNoErrors, vector<int>& sentenciasNoErrors,
                   int& line, int& stat) {
    string aux = space(lexemas);
    sentencia = sentencia + aux + " ";
    sintaxNoErrors.push_back(sentencia);
    sentenciasNoErrors.push_back(line);
    line++;
    sentencia = "";
    stat = 0;
}

//Declaraciones en la tabla de simbolos
bool declarationError(vector<string>& vec,string& elemento){
auto it = find(vec.begin(), vec.end(), elemento);
 if (it != vec.end()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    //Lee el archivo
    string fuente;
    string code = "";
    bool i = true;
    ifstream archivo;
    archivo.open("testNoSintaxError.txt",ios::in);

    if (archivo.fail()){
        cout<<"Error al abrir el archivo.";
    }
    while(!archivo.eof()){
        getline(archivo,fuente);
        if (i == true)
        {
            code = code+fuente;
            i = false;
        }
        else{
           code = code+"\n"+fuente;
        }
    }
   archivo.close();
  //Codigo fuente
  //cout<<code<<endl;
    string cadena0 = code;
    //string cadena0 = "return ,; return a,b,c;";
    //string cadena0 = "if True::var=1";
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
                else if (cadena[index] == '\"') { //Evalua si el caracter es "|"
                    state = 0;
                    lexema += cadena[index];
                    token = "Comilla";
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
            lexemas[i] = "y";
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
      //  cout <<"Token: "<<tokens[i];
       //cout <<"Lexema: "<<lexemas[i];
        //cout << "Type: "<<to_string(tipo[i])<<endl;

    }

//------------------------------------------------------------------------
    //Sintax Analyzer
   int stat = 0; //State
   vector<string> sintaxErrors;
   vector<string> sintaxNoErrors;
   vector<int> sentenciasErrors;
   vector<int> sentenciasNoErrors;
   stack<char> pila;
   vector<string> declarados; //Variables Declaration
   string id; //First ID
   bool error = false;
   bool FSTRING = false; //print and input FSTRING
   bool si = false; //if validation
   int line = 1; //CODE LINE
   int parameters = 0; //Parameters for
   bool def = false; //def (funtion)
   bool continuar = false; //continue in if,elif,else
   bool retorno = false; //return in def
   string datatype = ""; //Datatype validation (int,str,bool,float)
   string sentencia = "";
   string aux;
for(int i(0); i < tokens.size(); ++i)
    {
        switch(stat)
        {
      case 0:
          if (tokens[i].find("Reserved word") != string::npos){ //Sintax Reserved words
              if (lexemas[i].find("sinsi") != string::npos){ //Sintax elif
                sentencia = sentencia+"elif"+" ";
                continuar = false;
                if (si == true){
                    stat = 1;
                }else{
                sintaxErrors.push_back(sentencia);
                sentenciasErrors.push_back(line);
                sentencia = "";
                stat = 0;

                }
              }else if (lexemas[i].find("sino") != string::npos){ //Sintax else
                sentencia = sentencia+"else"+" ";
                continuar = false;
                if (si == true){
                    stat = 4;
                    si = false;
                }else{
                sintaxErrors.push_back(sentencia);
                sentenciasErrors.push_back(line);
                sentencia = "";
                stat = 0;
                }
              }else if (lexemas[i].find("mientras") != string::npos){ //Sintax while
                sentencia = sentencia+"while"+" ";
                stat = 1;
                continuar = true;
              }
              else if (lexemas[i].find("si") != string::npos){ //Sintax if
                sentencia = sentencia+"if"+" "; si = true;
                stat = 1;
                continuar = false;
              }
              else if (lexemas[i].find("imprimir") != string::npos){ //Sintax print
                sentencia = sentencia+"print"+" ";
                continuar = false;
                FSTRING = false;
                stat = 15;
              }
              else if (lexemas[i].find("entrada") != string::npos){ //Sintax input
                sentencia = sentencia+"input"+" ";
                FSTRING = false;
                continuar = false;
                stat = 15;
              }
              else if (lexemas[i].find("continuar") != string::npos){ //Sintax continue
                sentencia = sentencia+"continue"+" ";
                stat = 20;
              }
              else if (lexemas[i].find("romper") != string::npos){ //Sintax break
                sentencia = sentencia+"break"+" ";
                stat = 20;
              }
              else if (lexemas[i].find("para") != string::npos){ //Sintax for
                sentencia = sentencia+"for"+" ";
                stat = 21;
              }
              else if (lexemas[i].find("definir") != string::npos){ //Sintax def
                sentencia = sentencia+"def"+" ";
                stat = 21;
                def = true;
              }
              else if (lexemas[i].find("retorno") != string::npos){ //Sintax return
                if (lexemas[i+1].find(';') != string::npos){
                    sentencia = sentencia+"return"+" ";
                    procesarDatos(lexemas[i+1], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                }else{
                sentencia = sentencia+"return"+" ";
                stat = 26;
                retorno = true;
              }}
          }else if(tokens[i].find("Identifier")!= string::npos){//Sintax Identifier
              if (lexemas[i+1].find('(') != string::npos){
                   i--;
                   stat = 24;
              }else{
                    aux = space(lexemas[i]);
                    id = aux;
                    sentencia = sentencia+aux+" ";
                    declarados.push_back(aux);
                    stat = 6;
              }
           }else if(tokens[i].find("Semicolon")!= string::npos){//Sintax Error
                sintaxErrors.push_back(sentencia);
                sentenciasErrors.push_back(line);
                sentencia = "";
                stat = 0;
            }else if(tokens[i].find("End")!= string::npos){//Sintax Error
               if(sentencia.size()>0){
                sintaxErrors.push_back(sentencia);
                sentenciasErrors.push_back(line);
                sentencia = "";
                stat = 0;
               }
           }
       // cout<<"tokens "<<lexemas[i]<<endl;
        break;
      case 1: //Operando 1
          if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 2;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 2;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 2;
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                    pila.push('(');
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                    pila.pop();}
               }else if (tokens[i].find("Reserved word")!= string::npos){ //True and False
                  if (lexemas[i].find("Verdadero") != string::npos){
                           sentencia = sentencia+"True ";
                           stat = 2;
                  }else if (lexemas[i].find("Falso") != string::npos){
                           sentencia = sentencia+"False ";
                           stat = 2;
                  }else if (lexemas[i].find("no") != string::npos){
                           sentencia = sentencia+"not ";
                           stat = 3;
                  }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }
        break;
      case 2: //Operador
        if (tokens[i].find("RelationalOp") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 3;
              }else if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 3;
               }else if (tokens[i].find("MultiplOp")!= string::npos){
                        aux = space(lexemas[i]);
                        sentencia = sentencia+aux;
                        stat = 3;
               }else if (tokens[i].find("opIgualdad")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 3;
              }else if (tokens[i].find("TwoPoints")!= string::npos){
                    if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }
         break;
       case 3: //Operando 2
             if (lexemas[i-1].find("no") != string::npos){
                           stat = 5;
             }else{
                 stat = 4;
             }
              if (tokens[i].find("Identifier")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";

              }else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";

              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";

              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                    pila.push('(');
              }else if (tokens[i].find("Reserved word")!= string::npos){ //True and False
                  if (lexemas[i].find("Verdadero") != string::npos){
                           sentencia = sentencia+"True ";
                  }else if (lexemas[i].find("Falso") != string::npos){
                           sentencia = sentencia+"False ";
                  }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }
         break;
       case 4: //Fin de sentencia o continuacion.
             if (tokens[i].find("TwoPoints")!= string::npos){
                     if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                         procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);}
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 13;
                    pila.pop();}
              }else if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 1;
               }else if (tokens[i].find("MultiplOp")!= string::npos){
                        aux = space(lexemas[i]);
                        sentencia = sentencia+aux;
                        stat = 1;
               }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("y") != string::npos){
                           sentencia = sentencia+"and ";
                           stat = 1;
                  }else if (lexemas[i].find("alternativa") != string::npos){
                           sentencia = sentencia+"or ";
                           stat = 1;
                  }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                  agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }
        break;
       case 5:
            if (tokens[i].find("TwoPoints")!= string::npos){
                        procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
              }else if (tokens[i].find("opIgualdad")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 3;
              }else if (tokens[i].find("RelationalOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 3;
              }else if (tokens[i].find("End")!= string::npos){
                   sintaxErrors.push_back(sentencia);
                   sentenciasErrors.push_back(line);
                   sentencia = "";
                   stat = 0;
              }else{
                   sintaxErrors.push_back(sentencia);
                   sentenciasErrors.push_back(line);
                   sentencia = "";
                   stat = 0;
              }
        break;
       case 6:  //Sintax Identifier
           if (tokens[i].find("Assignment")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 8;
           }else if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 7;
           }else if (tokens[i].find("MultiplOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 7;
           }else if (tokens[i].find("End")!= string::npos){
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                   }
        break;
       case 7: //Asignation
            if (tokens[i].find("Assignment")!= string::npos){
                        aux = space(lexemas[i]);
                        sentencia = sentencia+aux+" ";
                        stat = 8;
            }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
            }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
       case 8: //Operando 1
            if (tokens[i].find("Identifier") != string::npos){
                  if (space(lexemas[i]) == id){
                  error = true;
                  }
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 9;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("Verdadero") != string::npos){
                           sentencia = sentencia+"True ";
                           stat = 9;
                  }else if (lexemas[i].find("Falso") != string::npos){
                           sentencia = sentencia+"False ";
                           stat = 9;
                   }else if (lexemas[i].find("entrada") != string::npos){
                           sentencia = sentencia+"input ";
                           stat = 15;
                   }else if (lexemas[i].find("continuar") != string::npos){
                           if(continuar == true){
                              sentencia = sentencia+"continue ";
                              stat = 9;
                           }
                           else{
                            sentencia = sentencia+"continue ";
                            i++;
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                           }
                  }else if (lexemas[i].find("imprimir") != string::npos){
                            sentencia = sentencia+"print ";
                            i++;
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                  }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                   }else{
                                agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                            }
              }else if (tokens[i].find("Data type")!= string::npos){
                  if (lexemas[i].find("entero") != string::npos){
                           sentencia = sentencia+"int ";
                           datatype = datatype+"i";
                           stat = 11;
                  }else if (lexemas[i].find("flotante") != string::npos){
                           sentencia = sentencia+"float ";
                           datatype = datatype+"f";
                           stat = 11;
                   }else if (lexemas[i].find("booleano") != string::npos){
                           sentencia = sentencia+"bool ";
                           datatype = datatype+"b";
                           stat = 11;
                   }else if (lexemas[i].find("cadena") != string::npos){
                           sentencia = sentencia+"str ";
                           datatype = datatype+"s";
                           stat = 11;}
                   if (type(datatype) == 0){ //Evalua si hay mas de un tipo de dato en una expresion
                      datatype = "";
                      //SemanticError
                      //agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                      stat = 11;
                  }
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
               }else if (tokens[i].find("Comilla")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 14;
                    pila.push('c');
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                   sentencia = sentencia+space(lexemas[i])+" ";
                    agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
       case 9: //Operador
        if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 10;
           }else if (tokens[i].find("MultiplOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 10;
           }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 12;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
               if (!pila.empty() || error == true) {
                           if (error == true){
                            procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                            //SemanticError
                           }else{
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    }else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
           }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
           }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        error = false;
        break;
       case 10:
           if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 9;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("Verdadero") != string::npos){
                           sentencia = sentencia+"True ";
                           stat = 9;
                  }else if (lexemas[i].find("Falso") != string::npos){
                           sentencia = sentencia+"False ";
                           stat = 9;
                  }else if (lexemas[i].find("entrada") != string::npos){
                           sentencia = sentencia+"input ";
                           stat = 15;
                   }else if (lexemas[i].find("continuar") != string::npos){
                           if(continuar == true){
                              sentencia = sentencia+"continue ";
                              stat = 9;
                           }
                           else{
                            sentencia = sentencia+"continue ";
                            i++;
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                           }
                  }else if (lexemas[i].find("imprimir") != string::npos){
                            sentencia = sentencia+"print ";
                            i++;
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                  }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                   }else{
                                agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                            }
              }else if (tokens[i].find("Data type")!= string::npos){
                  if (lexemas[i].find("entero") != string::npos){
                           sentencia = sentencia+"int ";
                           datatype = datatype+"i";
                           stat = 11;
                  }else if (lexemas[i].find("flotante") != string::npos){
                           sentencia = sentencia+"float ";
                           datatype = datatype+"f";
                           stat = 11;
                   }else if (lexemas[i].find("booleano") != string::npos){
                           sentencia = sentencia+"bool ";
                           datatype = datatype+"b";
                           stat = 11;
                   }else if (lexemas[i].find("cadena") != string::npos){
                           sentencia = sentencia+"str ";
                           datatype = datatype+"s";
                           stat = 11;}
                   if (type(datatype) == 0){ //Evalua si hay mas de un tipo de dato en una expresion
                      datatype = "";
                      //SemanticError
                      //agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                      stat = 11;
                  }
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 11: //Case parent ( in var
           if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 9;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 9;
              }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("Verdadero") != string::npos){
                           sentencia = sentencia+"True ";
                           stat = 9;
                  }else if (lexemas[i].find("Falso") != string::npos){
                           sentencia = sentencia+"False ";
                           stat = 9;
                  }else if (lexemas[i].find("continuar") != string::npos){
                           if(continuar == true){
                              sentencia = sentencia+"continue ";
                              stat = 9;
                           }
                           else{
                            sentencia = sentencia+"continue ";
                            i++;
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                           }
                  }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{
                        sentencia=sentencia+")";
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 12: //Case parent ) in var
             if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 8;
           }else if (tokens[i].find("MultiplOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 8;
           }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 12;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
               if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
           }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
              }else{    cout<<lexemas[i]<<endl;
                        cin.get();
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 13: //Case parent ) in conditional
            if (tokens[i].find("RelationalOp") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 1;
              }else if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 1;
               }else if (tokens[i].find("MultiplOp")!= string::npos){
                        aux = space(lexemas[i]);
                        sentencia = sentencia+aux;
                        stat = 1;
               }else if (tokens[i].find("opIgualdad")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 1;
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 13;
                    pila.pop();}
              }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("y") != string::npos){
                           sentencia = sentencia+"and ";
                           stat = 1;
                  }else if (lexemas[i].find("alternativa") != string::npos){
                           sentencia = sentencia+"or ";
                           stat = 1;}
              }else if (tokens[i].find("TwoPoints")!= string::npos){
               if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                            agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 14: //Strings ID
               if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux;
                  stat = 14;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 14;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 14;
              }
              else if (tokens[i].find("RightParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 14;
              }
              else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 14;
              }else if (tokens[i].find("Comilla")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+space(lexemas[i]);
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    sentencia=sentencia+" "+space(lexemas[i]);
                    stat = 14;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
                if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 15: //print
            if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 16;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 16: //" or f first in print
            if (tokens[i].find("Comilla")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 17;
                    pila.push('c');
              }else if (tokens[i].find("Identifier") != string::npos){
                    if (space(lexemas[i]) == "f"){ //Fstring valitation
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 19;
                  FSTRING = true;
                  }else{  sentencia = sentencia+space(lexemas[i])+" ";
                  stat = 18; }
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{

                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 17: //print string
           if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux;
                  stat = 17;
              } else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 17;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 17;
              }
              else if (tokens[i].find("LeftKey")!= string::npos){
                    if (FSTRING == true){
                        pila.push('c');
                    }
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 17;
              }
              else if (tokens[i].find("RightKey")!= string::npos){
                    if (FSTRING == true){
                        if (pila.empty()) {
                         sentencia=sentencia+space(lexemas[i]);
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                        else{
                            sentencia=sentencia+" "+space(lexemas[i]);
                            stat = 17;
                            pila.pop();}
                    }else{
                     aux = space(lexemas[i]);
                     sentencia = sentencia+aux;
                     stat = 17;
                    }
              }
              else if (tokens[i].find("Comilla")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+space(lexemas[i]);
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    sentencia=sentencia+" "+space(lexemas[i]);
                    stat = 18;
                    pila.pop();}
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 18: //print and input end
            if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 18;
                    pila.pop();}
              }else if (tokens[i].find("Comma")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 16;
              }else if (tokens[i].find("Semicolon")!= string::npos){
                if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 19: //FSTRING
            if (tokens[i].find("Comilla")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 17;
                    pila.push('c');
             }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 20: //continue and break sintax
           if (tokens[i].find("Semicolon")!= string::npos){
                procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
             }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 21: //for and def Sintax
          if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  if(def == false){
                    stat = 22;
                  }
                  else{
                    stat = 24;
                  }
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 22: //in
            if (tokens[i].find("Reserved word")!= string::npos){ //in
                  if (lexemas[i].find("en") != string::npos){
                           sentencia = sentencia+"in ";
                           stat = 23;
                  }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
            }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 23: //range
            if (tokens[i].find("Reserved word")!= string::npos){ //in
                  if (lexemas[i].find("rango") != string::npos){
                           sentencia = sentencia+"range ";
                           stat = 24;
                  }else{
                   agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
            }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 24: //Parameters
             if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 24;
                    pila.push('(');
              }
              else if (tokens[i].find("Comma")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+",";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 24;
                    pila.pop();}
              }
             else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 25;
                    pila.pop(); }
              }else if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux;
                  stat = 24;
                  pila.push('i');
                  if (def == false){ parameters++;}
              }else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('1');
                    if (def == false){ parameters++;}
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('.');
                    if (def == false){ parameters++;}
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;
        case 25: //END for and def
            if (tokens[i].find("TwoPoints")!= string::npos ){
                    if (parameters > 3){
                        sentencia = sentencia+" range expected at most 3 arguments, got "+to_string(parameters);
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                   }else{
                    if (pila.empty()) {
                          if (def == true){
                            procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                          }else{
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}}
                    else{
                    pila.pop();
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }}
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        parameters = 0;
        def = false;
        break;
        case 26: //return sintax
          if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux;
                  stat = 26;
                  pila.push('i');
              }else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('1');
                    stat = 26;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('.');
                    stat = 26;
              }else if (tokens[i].find("Comma")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+",";
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 26;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
                    pila.pop();
                    if (!pila.empty()) {
                         agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
               }else{
                        agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,lexemas[i]);
                    }
        break;

       // cout <<"Token: "<<element<<endl;
    }

} //END Lexical Analysis
    //No Errors
for(size_t i(0); i < sintaxNoErrors.size(); ++i)
{
    cout<<"Lexical analysis completed with no errors <"<<sentenciasNoErrors[i]<<"> "<<sintaxNoErrors[i]<<endl;
}
   //Errors
cout<<msjsintaxError<<endl;
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
