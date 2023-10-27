#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de tokens
enum Token {
    TOKEN_LETRA_A,        // Definición del token para la letra 'a'
    TOKEN_LETRA_B,        // Definición del token para la letra 'b'
    TOKEN_FINAL,          // Definición del token para el final de línea o archivo
    TOKEN_DESCONOCIDO     // Definición del token para caracteres desconocidos
};

int main(int argc, char** argv) {
    FILE* fichero;
    fichero = fopen("prueba.txt", "rt");    // Abre el archivo "prueba.txt" en modo lectura
    if (!fichero) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;  // Si no se pudo abrir el archivo, muestra un mensaje de error
        return 1;
    }

    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}}; // Matriz de transición del autómata
    char simbolo;   // Variable para almacenar el caracter actual
    int estado = 0; // Estado inicial del autómata

    // Ciclo para procesar la secuencia de caracteres
    while (estado != 3 && fscanf(fichero, "%c", &simbolo) != EOF) {
        std::cout << "La nueva entrada: " << simbolo << std::endl;

        Token token;    // Variable para almacenar el tipo de token

        // Determina el tipo de token basado en el caracter leído
        if (simbolo == 'a') {
            token = TOKEN_LETRA_A;
        } else if (simbolo == 'b') {
            token = TOKEN_LETRA_B;
        } else if (simbolo == '\n' || simbolo == '\r' || simbolo == EOF) {
            token = TOKEN_FINAL;
        } else {
            token = TOKEN_DESCONOCIDO;
        }

        // Actualiza el estado del autómata usando la matriz de transición
        estado = MT[estado][token];

        // Muestra información sobre el token y el estado actual
        std::cout << "Token: " << token << ", Estado: " << estado << std::endl;
    }

    fclose(fichero);    // Cierra el archivo
    return 0;           // Finaliza el programa
}
