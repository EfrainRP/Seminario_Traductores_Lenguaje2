#include "mainwindow.h"
#include <stack>
#include <algorithm>

using namespace std;

//Function AdditionOp + and - (Validates the hierarchy of addition and subtraction)
vector<vector<string>> AddOp(vector<string> entrada, int cont, vector<vector<string>> expression){
    string op,op2,temp,x; //res
    vector<string> vec;
    for(int i(0); i < entrada.size(); ++i){     //For each element of the input (lexemes)
        if(entrada[i].find(';')!= string::npos){ //Final case when finding the result Ex: x = var;
            op = entrada[i-1];
            x = entrada[i-3];
            expression.push_back({"LOAD",op,x});
            return expression;
        }
        if(entrada[i].find('+')!= string::npos || entrada[i].find('-')!= string::npos){ //When finding + or -
            if(entrada[i].find('+')!= string::npos){ //When finding "+"
                if(entrada[i].size() == 1){            //Validate that the entry only has one symbol "+"
                    cont++;
                    op = entrada[i-1];                     //The left operand of the operator is taken Ex: "op + op2" where "op" was taken
                    if(op[0] != 'T'){                      //If the operand hasn't been loaded previously
                        vec.push_back("LOAD");
                        vec.push_back(op);
                        op = "V"+to_string(cont);
                        vec.push_back(op);
                        expression.push_back(vec);
                        vec.clear();
                    }else{                                 //Opposite case
                        op = "T"+to_string(cont-1);
                    }
                    op2 = entrada[i+1];                    //The right operand of the operator is taken Ex: "op + op2" where "op2" was taken
                    if(op2[0] != 'T'){                     //If the operand 2 hasn't been loaded previously
                        vec.push_back("LOAD");
                        vec.push_back(op2);
                        op2 = "R"+to_string(cont);
                        vec.push_back(op2);
                        expression.push_back(vec);
                        vec.clear();
                    }else{                                 //Opposite case
                        op2 = "T"+to_string(cont-1);
                    }
                    vec.push_back("ADD");
                    vec.push_back(op);
                    vec.push_back(op2);
                    string aux = "T"+to_string(cont);
                    vec.push_back(aux);
                    expression.push_back(vec);
                    vec.clear();
                    entrada.erase(entrada.begin() + i-1);  //Replaces the new result into the vector Ex: "op + op2" = "T1"
                    entrada.erase(entrada.begin() + i-1);
                    temp = "T"+to_string(cont);
                    entrada[i-1] = temp;                   //The result is stored after the previous ones have been deleted
                    expression=AddOp(entrada,cont,expression);           //Call the function to see if the new entry has an "+ or -"
                    return expression;
                }
            }else{                                  //When finding "-"
                if(entrada[i].size() == 1){          //Validate that the entry only has one symbol "-"
                    cont++;
                    op = entrada[i-1];                     //The left operand of the operator is taken Ex: "op - op2" where "op" was taken
                    if(op[0] != 'T'){                      //If the operand hasn't been loaded previously
                        vec.push_back("LOAD");
                        vec.push_back(op);
                        op = "V"+to_string(cont);
                        vec.push_back(op);
                        expression.push_back(vec);
                        vec.clear();
                    }else{                                //Opposite case
                        op = "T"+to_string(cont-1);
                    }
                    op2 = entrada[i+1];                    //The right operand 2 of the operator is taken Ex: "op - op2" where "op2" was taken
                    if(op2[0] != 'T'){                     //If the operand 2 hasn't been loaded previously
                        //cout<<"LOAD\t\t"<<op2<<"\t\t\t\tR"<<cont<<endl;
                        vec.push_back("LOAD");
                        vec.push_back(op2);
                        op2 = "R"+to_string(cont);
                        vec.push_back(op2);
                        expression.push_back(vec);
                        vec.clear();
                    }else{                                 //Opposite case
                        op2 = "T"+to_string(cont-1);
                    }
                    vec.push_back("SUB");
                    vec.push_back(op);
                    vec.push_back(op2);
                    string aux = "T"+to_string(cont);
                    vec.push_back(aux);
                    expression.push_back(vec);
                    vec.clear();
                    entrada.erase(entrada.begin() + i-1);  //Replaces the new result into the vector Ex: "op - op2" = "T1"
                    entrada.erase(entrada.begin() + i-1);
                    temp = "T"+to_string(cont);
                    entrada[i-1] = temp;                   //The result is stored after the previous ones have been deleted

                    expression=AddOp(entrada,cont,expression);           //Call the function to see if the new entry has an "+ or -"
                    return expression;
                }}
        }
    }
}

//MultipliOp / and * (Validate the hierarchy of multiplication and division)
vector<vector<string>> MultOp(vector<string> entrada, int cont, vector<vector<string>> expression){
    string op,op2,temp; //res
    vector<string> vec;
    for(int i(0); i < entrada.size(); ++i){           //For each element of the input (lexemes)
        if(entrada[i].find(';')!= string::npos){       //Final case when finding "* or /"
            expression = AddOp(entrada,cont,expression);              //Call the function to see if the new entry has an "+ or -"
            return expression;
        }
        if(entrada[i].find('/')!= string::npos || entrada[i].find('*')!= string::npos){ //When finding "/" or "*"
            if(entrada[i].find('/')!= string::npos){              //When finding "/"
                cont++;
                op = entrada[i-1];                                  //The left operand of the operator is taken Ex: "op / op2" where "op" was taken
                if(op[0] != 'T'){                                   //If the operand hasn't been loaded previously
                    vec.push_back("LOAD");
                    vec.push_back(op);
                    op = "V"+to_string(cont);
                    vec.push_back(op);
                    expression.push_back(vec);
                    vec.clear();
                }else{                                              //Opposite case
                    op = "T"+to_string(cont-1);
                }
                op2 = entrada[i+1];                                 //The right operand of the operator is taken Ex: "op / op2" where "op2" was taken
                if(op2[0] != 'T'){                                  //If the operand 2 hasn't been loaded previously
                    vec.push_back("LOAD");
                    vec.push_back(op2);
                    op2 = "R"+to_string(cont);
                    vec.push_back(op2);
                    expression.push_back(vec);
                    vec.clear();
                }else{                                              //Opposite case
                    op2 = "T"+to_string(cont-1);
                }
                vec.push_back("DIV");
                vec.push_back(op);
                vec.push_back(op2);
                string aux = "T"+to_string(cont);
                vec.push_back(aux);
                expression.push_back(vec);
                vec.clear();
                entrada.erase(entrada.begin() + i-1);               //Replaces the new result into the vector Ex: "op / op2" = "T1"
                entrada.erase(entrada.begin() + i-1);
                temp = "T"+to_string(cont);
                entrada[i-1] = temp;                                //The result is stored after the previous ones have been deleted

                expression=MultOp(entrada,cont, expression);                       //Call the function to see if the new entry has an "/ or *"
                return expression;
            }else{                                                //When finding "*"
                cont++;
                op = entrada[i-1];                                  //The left operand of the operator is taken Ex: "op * op2" where "op" was taken
                if(op[0] != 'T'){                                   //If the operand hasn't been loaded previously
                    vec.push_back("LOAD");
                    vec.push_back(op);
                    op = "V"+to_string(cont);
                    vec.push_back(op);
                    expression.push_back(vec);
                    vec.clear();
                }else{                                              //Opposite case
                    op = "T"+to_string(cont-1);
                }
                op2 = entrada[i+1];                                 //The right operand of the operator is taken Ex: "op * op2" where "op2" was taken
                if(op2[0] != 'T'){                                  //If the operand 2 hasn't been loaded previously
                    vec.push_back("LOAD");
                    vec.push_back(op2);
                    op2 = "R"+to_string(cont);
                    vec.push_back(op2);
                    expression.push_back(vec);
                    vec.clear();
                }else{                                              //Opposite case
                    op2 = "T"+to_string(cont-1);
                }
                vec.push_back("MUL");
                vec.push_back(op);
                vec.push_back(op2);
                string aux = "T"+to_string(cont);
                vec.push_back(aux);
                expression.push_back(vec);
                vec.clear();
                entrada.erase(entrada.begin() + i-1);              //Replaces the new result into the vector Ex: "op * op2" = "T1"
                entrada.erase(entrada.begin() + i-1);
                temp = "T"+to_string(cont);
                entrada[i-1] = temp;                               //The result is stored after the previous ones have been deleted

                expression=MultOp(entrada,cont,expression);                      //Call the function to see if the new entry has an "/ or *"
                return expression;
            }
        }

    }
}

//DataType
bool type(const string &cadena){ //Evalua si hay mas de un tipo de dato en una expresion para el analizador sintatico
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
//SemanticError
void semanticError(vector<string>& semanticErrors, vector<int>& sentenciasErrors, int& line, string& sentencia, int& stat,int& i, string& lexemas) {
    //string aux = lexemas);
    //sentencia = sentencia + aux + " ";
    semanticErrors.push_back(sentencia);
    sentenciasErrors.push_back(line);
    line++;
    //i--;
    sentencia = "";
    stat = 0;
}
//Mensaje SintaxError
void sintaxError(string& msjsintaxError, int& line, string& sentencia, int& stat,int& i) {
    msjsintaxError = ">SyntaxError: invalid syntax "+msjsintaxError+"\""+sentencia+"\""+"\n in LINE --> <"+to_string(line)+">\n -Process finished with exit code 0.";
    i = 500; //Maximo de tokens
    stat = 0;
}
//Mensaje NoSintaxErrors
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
//Declaraciones en la tabla de simbolos
bool declarationError(vector<string>& vec,string& elemento){ //Busca una declaracion en la tabla de simbolos
    auto it = find(vec.begin(), vec.end(), elemento); //find busca el elemento desde .begin() hasta .end() en el vector
    if (it != vec.end()) { //Si it no es igual al final del vector, se encontro una coincidencia
        return true;
    } else { //Si it = vec.end() (final del vector), no se encontro una coincidencia
        return false;
    }
}

string funcionSintaticoSemantico(vector<tablaSimbolo>& TablaSimbolo, int flagNum){
    size_t i = 0;
    while (i < TablaSimbolo.size()) {   //Busca un "Unidentified", para mandar un mensaje de error, evitando el syntaxAnalyzer
        if(TablaSimbolo[i].token.find("Unidentified") != string::npos)
        {
            string ErrorLexical = "Lexical error in: "+TablaSimbolo[i].lexema+"\n-Process finished with exit code 0.";
            qCritical()<<ErrorLexical;
            if(flagNum==1){
                return ErrorLexical;
            }else{
                return " ";
            }
        }
        i++;
    }

    ///Sintax Analyzer
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

    ///Semantic Analyzer
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
    bool error = false; //ID error
    bool second = true; //Second ID

    for(int i(0); i < TablaSimbolo.size(); ++i) //for each token in tokens size
    {
        switch(stat)                 //Initial state SA = 0
        {
        case 0:
            //cout<<"Mi lexema actual caso 0: "<<TablaSimbolo[i].lexema<<it<<" Sentencia "<<sentenceError<<endl;
            //cin.get();
            if (it == false){ //NO SEMANTIC ERROR
                parameters = 0; //Parameters for
                def = false;    //def flag
                aux_id = "";    //Fist ID
                count_parameters = 0; //def parameters
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
                        aux = TablaSimbolo[i].lexema;
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
                        aux = TablaSimbolo[i].lexema;
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
                }else if(TablaSimbolo[i].token.find("End")!= string::npos){//Sintax Error
                    if(sentencia.size()>0){
                        sintaxError(msjsintaxError,line,sentencia,stat,i);
                    }
                }else{
                    stat = 0;
                }
                // cout<<"tokens "<<TablaSimbolo[i].lexema<<endl;
            }else{ //SEMANTIC ERROR
                if (TablaSimbolo[i].lexema.find(';') != string::npos){
                    //cout<<"Semicolon ; encontrado"<<endl;
                    it = false;
                    semanticError(semanticErrors,sentenciasErrors,line,sentenceError,stat,i,TablaSimbolo[i].lexema);
                    sentencia = "";
                }else if(TablaSimbolo[i].lexema.find(':') != string::npos){
                    //cout<<"TwoPoints : encontrado"<<endl;
                    it = false;
                    semanticError(semanticErrors,sentenciasErrors,line,sentenceError,stat,i,TablaSimbolo[i].lexema);
                    sentencia = "";
                }else{
                    //cout<<"Lexema brincado: "<<TablaSimbolo[i].lexema<<endl;
                    aux = TablaSimbolo[i].lexema;
                    sentenceError = sentenceError+aux+" ";
                }
                //cin.get();
            }
            break;
        case 1: //Operando 1
            if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                aux = TablaSimbolo[i].lexema;
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
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                if(TablaSimbolo[i-1].token.find("AdditionOp")!= string::npos || TablaSimbolo[i-1].token.find("MultiplOp")!= string::npos){
                    sintaxError(msjsintaxError,line,sentencia,stat,i);
                }
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
                if((TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('0')!= string::npos && (TablaSimbolo[i+2].token.find("opIgualdad")!= string::npos || TablaSimbolo[i+2].token.find("RelationalOp")!= string::npos || TablaSimbolo[i+2].lexema.find(':')!= string::npos || TablaSimbolo[i+2].lexema.find("y") != string::npos || TablaSimbolo[i+2].lexema.find("or") != string::npos))){
                    sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
            }else if (TablaSimbolo[i].token.find("opIgualdad")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                stat = 3;
            }else if (TablaSimbolo[i].token.find("RightParent")!= string::npos){
                if (pila.empty()) {
                    sentencia=sentencia+")";
                    sintaxError(msjsintaxError,line,sentencia,stat,i);}
                else{
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 2;
                    pila.pop();}
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
                found = declarationError(declarados,aux);
                if(found == false){ //SemanticError
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }

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
        case 4: //Fin de sentencia o continuacion if, elif, else, while.
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

                if((TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('0')!= string::npos && (TablaSimbolo[i+2].token.find("opIgualdad")!= string::npos || TablaSimbolo[i+2].token.find("RelationalOp")!= string::npos || TablaSimbolo[i+2].lexema.find(':')!= string::npos || TablaSimbolo[i+2].lexema.find("y") != string::npos || TablaSimbolo[i+2].lexema.find("or") != string::npos))){
                    sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
        case 5: //Operador logico not
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
                stat = 9;
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                found = declarationError(declarados,aux);
                if(found == false){ //SemanticError
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                sentencia = sentencia+aux+" ";
                stat = 10;
            }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                stat = 10;
                if((TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('0')!= string::npos && TablaSimbolo[i+2].lexema.find(';')!= string::npos) || (TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('(')!= string::npos && TablaSimbolo[i+2].lexema.find('0')!= string::npos && TablaSimbolo[i+3].lexema.find(')')!= string::npos && TablaSimbolo[i+4].lexema.find(';')!= string::npos)){
                    sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                    if (error == true){ datatype = "";
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
                found = declarationError(declarados,aux);
                if(found == false){ //SemanticError
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                found = declarationError(declarados,aux);
                if(found == false){ //SemanticError
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                sentencia = sentencia+aux+" ";
                stat = 8;
            }else if (TablaSimbolo[i].token.find("MultiplOp")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                stat = 8;
                if((TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('0')!= string::npos && TablaSimbolo[i+2].lexema.find(';')!= string::npos) || (TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('(')!= string::npos && TablaSimbolo[i+2].lexema.find('0')!= string::npos && TablaSimbolo[i+3].lexema.find(')')!= string::npos && TablaSimbolo[i+4].lexema.find(';')!= string::npos)){
                    sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
                else{ datatype = "";
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
                if((TablaSimbolo[i].lexema.find('/')!= string::npos && TablaSimbolo[i+1].lexema.find('0')!= string::npos && (TablaSimbolo[i+2].token.find("opIgualdad")!= string::npos || TablaSimbolo[i+2].token.find("RelationalOp")!= string::npos || TablaSimbolo[i+2].lexema.find(':')!= string::npos || TablaSimbolo[i+2].lexema.find("y") != string::npos || TablaSimbolo[i+2].lexema.find("or") != string::npos))){
                    sentenceError = sentenceError+"ZeroDivisionError: division by zero. "+sentencia;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
        case 15: //print and input
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
                }else{
                    aux = TablaSimbolo[i].lexema;
                    sentencia = sentencia+aux+" ";
                    stat = 18;
                    found = declarationError(declarados,aux);
                    if(found == false){ //SemanticError
                        sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                        //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                        it = true;
                        stat = 0;
                        while (!pila.empty()) {
                            pila.pop(); // Vacia la pila
                        }
                    }
                    if(TablaSimbolo[i].lexema == aux_id){ //Same ID declaration Error
                        sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                        it = true;
                        stat = 0;
                        while (!pila.empty()) {
                            pila.pop(); // Vacia la pila
                        }
                    }
                }
            }else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux;
                stat = 18;
            }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux;
                stat = 18;
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
                    declarados_def.push_back(aux);
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
                        stat = 20; funtion = false;  if (pila.size() > 0){pila.pop();
                            if(declarationError(declarados_def,aux_def) == true){
                                for(int i(0); i < declarados_def.size(); ++i){
                                    if(declarados_def[i] == aux_def){
                                        if(parameters_def[i] != count_parameters){
                                            int pd = parameters_def[i];
                                            sentenceError = sentenceError+"TypeError: "+aux_def+" requires <"+to_string(pd)+"> arguments and got <"+to_string(count_parameters)+">. "+sentencia;
                                            //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
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
            }else if (TablaSimbolo[i].token.find("Identifier") != string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";;
                stat = 24;
                pila.push('i');
                count_parameters++;
                if (def == false && funtion == false){ parameters++;}
                if(def == false){
                    found = declarationError(declarados,aux);
                    if(found == false){ //SemanticError
                        sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                        //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                        it = true; retorno = true;
                        stat = 0;
                        while (!pila.empty()) {
                            pila.pop(); // Vacia la pila
                        }
                    }
                    if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                        sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                        it = true; retorno = true;
                        stat = 0;
                        second = true;
                        while (!pila.empty()) {
                            pila.pop(); // Vacia la pila
                        }
                    }}
            }else if (TablaSimbolo[i].token.find("Integer")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                pila.push('1');
                count_parameters++;
                if (def == false && funtion == false){ parameters++;}
            }else if (TablaSimbolo[i].token.find("Real")!= string::npos){
                aux = TablaSimbolo[i].lexema;
                sentencia = sentencia+aux+" ";
                pila.push('.');
                count_parameters++;
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
                            parameters_def.push_back(count_parameters);
                            procesarDatos(TablaSimbolo[i].lexema, sentencia, sintaxNoErrors, sentenciasNoErrors, line, stat);
                        }else{ sentencia = sentencia+TablaSimbolo[i].lexema;
                            sintaxError(msjsintaxError,line,sentencia,stat,i);}}
                    else{
                        pila.pop();
                        if (def == true){ retorno = true; parameters_def.push_back(count_parameters);
                        }
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
                sentencia = sentencia+aux+" ";
                stat = 26;
                pila.push('i');
                found = declarationError(declarados,aux);
                if(found == false){ //SemanticError
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    //semanticError(semanticErrors,sentenciasErrors,line,sentencia,stat,i,TablaSimbolo[i].lexema;
                    it = true;
                    stat = 0;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
                if(TablaSimbolo[i].lexema == aux_id && second == false){ //Same ID declaration Error
                    sentenceError = sentenceError+"NameError: name "+aux+" is not defined. "+sentencia;
                    it = true;
                    stat = 0;
                    second = true;
                    while (!pila.empty()) {
                        pila.pop(); // Vacia la pila
                    }
                }
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
        }

    } //END Analysis

    //If there are no semantic errors
    string msjSemanticError="";
    if(flagNum == 1){ ///Syntaxis Analysis
        if(msjsintaxError.size() <= 0){ //If there are no errors
            msjsintaxError = "<System: Syntax analysis completed with no errors>\n-Process finished with exit code 0.";
        }
        return msjsintaxError;
    }else if(flagNum == 2){///Semantic Analysis
        if(msjsintaxError.size() <= 0){//If there are no sintatic errors
            if(!semanticErrors.empty()){ //If there are semantic errors
                msjSemanticError += ">SemanticError: \n";
                for(int i(0); i < semanticErrors.size(); ++i){
                    msjSemanticError += "- In line <"+ to_string(sentenciasErrors[i]) + ">: " + semanticErrors[i] + "\n\n";
                }
            }else{//If there are no semantic errors
                msjSemanticError="< System: Semantic analysis completed with no errors. >\n-Process finished with exit code 0.\n";
            }
        }
        return msjSemanticError;
    }
    else if (flagNum == 3){
        string codeEND;

        if(semanticErrors.empty()){//If there are no semantic errors
            int generate_code = 1;
            for(int i(0); i < TablaSimbolo.size(); ++i){ //Compatible source code
                if(TablaSimbolo[i].token.find("Assignment")!= string::npos || TablaSimbolo[i].token.find("AdditionOp")!= string::npos || TablaSimbolo[i].token.find("Identifier")!= string::npos || TablaSimbolo[i].token.find("Integer")!= string::npos || TablaSimbolo[i].token.find("MultiplOp")!= string::npos || TablaSimbolo[i].token.find("Semicolon")!= string::npos || TablaSimbolo[i].token.find("End")!= string::npos || TablaSimbolo[i].token.find("Real")!= string::npos){
                    continue;
                }
                else{ //Code generated error
                    generate_code = 0;
                    break;
                }
            }
            if(generate_code){ //If validate to generate the code
                //Send the expressions to generate intermediate code
                string entrada;
                vector<string> sentence;
                vector<vector<string>> expression;
                vector<vector<string>> codigo = {{".CODE","  ;   Code start"}};
                //Instructions used --> .CODE, LOAD, ADD, SUB, MOV, DIV, END, ;
                for(int i(0); i < TablaSimbolo.size(); ++i){
                    sentence.push_back(TablaSimbolo[i].lexema);
                    if(TablaSimbolo[i].lexema.find(';')!= string::npos){ //Being a declaration of value, it is omitted Ex: x = 2;
                        if (TablaSimbolo[i-2].lexema.find('=')!= string::npos){
                            sentence.clear();
                            continue;
                        }
                        for (string element : sentence) { //For each lexeme up to ";"
                            entrada = entrada+element+" ";
                        }
                        codigo.push_back({" "});
                        codigo.push_back({" ;  Entrada --> ",entrada});

                        vector<vector<string>> codigo_expresion = MultOp(sentence,0,expression);            //Returns the generated code of an expression
                        sentence.clear();                                                                  //Clean for the next expression
                        entrada = "";
                        for(int i(0); i < codigo_expresion.size(); ++i){    //The generated code of the expression is added to the code
                            codigo.push_back(codigo_expresion[i]);
                        }
                    }
                }

                codigo.push_back({"END"," ;    Code end"});

                for(int i(0); i < codigo.size(); ++i){          //For each generated code statement
                    for(int j(0); j < codigo[i].size(); j++){

                        codeEND += codigo[i][j] + "\t";                // <-- Generated Code
                    }
                    codeEND += "\n";
                }
            }else{ //Code generated error
                codeEND = ">System: The generated code is incompatible.";
            }
        }
        return codeEND;//Regresara la cadena del generador de codigo
    }
}
