#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>

//Lexical Analyzer
using namespace std;


//DataType
bool type(const std::string &cadena) {
    if (cadena.empty()) {
        // Si la cadena está vacía, consideramos que tiene el mismo tipo.
        return true;
    } 
    char primerCaracter = cadena[0];
    for (size_t i = 1; i < cadena.length(); ++i) { //Busca si hay más de un tipo de dato en la cadena
        if (cadena[i] != primerCaracter) { //Si hay mas de un tipo de dato, retorna false 
            return false;
        }
    }
    return true; //Retorna true al haber un solo tipo de dato 
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
  //SemanticError
void semanticError(vector<string>& semanticErrors, vector<int>& sentenciasErrors, int& line, string& sentencia, int& stat,int& i, string& lexemas) {
    //string aux = space(lexemas);
    //sentencia = sentencia + aux + " ";
    semanticErrors.push_back(sentencia);
    sentenciasErrors.push_back(line);
    line++;
    //i--;
    sentencia = "";
    stat = 0;
}
  //SintaxError
void sintaxError(string& msjsintaxError, int& line, string& sentencia, int& stat,int& i) {
    msjsintaxError = ">SyntaxError: invalid syntax "+msjsintaxError+sentencia+" LINE --> <"+to_string(line)+">\n -Process finished with exit code 0.";
    i = 500; //Maximo de tokens
    stat = 0;
}
  //NoSintaxErrors
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
bool declarationError(vector<string>& vec,string& elemento){ //Busca una declaracion en la tabla de simbolos
auto it = find(vec.begin(), vec.end(), elemento); //find busca el elemento desde .begin() hasta .end() en el vector
 if (it != vec.end()) { //Si it no es igual al final del vector, se encontro una coincidencia 
        return true;
    } else { //Si it = vec.end() (final del vector), no se encontro una coincidencia 
        return false;
    }
}

int main() {
    //Lee el archivo
    string fuente;
    string code = "";
    bool i = true;
    ifstream archivo;
    archivo.open("testSemanticNoError.txt",ios::in);
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

    //string cadena0 = "def funtion(a,b,c,d,e,f):\n"
                 "return a,b,c,d;"
                 "var = var;"
                 "cadenita = \"string\";"
                 "for csas in range(0,1,3):\n"
                 "def funtion(a,b,c,d,e,f):\n"
                 "for it in range(5):\n"
                 "while True:\n"
                 "   a = x;\n"
                 "   b = \"test\";\n"
                 "   c = 5.1;\n"
                 "   break;\n"
                 "if (a != x):\n"
                 "    b = \"test\";\n"
                 "else:\n"
                 "    b = \"test3\";\n"
                 "for element in range(0,a):\n"
                 "    print(element);\n"
                 "text = input(\"Type \");\n"
                 "print(f\"{text}\");\n"
                 "input(\"\");\n"
                 "print(\"Test\");\n"
                 "a = (2*(c+(42)));\n"
                 "if (a == 40 and c != a):\n"
                 "   var1 = 1;\n"
                 "elif not test:\n"
                 "   var2 = False;\n"
                 "elif a >= c or var1 < 10:\n"
                 "  myvar = a;\n"
                 "else:\n"
                 "   var3 = \"Not found\";\n"
                 "myint = int(a) + int(c);\n"
                 "semanticerror = int(a) + str(c);\n"
                 "if (a == (c+20) and c <= 5):\n"
                 "while a != c:\n"
                 "   print(\"\");\n"
                 "   break;\n"
                 "   while a ==b:\n";

    //string cadena0 = "if True::var=1";
    //string cadena0;
    //getline(cin,cadena0);
    //cin.ignore();
    //vector<string> elements;
    vector<string> lexemas;
    vector<string> tokens;
    vector<int> tipo;
    string tokenError = "Unidentified";
    bool lexicalError;
    int state = 1;
    int index = 0;
    int intTipo = -1;
    string cadena = cadena0 + "$";
    while (index <= (cadena.length() - 1) && state == 1) {  //Mientras no sea el fin de la cadena y el estado = 1
        string lexema = "";                                 //Inicialmente el lexema no es reconocido
        string token = "Unidentified";
        intTipo = 39;  //Inicialmente el tipo es 39 (no reconocido)

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
                else if (cadena[index] == '\"') { //Evalua si el caracter es """
                    state = 0;
                    lexema += cadena[index];
                    token = "Comilla";
                    intTipo = 40;
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
                    intTipo = 39;
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

lexicalError = declarationError(tokens,tokenError);
if (lexicalError){ //Lexical Error

    for(size_t i(0); i < tokens.size(); ++i){
        if(tokens[i].find("Unidentified") != string::npos)
        {
           cout<<">Lexical error in: "<<lexemas[i]<<"\n-Process finished with exit code 0.";
           break;
        }
    }
}
else{
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
   //     cout <<"Token: "<<tokens[i];
     //  cout <<"Lexema: "<<lexemas[i];
       // cout << "Type: "<<to_string(tipo[i])<<endl;

    }
}
//------------------------------------------------------------------------
    //Sintax Analyzer
   int stat = 0; //State
   vector<string> sintaxNoErrors;
   vector<int> sentenciasNoErrors;
   stack<char> pila;
   bool FSTRING = false; //print and input FSTRING
   bool si = false; //if validation
   int line = 1; //CODE LINE
   int parameters = 0; //Parameters for
   bool def = false; //def (funtion)
   bool funtion = false; //funtion ID
   bool retorno = false; //return in def
   string msjsintaxError; //MSJ SintaxError
   string sentencia = "";
   string aux;
   //Semantic Analyzer
   vector<string> semanticErrors;
   vector<int> sentenciasErrors;
   vector<string> declarados; //Symbol table ID
   vector<string> declarados_def; //Symbol table def
   vector<int> parameters_def; //Symbol table parameters def
   int count_parameters; //Count parameters def 
   string sentenceError; 
   bool it = false; //Sentence Iterator
   bool found; //Found symbol table
   string datatype = ""; //Datatype validation (int,str,bool,float)
   string id; //First ID
   string aux_id; //Aux ID
   string aux_def; //Aux ID def
   bool zero = false; //Division by zero
   bool error = false; //ID error
   bool second = true; //Second ID
if(!lexicalError){ //If there are no lexical errors 
for(int i(0); i < tokens.size(); ++i) //for each token in tokens size
    {

        switch(stat)                 //Initial state SA = 0
        {
      case 0:
          //cout<<"Mi lexema actual caso 0: "<<lexemas[i]<<it<<" Sentencia "<<sentenceError<<endl;
          //cin.get();
          if (it == false){ //NO SEMANTIC ERROR
          parameters = 0; //Parameters for
          def = false;    //def flag
          aux_id = "";    //Fist ID
          count_parameters = 0; //def parameters
          if (tokens[i].find("Reserved word") != string::npos){ //Sintax Reserved words
              if (lexemas[i].find("sinsi") != string::npos){ //Sintax elif
                sentencia = sentencia+"elif"+" ";
                if (si == true){
                    stat = 1;
                }else{
                sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
              }else if (lexemas[i].find("sino") != string::npos){ //Sintax else
                sentencia = sentencia+"else"+" ";
                if (si == true){
                    stat = 4;
                    si = false;
                }else{
                sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
              }else if (lexemas[i].find("mientras") != string::npos){ //Sintax while
                sentencia = sentencia+"while"+" ";
                stat = 1;
              }
              else if (lexemas[i].find("si") != string::npos){ //Sintax if
                sentencia = sentencia+"if"+" "; si = true;
                stat = 1;
              }
              else if (lexemas[i].find("imprimir") != string::npos){ //Sintax print
                sentencia = sentencia+"print"+" ";
                FSTRING = false;
                stat = 15;
              }
              else if (lexemas[i].find("entrada") != string::npos){ //Sintax input
                sentencia = sentencia+"input"+" ";
                FSTRING = false;
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
                if (retorno == true){
                      if (lexemas[i+1].find(';') != string::npos){
                       sentencia = sentencia+"return"+" ";
                       stat = 20;

                }else{
                sentencia = sentencia+"return"+" ";
                stat = 26;
                 }}else{ sentencia = sentencia+"return"+" outside function";
                      sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }  retorno = false;}
          }else if(tokens[i].find("Identifier")!= string::npos){//Sintax Identifier
              if (lexemas[i+1].find('(') != string::npos){ //Funtion declaration
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    if(declarationError(declarados_def,aux) != true){
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                    }else{
                        stat = 24;
                       funtion = true;
                       aux_def = aux;
                    }
              }else{ //Normal ID
                    aux = space(lexemas[i]);
                    id = aux;
                    sentencia = sentencia+aux+" ";
                    aux_id = aux; //Same ID validation
                    if(declarationError(declarados,aux) == true){
                        second = true;
                    }
                    else{
                    second = false;
                    if(declarationError(declarados,aux) == true){
                        for(int i(0); i < declarados.size(); ++i){
                            if(declarados[i] == aux){
                                declarados[i] = aux;
                            }
                        }
                    }else{
                    declarados.push_back(aux);}
                    }
                    stat = 6;
              }
            }else if(tokens[i].find("End")!= string::npos){//Sintax Error
               if(sentencia.size()>0){
                sintaxError(msjsintaxError,line,sentencia,stat,i);
               }
           }else{
                 stat = 0;
               }
       // cout<<"tokens "<<lexemas[i]<<endl;
          }else{ //SEMANTIC ERROR
              if (lexemas[i].find(';') != string::npos){
                       //cout<<"Semicolon ; encontrado"<<endl;
                       it = false;
                       semanticError(semanticErrors,sentenciasErrors,line,sentenceError,stat,i,lexemas[i]);
                       sentencia = "";
              }else if(lexemas[i].find(':') != string::npos){
                   //cout<<"TwoPoints : encontrado"<<endl;
                   it = false;
                   semanticError(semanticErrors,sentenciasErrors,line,sentenceError,stat,i,lexemas[i]);
                   sentencia = "";
              }else{
              //cout<<"Lexema brincado: "<<lexemas[i]<<endl;
              aux = space(lexemas[i]);
              sentenceError = sentenceError+aux+" ";
              }
              //cin.get();
          }
        break;
      case 1: //Operando 1
          if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 2;
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                    pila.pop();}
                    if(tokens[i-1].find("AdditionOp")!= string::npos || tokens[i-1].find("MultiplOp")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
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
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{ sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                        if((lexemas[i].find('/')!= string::npos && lexemas[i+1].find('0')!= string::npos && (tokens[i+2].find("opIgualdad")!= string::npos || tokens[i+2].find("RelationalOp")!= string::npos || lexemas[i+2].find(':')!= string::npos || lexemas[i+2].find("y") != string::npos || lexemas[i+2].find("or") != string::npos))){
                         sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                          it = true;
                          stat = 0;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                            }
                    }
               }else if (tokens[i].find("opIgualdad")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 3;
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                    pila.pop();}
              }else if (tokens[i].find("TwoPoints")!= string::npos){
                    if (!pila.empty()) {
                         sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                    sentencia = sentencia+space(lexemas[i]);
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                    found = declarationError(declarados,aux);
                      if(found == false){ //SemanticError
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                      it = true;
                      stat = 0;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                        }
                      }
                      if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                          sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                          it = true;
                          stat = 0;
                          second = true;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                           }
                      }

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
                      sentencia = sentencia+space(lexemas[i]);
                      sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                   sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }
         break;
       case 4: //Fin de sentencia o continuacion if, elif, else, while.
             if (tokens[i].find("TwoPoints")!= string::npos){
                     if (!pila.empty()) {
                         sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                         procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);}
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
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

                        if((lexemas[i].find('/')!= string::npos && lexemas[i+1].find('0')!= string::npos && (tokens[i+2].find("opIgualdad")!= string::npos || tokens[i+2].find("RelationalOp")!= string::npos || lexemas[i+2].find(':')!= string::npos || lexemas[i+2].find("y") != string::npos || lexemas[i+2].find("or") != string::npos))){
                         sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                          it = true;
                          stat = 0;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                            }
                    }
               }else if (tokens[i].find("Reserved word")!= string::npos){
                  if (lexemas[i].find("y") != string::npos){
                           sentencia = sentencia+"and ";
                           stat = 1;
                  }else if (lexemas[i].find("alternativa") != string::npos){
                           sentencia = sentencia+"or ";
                           stat = 1;
                  }else{ sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{ sentencia = sentencia+space(lexemas[i]);
                  sintaxError(msjsintaxError,line,sentencia,stat,i);
              }
        break;
       case 5: //Operador logico not
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
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                    sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
                   }
        break;
       case 7: //Asignation
            if (tokens[i].find("Assignment")!= string::npos){
                        aux = space(lexemas[i]);
                        sentencia = sentencia+aux+" ";
                        stat = 8;
            }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
            }else{      sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
       case 8: //Operando 1
            if (tokens[i].find("Identifier") != string::npos){
                  if (space(lexemas[i]) == id){
                  error = true;
                  }
                  stat = 9;
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
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
                           sentencia = sentencia+"continue ";
                           sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else if (lexemas[i].find("imprimir") != string::npos){
                            sentencia = sentencia+"print ";
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                   }else{
                                sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                     if(datatype.find('i') != string::npos && datatype.find('f') != string::npos ){
                            stat = 11;
                     }else{
                      datatype = "";
                      //SemanticError
                      sentenceError = sentenceError+"TypeError: incompatible data type "+sentencia;
                      it = true;
                      stat = 0;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                        }
                  }}else{  //Evalua si el mismo tipo de dato es una cadena
                        if (datatype.find('s') != string::npos){ //Evalua las operaciones validas de una cadena
                             if(sentencia.find('-') != string::npos || sentencia.find('*') != string::npos ||  sentencia.find('/') != string::npos ){
                                  datatype = "";
                                  //SemanticError
                                  sentenceError = sentenceError+"TypeError: incompatible data type "+sentencia;
                                  it = true;
                                  stat = 0;
                                  while (!pila.empty()) {
                                   pila.pop(); // Vacia la pila
                                    }
                            }else{
                              stat = 11;
                            }
                  }}
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
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                   sentencia = sentencia+space(lexemas[i]);
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
       case 9: //Operador
        if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 10;
           }else if (tokens[i].find("MultiplOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 10;
                    if((lexemas[i].find('/')!= string::npos && lexemas[i+1].find('0')!= string::npos && lexemas[i+2].find(';')!= string::npos) || (lexemas[i].find('/')!= string::npos && lexemas[i+1].find('(')!= string::npos && lexemas[i+2].find('0')!= string::npos && lexemas[i+3].find(')')!= string::npos && lexemas[i+4].find(';')!= string::npos)){
                         sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                          it = true;
                          stat = 0;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                            }
                    }
           }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 12;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
               if (!pila.empty() || error == true) {
                           if (error == true){ datatype = "";
                            procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                            //SemanticError in if
                           }else{
                         sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    }else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
           }else if (tokens[i].find("End")!= string::npos){
                       sintaxError(msjsintaxError,line,sentencia,stat,i);
           }else{      sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        error = false;
        break;
       case 10:
           if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 9;
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
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
                            sentencia = sentencia+"continue ";
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else if (lexemas[i].find("imprimir") != string::npos){
                            sentencia = sentencia+"print ";
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                   }else{       sentencia = sentencia+space(lexemas[i]);
                                sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                     if(datatype.find('i') != string::npos && datatype.find('f') != string::npos ){
                            stat = 11;
                     }else{
                      datatype = "";
                      //SemanticError
                      sentenceError = sentenceError+"TypeError: incompatible data type "+sentencia;
                      it = true;
                      stat = 0;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                        }
                  }}else{  //Evalua si el mismo tipo de dato es una cadena
                        if (datatype.find('s') != string::npos){ //Evalua las operaciones validas de una cadena
                             if(sentencia.find('-') != string::npos || sentencia.find('*') != string::npos ||  sentencia.find('/') != string::npos ){
                                  datatype = "";
                                  //SemanticError
                                  sentenceError = sentenceError+"TypeError: incompatible data type "+sentencia;
                                  it = true;
                                  stat = 0;
                                  while (!pila.empty()) {
                                   pila.pop(); // Vacia la pila
                                    }
                            }else{
                              stat = 11;
                            }
                  }}
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{    sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 11: //Case parent ( in var
           if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 9;
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
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
                            sentencia = sentencia+"continue ";
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                  }else{sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
              }else if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{
                        sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 12: //Case parent ) in var
             if (tokens[i].find("AdditionOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 8;
           }else if (tokens[i].find("MultiplOp")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 8;
                    if((lexemas[i].find('/')!= string::npos && lexemas[i+1].find('0')!= string::npos && lexemas[i+2].find(';')!= string::npos) || (lexemas[i].find('/')!= string::npos && lexemas[i+1].find('(')!= string::npos && lexemas[i+2].find('0')!= string::npos && lexemas[i+3].find(')')!= string::npos && lexemas[i+4].find(';')!= string::npos)){
                         sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                          it = true;
                          stat = 0;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                            }
                    }
           }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 12;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
               if (!pila.empty()) {sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{ datatype = "";
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
           }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
              }else{    sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                        if((lexemas[i].find('/')!= string::npos && lexemas[i+1].find('0')!= string::npos && (tokens[i+2].find("opIgualdad")!= string::npos || tokens[i+2].find("RelationalOp")!= string::npos || lexemas[i+2].find(':')!= string::npos || lexemas[i+2].find("y") != string::npos || lexemas[i+2].find("or") != string::npos))){
                         sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                          it = true;
                          stat = 0;
                          while (!pila.empty()) {
                           pila.pop(); // Vacia la pila
                            }
                    }
               }else if (tokens[i].find("opIgualdad")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 1;
              }else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
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
               if (!pila.empty()) { sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{       sentencia = sentencia+space(lexemas[i]);
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    sentencia=sentencia+" "+space(lexemas[i]);
                    stat = 14;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
                if (!pila.empty()) { sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 15: //print and input
            if (tokens[i].find("LeftParent")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 16;
                    pila.push('(');
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                  }else{
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 18;
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
                  }
              }else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 18;
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux;
                    stat = 18;
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{
                        sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    sentencia=sentencia+" "+space(lexemas[i]);
                    stat = 18;
                    pila.pop();}
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 18: //print and input end
            if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
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
                if (!pila.empty()) { sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
               }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 19: //FSTRING
            if (tokens[i].find("Comilla")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 17;
                    pila.push('c');
             }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 20: //continue and break and funtion ID sintax
           if (tokens[i].find("Semicolon")!= string::npos){
                procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
             }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                    declarados_def.push_back(aux);
                  }
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 22: //in
            if (tokens[i].find("Reserved word")!= string::npos){ //in
                  if (lexemas[i].find("en") != string::npos){
                           sentencia = sentencia+"in ";
                           stat = 23;
                  }else{ sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
            }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 23: //range
            if (tokens[i].find("Reserved word")!= string::npos){ //in
                  if (lexemas[i].find("rango") != string::npos){
                           sentencia = sentencia+"range ";
                           stat = 24;
                  }else{ sentencia = sentencia+space(lexemas[i]);
                   sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
            }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 24;
                    pila.pop();
                    }
              }
             else if (tokens[i].find("RightParent")!= string::npos){
                    if (pila.empty()) {
                         sentencia=sentencia+")";
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    pila.pop();
                    sentencia = sentencia+aux+" ";
                    if (funtion == true){
                        stat = 20; funtion = false;  if (pila.size() > 0){pila.pop();
                        if(declarationError(declarados_def,aux_def) == true){
                        for(int i(0); i < declarados_def.size(); ++i){
                            if(declarados_def[i] == aux_def){
                                if(parameters_def[i] != count_parameters){
                                        int pd = parameters_def[i];
                                    sentenceError = sentenceError+"TypeError: "+aux_def+" requires <"+to_string(pd)+"> arguments and got <"+to_string(count_parameters)+">. "+sentencia;
                                      //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                                      it = true;
                                      stat = 0;
                                      while (!pila.empty()) {
                                       pila.pop(); // Vacia la pila
                                        }
                                      break;
                                }
                            }
                        }}
                        }
                    }else{stat = 25;}
                    }
              }else if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";;
                  stat = 24;
                  pila.push('i');
                 count_parameters++;
                 if (def == false && funtion == false){ parameters++;}
                 if(def == false){
                 found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true; retorno = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true; retorno = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }}
              }else if (tokens[i].find("Integer")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('1');
                    count_parameters++;
                    if (def == false && funtion == false){ parameters++;}
              }else if (tokens[i].find("Real")!= string::npos){
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    pila.push('.');
                    count_parameters++;
                    if (def == false && funtion == false){ parameters++;}
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;
        case 25: //END for and def
            if (tokens[i].find("TwoPoints")!= string::npos ){
                    if (parameters > 3){
                        sentencia = sentencia+" range expected at most 3 arguments, got "+to_string(parameters);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                   }else{
                    if (pila.empty()) {
                          if (def == true){ retorno = true;
                          parameters_def.push_back(count_parameters);
                            procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                          }else{ sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}}
                    else{
                    pila.pop();
                     if (def == true){ retorno = true; parameters_def.push_back(count_parameters);
                        }
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }}
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        parameters = 0;
        def = false;
        break;
        case 26: //return sintax
          if (tokens[i].find("Identifier") != string::npos){
                  aux = space(lexemas[i]);
                  sentencia = sentencia+aux+" ";
                  stat = 26;
                  pila.push('i');
                  found = declarationError(declarados,aux);
                  if(found == false){ //SemanticError
                  sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                  //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,lexemas[i]);
                  it = true;
                  stat = 0;
                  while (!pila.empty()) {
                   pila.pop(); // Vacia la pila
                    }
                  }
                  if(space(lexemas[i]) == aux_id && second == false){ //Same ID declaration Error
                      sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                      it = true;
                      stat = 0;
                      second = true;
                      while (!pila.empty()) {
                       pila.pop(); // Vacia la pila
                       }
                  }
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
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    aux = space(lexemas[i]);
                    sentencia = sentencia+aux+" ";
                    stat = 26;
                    pila.pop();}
              }else if (tokens[i].find("Semicolon")!= string::npos){
                    pila.pop();
                    if (!pila.empty()) { sentencia = sentencia+space(lexemas[i]);
                         sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                    procesarDatos(lexemas[i], sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
              }else if (tokens[i].find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
               }else{   sentencia = sentencia+space(lexemas[i]);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
        break;

       // cout <<"Token: "<<element<<endl;
    }

} //END Analysis

//If there are errors
if(msjsintaxError.size() > 0){
//Error
cout<<msjsintaxError<<endl;
}else{ //If there are no errors
  cout<<"< System: Lexical analysis completed with no errors. >\n"<<"-Process finished with exit code 0."<<endl<<endl;
  if(!semanticErrors.empty()){ //If there are semantic errors
  for(int i(0); i < semanticErrors.size(); ++i){
                    cout<<semanticErrors[i]<<"Line <"<<sentenciasErrors[i]<<">"<<endl;
                  }
  }else{ //If there are no semantic errors
      cout<<"< System: Semantic analysis completed with no errors. >\n"<<"-Process finished with exit code 0."<<endl;
  }
//for(size_t i(0); i < sintaxNoErrors.size(); ++i)
//{
//    cout<<"Lexical analysis completed with no errors <"<<sentenciasNoErrors[i]<<"> "<<sintaxNoErrors[i]<<endl;
//   if(i == sintaxNoErrors.size()-1){
//        cout<<"-Process finished with exit code 0.";
// }}
}
}
     /* 
     //Example
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
