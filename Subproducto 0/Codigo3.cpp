#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
//AFD que acepta cadenas del lenguaje: {b*abb+}
    // Declarar un puntero a un archivo
    FILE* fichero;
    // Abrir el archivo "prueba.txt" en modo lectura de texto
    fichero = fopen("prueba.txt", "rt");
    // Declarar una matriz de transiciones
    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}};
    // Declarar una variable para el símbolo leído del archivo
    int simbolo;
    // Inicializar el estado a 0
    int estado = 0; 
    // Iniciar un bucle que se ejecuta mientras el estado no sea igual a 3
    while (estado != 3) {
        // Imprimir un mensaje
        std::cout << "La nueva entrada: ";
        // Leer un carácter del archivo y almacenarlo en la variable simbolo
        fscanf(fichero, "%c", &simbolo);
        // Imprimir el carácter leído
        std::cout << (char) simbolo << "\n";
        // Convertir el carácter leído restando 'a' para obtener un valor numérico
        simbolo = simbolo - 'a';
        // Actualizar el estado según la matriz de transiciones
        estado = MT[estado][simbolo];
        // Imprimir el nuevo estado
        std::cout << estado << "\n";
    }
    // Cerrar el archivo
    fclose(fichero);
    // Retornar 0 para indicar una finalización exitosa del programa
    return 0;
}
