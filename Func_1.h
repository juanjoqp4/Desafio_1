#ifndef FUNC_1_H
#define FUNC_1_H

#endif // FUNC_1_H

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>
#include<stdio.h>
using namespace std;

int **mat;

//Funcion para rotar la matriz
void Rotation(int orden){
    int backup = 0, backup_2 = 0, help = 0, cont = 0;
    for(int i = 0; i < orden; i++){
        for(int j = (orden - 1) - cont; j > cont; j--){
            backup = mat[i][j];                                             //backup : Toma el valor de la posicion de la matriz que sera reemplazada
            mat[i][j] = mat[i + help][i];                                 //help : Sirve como soporte para i y j. Cuando itera i / j siguen referencian una fila / columna por la que ya pasaron,
            backup_2 = mat[j][j + help];                                        //por lo que necesitan avanzar sin aumentar su valor en el ciclo , entonces help cubre esa necesidad
            mat[j][j + help] = backup;

            backup = mat[j + help][i + help];
            mat[j + help][i + help] = backup_2;

            mat[i + help][i] = backup;
            help++;
        }
        cont++;                     //cont : Cuando j finaliza con todos los elementos columna de una fila, no vuelve a ella, pero cuando acaba su ciclo vuelve siempre
        help = i;                   //a la primera. cont evita eso y en vez de volver a n, vuelve a la columna que sigue
    }
}
//Fin

//Funcion para imprimir la matriz ( Meramente grafica )
void Graph(int orden){
    for(int i = 0; i < orden; i++){
        for(int j = 0; j < orden; j++){
            if(mat[i][j] < 10){
                cout << mat[i][j] << "  ";              //Para compensar espacios, en caso de que sea de 1 digito añade un espacio mas
            }else cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//Fin

//Funcion encargada de la construccion de la matriz
void Bob_Pr_14(int orden){
    mat = new int *[orden];
    int cont = 0;
    for (int i = 0; i < orden; i++){
        mat[i] = new int [orden];         //A cada fila a se le asigna b elementos
    }

    for(int i = 0; i < orden; i++){
        for(int j = 0; j < orden; j++){
            cont++;
            mat[i][j] = cont;
        }
    }
}
//Fin

//Funcion encargada de liberar el puntero principal
void Deleter(int orden){
    for(int i = 0; i < orden; i++){
        delete[ ] mat[i];           //Cada espacio de cada fila a es liberado
    }
    delete[ ] mat;      //Toda fila a es liberada
    mat = nullptr;
}
//Fin
