#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    //CODIGO QUE IMPLEMENTA UN AFD (cambia sus estados en funcion a las entradas dadas por el archivo, buscando la aceptacion)
//Cadenas que acepta: 1*011+
    FILE* fichero;                          //Crea un apuntador para el archivo
    fichero = fopen("prueba.txt", "rt");    //Entra en modo de lectura solo si existe el archivo
    int MT[3][2] = {{1,0},{-1,2},{-1,3}};   //Matriz de transicion, -1 es estado de NO aceptacion  
    int simbolo;
    int estado = 0;

    while(estado != 3){ //Hasta terminar en el estado 3
        std::cout << "La nueva entrada "; 
        fscanf(fichero, "%c", &simbolo);    //obtiene el caracter del archivo
        simbolo = simbolo - '0';            //Convierte los caracteres del archivo a valores enteros, con una conversion ASCII de '0'
        std::cout << "es: "<< simbolo << "\n";//Imprime el valor entero en pantalla
        estado = MT[estado][simbolo];       //Actualiza el estado segun la matriz, , fila=estado,columna=simbolo de entrada
        std::cout << estado << "\n";        //Imprime el estado en el que se encuentra en el AFD
    }
     //Ex.Regular 1*011+
    fclose(fichero);//Cierra el archivo
    return 0;
