#ifndef FUNC_1_H
#define FUNC_1_H

#endif // FUNC_1_H

#include <iostream>     //Entrada y salida estandar (cout y cin)
#include<stdlib.h>      //Manejo de memoria dinamica (new y delete)

using namespace std;

int ***mat;
int *pref, *k;


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

//Funcion para inicializar l@s matrices / arreglos
int User_Bob(){
    unsigned short int est, orden;              //No se necesitan numeros negativos ni valores muy grandes
    cout << "Digite numero de estructuras: ";
    cin >> est;
    pref = new int [est];                       //pref se encarga de guardar el orden de cada matriz
    k = new int [5];

    cout << "Digite el orden de cada una" << endl;
    for(int i = 0; i < est; i++){
        cout << "Orden para estructura #" << i + 1 << " : ";
        cin >> orden;
        while ((orden < 3) || (orden % 2 == 0)){                                                            //Validacion
            cout << "Orden invalido, vuelva a intentarlo" << endl << "Estructura #" << i + 1 << " : ";
            cin >> orden;
        }
        pref[i] = orden;
    }

    mat = new int **[est];              //CERRADURA X
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

    delete[] k;
    k = nullptr;

    delete[] pref;
    pref = nullptr;
}
//Fin

//Funcion que añade valores a cada una de las matrices
void Value(int matriz){
    int cont = 1, lineal = pref[matriz] / 2;

    for(int i = 0; i < pref[matriz]; i++){
        for(int j = 0; j < pref[matriz]; j++){
            if((i == lineal) && (j == lineal)){         //Si se encuentra en la mitad de la matriz asigna valor 0 a esa posicion
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

//Funcion encargada de validaciones de rango
int Comp (int var, int range){
    while ((var > range) || (var < 1)){
        cout << "Error, no corresponde con los limites\n" << "Digite nuevamente: ";
        cin >> var;
    }
    return var;
}
//Fin

//Funcion encargada de construir la regla K
void Rule_K(int num_matrices){

    int fila, columna, est, m1, m2, orden;

    cout << "Regla K" << endl << "Digite # de estructura: ";
    cin >> est;
    est = Comp(est, num_matrices);
    k[2] = est;

    orden = pref[est - 1];

    cout << "Digite Fila: ";
    cin >> fila;
    fila = Comp(fila, orden);
    k[0] = fila;

    cout << "Digite Columna: ";
    cin >> columna;
    columna = Comp(columna, orden);
    k[1] = columna;

    cout << "Digite -1 para mayor o 1 para menor: ";
    cin >> m1;
    while ((m1 != 1) && (m1 != -1)){
        cout << "Error\nDigite -1 para mayor o 1 para menor: ";
        cin >> m1;
    }
    k[3] = m1;

    cout << "Digite -1 para mayor o 1 para menor: ";
    cin >> m2;
    while ((m2 != 1) && (m2 != -1)){
        cout << "Error\nDigite -1 para mayor o 1 para menor: ";
        cin >> m2;
    }
    k[4] = m2;
}
//Fin
