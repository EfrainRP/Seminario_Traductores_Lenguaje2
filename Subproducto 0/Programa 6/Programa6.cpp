#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
// Definición de tokens
enum Token
{
    TOKEN_IDENTIFICADOR,//valor de 0
    TOKEN_ASIGNACION,//valor de 1
    TOKEN_ENTERO,//valor de 2
    TOKEN_SUMA,//valor de 3
    TOKEN_FIN//valor de 4
};
// Función para obtener el siguiente token
enum Token obtenerToken(char *lexema)
{
    int c = getchar();//Obtendra el caracter, 
                    //pero haste que se presione el enter se ejecutara la siguiente instruccion
    if (c == 'a'){  //A travez de estos IFs anidados se va ir copiando los 
        strcpy(lexema, "a");    //caracteres predeterminados para su respectivo analisis con los tokens
        return TOKEN_IDENTIFICADOR;
    }
    else if (c == '='){
        strcpy(lexema, "=");//Copiando el caracter al lexema, la une
        return TOKEN_ASIGNACION;
    }
    else if (isdigit(c)){
        ungetc(c, stdin); //retorna el carácter apilado después de la conversión. (lo apila)
        scanf("%s", lexema);
        return TOKEN_ENTERO;
    }
    else if (c == '+'){
        strcpy(lexema, "+");
        return TOKEN_SUMA;
    } else if (c == '\n' || c == EOF) {
        return TOKEN_FIN;
    } else {
        strcpy(lexema, "DESCONOCIDO");
        return TOKEN_FIN;
    }
}
int main()
{
    char lexema[100];//Definicion un arreglo de caracter
    enum Token token;//Definicion de la palabra token
    std::cout << "Escribe: ";//Mensaje para la entrada de datos

    do{//Ciclo para analizar caracter por caracter la expresion hasta que no cumpla la condicion, 
        //terminara cuando llegue al token de fin (valor de 4)
        token = obtenerToken(lexema);   //Funcion para ingresar expresion, 
                                        //mandando el arreglo de caracter como parametro
        printf("Token: %d, Lexema: %s\n", token, lexema); //Imprime cada token con su respectivo lexema
    } while (token != TOKEN_FIN);//Terminara cuando llegue al token de fin (con valor de 4)

    return 0;
}