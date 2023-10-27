#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

//SIMPLE ANALIZADOR LEXICO

// Definición de tokens
enum Token {
TOKEN_IDENTIFICADOR, //0 Example: [A-Za-z]
TOKEN_ASIGNACION,    //1 Example: =
TOKEN_ENTERO,        //2 Example: \d
TOKEN_SUMA,          //3 Example: +
TOKEN_FIN            //4 Example: \n
};
// Función para obtener el siguiente token
enum Token obtenerToken(char* lexema) {             //Analiza cada caracter y determina el tipo de Token
int c = getchar();              //Lee un caracter y lo almacena

if (c == 'a') {                 //Si el caracter es a
strcpy(lexema, "a");            //El contenido "a" se copiara al arreglo lexema, para ser representado y mostrado
return TOKEN_IDENTIFICADOR;     //Regresa el tipo de Token identificador = 0

} else if (c == '=') {          //Si el caracter es =

strcpy(lexema, "=");            //El contenido "=" se copiara al arreglo lexema, para ser representado y mostrado
return TOKEN_ASIGNACION;        //Regresa el tipo de Token asignacion = 1

} else if (isdigit(c)) {        //Si el caracter es cualquier digito [\d]

ungetc(c, stdin);               //Devuelve un caracter al flujo de entrada
scanf("%c", lexema);            //Lee una secuencia completa de digitos, y la almacena en lexema, para ser mostrada
                                //Al modificarse "%s" por "%c" permite que se muestre el Token por cada caracter

return TOKEN_ENTERO;            //Regresa el tipo de Token entero = 2

} else if (c == '+') {          //Si el caracter es +

strcpy(lexema, "+");            //El contenido "+" se copiara al arreglo lexema, para ser representado y mostrado
return TOKEN_SUMA;              //Regresa el tipo de Token Suma = 3

} else if (c == '\n' || c == EOF) {     //Si el caracter es un salto de linea o es el fin del flujo de entrada

strcpy(lexema, "\n");           //Al ser el ultimo Token, el lexema contiene un salto de linea, indicando el fin de flujo de entrada
return TOKEN_FIN;               //Regresa el tipo de Token Fin de flujo = 4

} else {

strcpy(lexema, "DESCONOCIDO"); //El contenido "DESCONOCIDO" se copiara al arreglo lexema, indicando que no es un Token valido (0-3)
return TOKEN_FIN;              //Regresa el tipo de Token Fin de flujo = 4
}
}
//------------------------------------------------------------------------------
int main() {

char lexema[100];
enum Token token;
cout<<"escribe: ";

do {

token = obtenerToken(lexema);                       //Se llama la funcion por cada caracter para determinar su tipo de Token
                                                    //y lexema asociado
printf("Token: %d, Lexema: %s\n", token, lexema);   //Imprime el Token y el Lexema asociado

} while (token != TOKEN_FIN);                       //Mientras el Token no sea el fin de flujo de entrada

printf("Token: 4 Fin\n");
return 0;
}
