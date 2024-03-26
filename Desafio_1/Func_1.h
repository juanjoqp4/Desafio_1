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

int ***mat;
int *pref;

//Funcion para imprimir la matriz ( Meramente grafica )
void Graph(int matriz){
    for(int i = 0; i < pref[matriz]; i++){
        for(int j = 0; j < pref[matriz]; j++){
            if(mat[matriz][i][j] != 0){
                if(mat[matriz][i][j] < 10){
                    cout << mat[matriz][i][j] << "  ";              //Para compensar espacios, en caso de que sea de 1 digito añade un espacio mas
                }else cout << mat[matriz][i][j] << " ";
            } else cout << "   ";
        }
        cout << endl;
    }
    cout << endl;
}
//Fin

//Funcion para inicializar las matrices
int User_Bob(){
    int est, orden;
    cout << "Digite numero de estructuras: ";
    cin >> est;
    pref = new int [est];

    cout << "Digite el orden de cada una" << endl;
    for(int i = 0; i < est; i++){
        cout << "Estructura #" << i + 1 << " : ";
        cin >> orden;
        pref[i] = orden;
    }

    mat = new int **[est];
    for (int i = 0; i < est; i++){      //i referencia cada estructura
        mat[i] = new int *[pref[i]];           //Aqui se le asigna numero de filas a la matriz del tamaño de estructura i
        for(int j = 0; j < pref[i]; j++){
            mat[i][j] = new int [pref[i]];      //Se le asigna numero de columnas a cada fila del tamaño de estructura i
        }
    }

    return est;
}
//Fin

//Funcion para liberar memoria dinamica
void Eraser(int num_matrices){
    for(int i = 0; i < num_matrices; i++){
        for(int j = 0; j < pref[i]; j++){
            delete[] mat[i][j];             //Libera cada columna por fila
        }
        delete[] mat[i];            //Libera cada fila
    }
    delete[] mat;           //Libera cada espacio para matrices
    mat = nullptr;

    delete[] pref;
    pref = nullptr;
}
//Fin

//Funcion que añade valores a cada una de las matrices
void Value(int matriz){
    int cont = 1, lineal = pref[matriz] / 2;

    for(int i = 0; i < pref[matriz]; i++){
        for(int j = 0; j < pref[matriz]; j++){
            if((i == lineal) && (j == lineal)){
                mat[matriz][i][j] = 0;
            } else {
                mat[matriz][i][j] = cont;
                cont++;
            }
        }
    }
}
//Fin

//Funcion para rotar la matriz
void Rotation(int matriz){

    int orden = pref[matriz], backup = 0, backup_2 = 0, help = 0, cont = 0;

    for(int i = 0; i < orden; i++){
        for(int j = (orden - 1) - cont; j > cont; j--){
            backup = mat[matriz][i][j];                                             //backup : Toma el valor de la posicion de la matriz que sera reemplazada
            mat[matriz][i][j] = mat[matriz][i + help][i];                                 //help : Sirve como soporte para i y j. Cuando itera i / j siguen referencian una fila / columna por la que ya pasaron,
            backup_2 = mat[matriz][j][j + help];                                        //por lo que necesitan avanzar sin aumentar su valor en el ciclo , entonces help cubre esa necesidad
            mat[matriz][j][j + help] = backup;

            backup = mat[matriz][j + help][i + help];
            mat[matriz][j + help][i + help] = backup_2;

            mat[matriz][i + help][i] = backup;
            help++;
        }
        cont++;                     //cont : Cuando j finaliza con todos los elementos columna de una fila, no vuelve a ella, pero cuando acaba su ciclo vuelve siempre
        help = i;                   //a la primera. cont evita eso y en vez de volver a n, vuelve a la columna que sigue
    }
}
//Fin
