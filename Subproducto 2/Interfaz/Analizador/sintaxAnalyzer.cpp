#include "mainwindow.h"
#include <stack>
#include <algorithm>

using namespace std;

//DataType
bool type(const string &cadena){
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

    sentencia = sentencia + lexemas + " ";
    sintaxNoErrors.push_back(sentencia);
    sentenciasNoErrors.push_back(line);
    line++;
    sentencia = "";
    stat = 0;
}
///Sintax Analyzer
string funcionSintatico(vector<tablaSimbolo>& TablaSimbolo){
    size_t i = 0;
    while (i < TablaSimbolo.size()) {
        if(TablaSimbolo[i].token.find("Unidentified") != string::npos)
        {
            string ErrorLexical = "Lexical error in: "+TablaSimbolo[i].lexema+"\n-Process finished with exit code 0.";
            qCritical()<<ErrorLexical;
            return ErrorLexical;
        }
        i++;
    }

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
    //Semantic Analyzer variables
    vector<string> semanticErrors;
    vector<int> sentenciasErrors;
    vector<string> declarados; //Variables Declaration
    string datatype = ""; //Datatype validation (int,str,bool,float)
    string id; //First ID
    bool error = false; //ID = ID error
    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
        for(int i=0; i < TablaSimbolo.size(); ++i)
        {

            switch(stat)
            {
            case 0:
                if (TablaSimbolo[i].token.find("Reserved word") != string::npos){ //Sintax Reserved words
                    if (TablaSimbolo[i].lexema.find("sinsi") != string::npos){ //Sintax elif
                        sentencia = sentencia+"elif"+" ";
                        if (si == true){
                            stat = 1;
                        }else{
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                        }
                    }else if (TablaSimbolo[i].lexema.find("sino") != string::npos){ //Sintax else
                        sentencia = sentencia+"else"+" ";
                        if (si == true){
                            stat = 4;
                            si = false;
                        }else{
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                        }
                    }else if (TablaSimbolo[i].lexema.find("mientras") != string::npos){ //Sintax while
                        sentencia = sentencia+"while"+" ";
                        stat = 1;
                    }
                    else if (TablaSimbolo[i].lexema.find("si") != string::npos){ //Sintax if
                        sentencia = sentencia+"if"+" "; si = true;
                        stat = 1;
                    }
                    else if (TablaSimbolo[i].lexema.find("imprimir") != string::npos){ //Sintax print
                        sentencia = sentencia+"print"+" ";
                        FSTRING = false;
                        stat = 15;
                    }
                    else if (TablaSimbolo[i].lexema.find("entrada") != string::npos){ //Sintax input
                        sentencia = sentencia+"input"+" ";
                        FSTRING = false;
                        stat = 15;
                    }
                    else if (TablaSimbolo[i].lexema.find("continuar") != string::npos){ //Sintax continue
                        sentencia = sentencia+"continue"+" ";
                        stat = 20;
                    }
                    else if (TablaSimbolo[i].lexema.find("romper") != string::npos){ //Sintax break
                        sentencia = sentencia+"break"+" ";
                        stat = 20;
                    }
                    else if (TablaSimbolo[i].lexema.find("para") != string::npos){ //Sintax for
                        sentencia = sentencia+"for"+" ";
                        stat = 21;
                    }
                    else if (TablaSimbolo[i].lexema.find("definir") != string::npos){ //Sintax def
                        sentencia = sentencia+"def"+" ";
                        stat = 21;
                        def = true;
                    }
                    else if (TablaSimbolo[i].lexema.find("retorno") != string::npos){ //Sintax return
                        if (retorno == true){
                            if (TablaSimbolo[i+1].lexema.find(';') != string::npos){
                                sentencia = sentencia+"return"+" ";
                                stat = 20;

                            }else{
                                sentencia = sentencia+"return"+" ";
                                stat = 26;
                            }}else{ sentencia = sentencia+"return"+" outside function";
                            sintaxError(msjsintaxError,line,sentencia,stat,i);
                        }  retorno = false;}
                }else if(TablaSimbolo[i].token.find("Identifier")!= string::npos){//Sintax Identifier
                    if (TablaSimbolo[i+1].lexema.find('(') != string::npos){ //Funtion declaration
                        stat = 24;
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        funtion = true;
                    }else{
                        aux = TablaSimbolo[i].lexema;
                        id = aux;
                        sentencia = sentencia+aux+" ";
                        declarados.push_back(aux);
                        stat = 6;
                    }
                }else if(TablaSimbolo[i].token.find("End")!= string::npos){//Sintax Error
                    if(sentencia.size()>0){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else{
                    stat = 0;
                }
                // cout<<"tokens "<<TablaSimbolo[i].lexema<<endl;
                break;
            case 1: //Operando 1
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                }else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 2;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){ //True and False
                    if (TablaSimbolo[i].lexema.find("Verdadero") != string::npos){
                        sentencia = sentencia+"True ";
                        stat = 2;
                    }else if (TablaSimbolo[i].lexema.find("Falso") != string::npos){
                        sentencia = sentencia+"False ";
                        stat = 2;
                    }else if (TablaSimbolo[i].lexema.find("no") != string::npos){
                        sentencia = sentencia+"not ";
                        stat = 3;
                    }else{
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 2: //Operador
                if (TablaSimbolo[i].token.find("RelationalOp") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("opIgualdad")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("TwoPoints")!= string::npos){
                    if (!pila.empty()) {
                        sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 3: //Operando 2
                if (TablaSimbolo[i-1].lexema.find("no") != string::npos){
                    stat = 5;
                }else{
                    stat = 4;
                }
                if (TablaSimbolo[i].token.find("Identifier")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";

                }else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";

                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";

                }else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){ //True and False
                    if (TablaSimbolo[i].lexema.find("Verdadero") != string::npos){
                        sentencia = sentencia+"True ";
                    }else if (TablaSimbolo[i].lexema.find("Falso") != string::npos){
                        sentencia = sentencia+"False ";
                    }else{
                        sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 4: //Fin de sentencia o continuacion.
                if (TablaSimbolo[i].token.find("TwoPoints")!= string::npos){
                    if (!pila.empty()) {
                        sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);}
                }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 13;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("y") != string::npos){
                        sentencia = sentencia+"and ";
                        stat = 1;
                    }else if (TablaSimbolo[i].lexema.find("alternativa") != string::npos){
                        sentencia = sentencia+"or ";
                        stat = 1;
                    }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 5:
                if (TablaSimbolo[i].token.find("TwoPoints")!= string::npos){
                    procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                }else if (TablaSimbolo[i].token.find("opIgualdad")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("RelationalOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 3;
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 6:  //Sintax Identifier
                if (TablaSimbolo[i].token.find("Assignment")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 8;
                }else if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 7;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 7;
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 7: //Asignation
                if (TablaSimbolo[i].token.find("Assignment")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 8;
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{      sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 8: //Operando 1
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    if (TablaSimbolo[i].lexema == id){
                        error = true;
                    }
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("Verdadero") != string::npos){
                        sentencia = sentencia+"True ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("Falso") != string::npos){
                        sentencia = sentencia+"False ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("entrada") != string::npos){
                        sentencia = sentencia+"input ";
                        stat = 15;
                    }else if (TablaSimbolo[i].lexema.find("continuar") != string::npos){
                        sentencia = sentencia+"continue ";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else if (TablaSimbolo[i].lexema.find("imprimir") != string::npos){
                        sentencia = sentencia+"print ";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else{
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("Data type")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("entero") != string::npos){
                        sentencia = sentencia+"int ";
                        datatype = datatype+"i";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("flotante") != string::npos){
                        sentencia = sentencia+"float ";
                        datatype = datatype+"f";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("booleano") != string::npos){
                        sentencia = sentencia+"bool ";
                        datatype = datatype+"b";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("cadena") != string::npos){
                        sentencia = sentencia+"str ";
                        datatype = datatype+"s";
                        stat = 11;}
                    if (type(datatype) == 0){ //Evalua si hay mas de un tipo de dato en una expresion
                        datatype = "";
                        //SemanticError
                        //agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,TablaSimbolo[i].lexema;
                        stat = 11;
                    }
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("Comilla")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 14;
                    pila.push('c');
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 9: //Operador
                if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 10;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 10;
                }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 12;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    if (!pila.empty() || error == true) {
                        if (error == true){
                            procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                            //SemanticError in if
                        }else{
                            sentencia = sentencia+TablaSimbolo[i].lexema;
                            sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    }else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{      sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                error = false;
                break;
            case 10:
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("Verdadero") != string::npos){
                        sentencia = sentencia+"True ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("Falso") != string::npos){
                        sentencia = sentencia+"False ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("entrada") != string::npos){
                        sentencia = sentencia+"input ";
                        stat = 15;
                    }else if (TablaSimbolo[i].lexema.find("continuar") != string::npos){
                        sentencia = sentencia+"continue ";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else if (TablaSimbolo[i].lexema.find("imprimir") != string::npos){
                        sentencia = sentencia+"print ";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else{       sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("Data type")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("entero") != string::npos){
                        sentencia = sentencia+"int ";
                        datatype = datatype+"i";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("flotante") != string::npos){
                        sentencia = sentencia+"float ";
                        datatype = datatype+"f";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("booleano") != string::npos){
                        sentencia = sentencia+"bool ";
                        datatype = datatype+"b";
                        stat = 11;
                    }else if (TablaSimbolo[i].lexema.find("cadena") != string::npos){
                        sentencia = sentencia+"str ";
                        datatype = datatype+"s";
                        stat = 11;}
                    if (type(datatype) == 0){ //Evalua si hay mas de un tipo de dato en una expresion
                        datatype = "";
                        //SemanticError
                        //agregarError(sintaxErrors, sentenciasErrors, line, sentencia, stat,i,TablaSimbolo[i].lexema;
                        stat = 11;
                    }
                }else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 11: //Case parent ( in var
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 9;
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("Verdadero") != string::npos){
                        sentencia = sentencia+"True ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("Falso") != string::npos){
                        sentencia = sentencia+"False ";
                        stat = 9;
                    }else if (TablaSimbolo[i].lexema.find("continuar") != string::npos){
                        sentencia = sentencia+"continue ";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else{sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 11;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 12: //Case parent ) in var
                if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 8;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 8;
                }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 12;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    if (!pila.empty()) {sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 13: //Case parent ) in conditional
                if (TablaSimbolo[i].token.find("RelationalOp") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("AdditionOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("opIgualdad")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 1;
                }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 13;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){
                    if (TablaSimbolo[i].lexema.find("y") != string::npos){
                        sentencia = sentencia+"and ";
                        stat = 1;
                    }else if (TablaSimbolo[i].lexema.find("alternativa") != string::npos){
                        sentencia = sentencia+"or ";
                        stat = 1;}
                }else if (TablaSimbolo[i].token.find("TwoPoints")!= string::npos){
                    if (!pila.empty()) { sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{       sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 14: //Strings ID
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 14;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 14;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 14;
                }
                else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 14;
                }
                else if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 14;
                }else if (TablaSimbolo[i].token.find("Comilla")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        sentencia=sentencia+" "+TablaSimbolo[i].lexema;
                        stat = 14;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    if (!pila.empty()) { sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 15: //print
                if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 16;
                    pila.push('(');
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 16: //" or f first in print
                if (TablaSimbolo[i].token.find("Comilla")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 17;
                    pila.push('c');
                }else if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    if (TablaSimbolo[i].lexema == "f"){ //Fstring valitation
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 19;
                        FSTRING = true;
                    }else{  sentencia = sentencia+TablaSimbolo[i].lexema+" ";
                        stat = 18; }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{
                    sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 17: //print string
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 17;
                } else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 17;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 17;
                }
                else if (TablaSimbolo[i].token.find("LeftKey")!= string::npos){
                    if (FSTRING == true){
                        pila.push('c');
                    }
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 17;
                }
                else if (TablaSimbolo[i].token.find("RightKey")!= string::npos){
                    if (FSTRING == true){
                        if (pila.empty()) {
                            sentencia=sentencia+TablaSimbolo[i].lexema;
                            sintaxError(msjsintaxError,line,sentencia,stat,i);}
                        else{
                            sentencia=sentencia+" "+TablaSimbolo[i].lexema;
                            stat = 17;
                            pila.pop();}
                    }else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux;
                        stat = 17;
                    }
                }
                else if (TablaSimbolo[i].token.find("Comilla")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        sentencia=sentencia+" "+TablaSimbolo[i].lexema;
                        stat = 18;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 18: //print and input end
                if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 18;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Comma")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 16;
                }else if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    if (!pila.empty()) { sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 19: //FSTRING
                if (TablaSimbolo[i].token.find("Comilla")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 17;
                    pila.push('c');
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 20: //continue and break and funtion ID sintax
                if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 21: //for and def Sintax
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    if(def == false){
                        stat = 22;
                    }
                    else{
                        stat = 24;
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 22: //in
                if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){ //in
                    if (TablaSimbolo[i].lexema.find("en") != string::npos){
                        sentencia = sentencia+"in ";
                        stat = 23;
                    }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 23: //range
                if (TablaSimbolo[i].token.find("Reserved word")!= string::npos){ //in
                    if (TablaSimbolo[i].lexema.find("rango") != string::npos){
                        sentencia = sentencia+"range ";
                        stat = 24;
                    }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 24: //Parameters
                if (TablaSimbolo[i].token.find("LeftParent")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 24;
                    pila.push('(');
                }
                else if (TablaSimbolo[i].token.find("Comma")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+",";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 24;
                        pila.pop();
                    }
                }
                else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+")";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        pila.pop();
                        sentencia = sentencia+aux+" ";
                        if (funtion == true){
                            stat = 20; funtion = false;  if (pila.size() > 0){pila.pop();}
                        }else{stat = 25;}
                    }
                }else if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 24;
                    pila.push('i');
                    if (def == false && funtion == false){ parameters++;}
                }else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    pila.push('1');
                    if (def == false && funtion == false){ parameters++;}
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    pila.push('.');
                    if (def == false && funtion == false){ parameters++;}
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;
            case 25: //END for and def
                if (TablaSimbolo[i].token.find("TwoPoints")!= string::npos ){
                    if (parameters > 3){
                        sentencia = sentencia+" range expected at most 3 arguments, got "+to_string(parameters);
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }else{
                        if (pila.empty()) {
                            if (def == true){ retorno = true;
                                procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                            }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                                sintaxError(msjsintaxError,line,sentencia,stat,i);}}
                        else{
                            pila.pop();
                            if (def == true){ retorno = true;}
                            procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                        }}
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                parameters = 0;
                def = false;
                break;
            case 26: //return sintax
                if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux;
                    stat = 26;
                    pila.push('i');
                }else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    pila.push('1');
                    stat = 26;
                }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    pila.push('.');
                    stat = 26;
                }else if (TablaSimbolo[i].token.find("Comma")!= string::npos){
                    if (pila.empty()) {
                        sentencia=sentencia+",";
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        aux = TablaSimbolo[i].lexema;
                        sentencia = sentencia+aux+" ";
                        stat = 26;
                        pila.pop();}
                }else if (TablaSimbolo[i].token.find("Semicolon")!= string::npos){
                    pila.pop();
                    if (!pila.empty()) { sentencia = sentencia+TablaSimbolo[i].lexema;
                        sintaxError(msjsintaxError,line,sentencia,stat,i);}
                    else{
                        procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                    }
                }else if (TablaSimbolo[i].token.find("End")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }else{   sentencia = sentencia+TablaSimbolo[i].lexema;
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
                break;

                // cout <<"Token: "<<element<<endl;
            }

        } //END Sintax Analysis

        //If there are errors
        if(msjsintaxError.size() > 0){
            return msjsintaxError;
        }else{ //If there are no errors
            return "<System: Syntax analysis completed with no errors>\n-Process finished with exit code 0.";

            //for(size_t i(0); i < sintaxNoErrors.size(); ++i)
            //{
            //    cout<<"Lexical analysis completed with no errors <"<<sentenciasNoErrors[i]<<"> "<<sintaxNoErrors[i]<<endl;
            //   if(i == sintaxNoErrors.size()-1){
            //        cout<<"-Process finished with exit code 0.";
            // }}
        }
}
