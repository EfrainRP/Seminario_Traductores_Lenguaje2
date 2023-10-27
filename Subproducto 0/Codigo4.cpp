#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Abre el archivo "prueba.txt" para lectura
    std::ifstream fichero("prueba.txt");
    // Verifica si el archivo se ha abierto correctamente
    if (!fichero.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1; // Sale del programa con un código de retorno 1 en caso de fallo
    }

    // Declara una matriz de transiciones para un autómata finito
    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}};
    char simbolo;
    int estado = 0;

    // Inicia un bucle que se ejecuta mientras el estado no sea igual a 3 y se puedan obtener caracteres del archivo
    while (estado != 3 && fichero.get(simbolo)) {
        // Imprime el carácter leído
        std::cout << "La nueva entrada: " << simbolo << std::endl;
        // Calcula el índice del carácter en la matriz de transiciones
        int simboloIndex = simbolo - 'a';
        // Comprueba si el carácter es desconocido y muestra un mensaje de error si es así
        if (simboloIndex < 0 || simboloIndex > 1) {
            std::cerr << "Caracter desconocido: " << simbolo << std::endl;
            return 1; // Sale del programa con un código de retorno 1
        }
        // Actualiza el estado del autómata usando la matriz de transiciones
        estado = MT[estado][simboloIndex];
        // Imprime el nuevo estado
        std::cout << estado << std::endl;
    }

    // Cierra el archivo después de haber terminado de procesarlo
    fichero.close();
    // Retorna 0 para indicar una finalización exitosa del programa
    return 0;
}
