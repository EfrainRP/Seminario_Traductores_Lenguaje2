#include <iostream>
using namespace std;
int main (int argc, char** argv) {
//CODIGO QUE IMPLEMENTA UNA MAQUINA DE ESTADOS FINITOS (cambia sus estados en funcion a las entradas dadas)
int MT [3][2] = {{1,0}, {1,2}, {0,3}};  //Se crea una matriz de 3x2 con los valores dados
                                          //Las filas representan los posibles estados (3) en la maquina = (0,1,2)
                                          //Las columnas representan las posibles entradas en la maquina (0,1) = 2 entradas distintas
                                          //Ocasionando un comportamiento inusual el valor -1, ya que no hay una fila correspondiente
                                          //a -1 en la matriz.
                                          //Modificacion: {{1,0}, {-1,2}, {-1,3}} = {{1,0}, {1,2}, {0,3}}
int simbolo;                              //Simbolo entero
int estado = 0;                           //Estado inicial = 0
while(estado != 3){                        //Mientras no se llegue al estado 3
cout << "Dame la nueva entrada (0,1): ";   //Pide una entrada (0,1)
cin >> simbolo;                            //Lee la entrada dada y se guarda
estado = MT[estado][simbolo];              //Se actualiza el estado
cout <<"Estado actual: "<< estado << "\n"; //Imprime el estado
cin.ignore();
cin.get();
//cout<<"MT["<<estado<<"]["<<simbolo<<"]"<<"\n";
system("cls");
}
return 0;
}
