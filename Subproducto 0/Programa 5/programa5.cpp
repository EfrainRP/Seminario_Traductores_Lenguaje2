#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Definición de tokens
enum Token{
    TOKEN_LETRA_A,//valor de 0
    TOKEN_LETRA_B,//valor de 1
    TOKEN_FINAL,//valor de 2
    TOKEN_DESCONOCIDO //valor de 3
};

int main(int argc, char **argv){
    //CODIGO QUE IMPLEMENTA UNA MAQUINA DE ESTADOS FINITOS (cambia sus estados en funcion a las entradas dadas por el archivo) mediante la bibliteca de tokens
    FILE *fichero;                  //Crea un apuntador para el archivo
    fichero = fopen("prueba.txt", "rt"); //Entra en modo de lectura solo si existe el archivo
    if (!fichero) {//Verificacion de apertura correcta del archivo
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}}; //Matriz de transiciones
    char simbolo;
    int estado = 0;
    while (estado != 3 && fscanf(fichero, "%c", &simbolo) != EOF){ //Hasta terminar en el estado 3 y ya encuentre el final del archivo
        std::cout << "La nueva entrada: " << simbolo << std::endl; //Imprime el valor del caracter en pantalla
        Token token; //Se define variable para los tokens (identificadores) para cada caracter de nuestra gramatica, como si fuera un arreglo unidireccional
        if (simbolo == 'a'){    //Condicionales para asignar un valor (entero del arreglo) mediante los tokens
            token = TOKEN_LETRA_A;
        }
        else if (simbolo == 'b'){
            token = TOKEN_LETRA_B;
        }
        else if (simbolo == '\n' || simbolo == '\r' || simbolo == EOF){
            token = TOKEN_FINAL;
        }
        else{
            token = TOKEN_DESCONOCIDO;
        }
        estado = MT[estado][token]; //Actualiza el estado segun la matriz, , fila=estado,columna=simbolo de entrada
        std::cout << "Token: " << token << ", Estado: " << estado << std::endl; //Imprime el valor del token (del arreglo unidireccional) y el estado que se encuentra 
    }
            //Ex.Regular b*abbb*
    fclose(fichero); //Cierra el archivo
    return 0;
}