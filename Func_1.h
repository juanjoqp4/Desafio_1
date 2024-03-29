#ifndef FUNC_1_H
#define FUNC_1_H

#endif // FUNC_1_H

#include <iostream>     //Entrada y salida estandar (cout y cin)
#include <stdlib.h>      //Manejo de memoria dinamica (new y delete)
#include <string.h>

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
    cout << "Digite numero de estructuras para X: ";
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
<<<<<<< HEAD
    int backup = 0, help = 0, orden = pref[matriz], min = 0, max = 0;
    for(int capa = 0; capa < orden / 2; capa++){

        min = capa;                     //Se toma los bordes como "capas"
        max = (orden - 1) - capa;       //Al iterar se adentra en la siguiente capa, cambiando asi los limites

        for(int j = min; j < max; j++){

            help = j - min;             //help ayuda a referenciar los nuevos limites, ya que no puedo modificar j

            backup = mat[matriz][min][j];

            mat[matriz][min][j] = mat[matriz][max - help][min];

            mat[matriz][max - help][min] = mat[matriz][max][max - help];

            mat[matriz][max][max - help] = mat[matriz][j][max];

            mat[matriz][j][max] = backup;
        }
    }
    //cout << "Rotacion : " << "Matriz #" << matriz + 1 << endl;
}
//Fin


=======

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

>>>>>>> 421f30e386fe3af3a9d8ec5edd85e6853708ff4f
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

    cout << "Digite -1 para mayor / menor o 1 para menor / mayor: ";
    cin >> m1;
    while ((m1 != 1) && (m1 != -1)){
        cout << "Error\nDigite -1 para mayor o 1 para menor: ";
        cin >> m1;
    }
    k[3] = m1;

    if (m1 == 1) m2 = -1;
    else m2 = 1;
    k[4] = m2;
}
//Fin


//Funcion para validar la apertura de X
void Locked(int num_matrices){
<<<<<<< HEAD
    bool comp = false, invalid = false;
    int backup = 0, backup_2 = 0, fila = k[0] - 1, column = k[1] - 1, sec = 0, cont = 0, Escen = 1, DIF = 0, DIF_sup = 0;
=======
    bool comp = false;
    int backup = 0, backup_2 = 0, fila = k[0] - 1, column = k[1] - 1, sec = 0;
>>>>>>> 421f30e386fe3af3a9d8ec5edd85e6853708ff4f
    if (k[3] == -1) sec = -1;           //sec indica si la secuencia es mayor / menor(-1 / 1 /true) o menor / mayor(1 / -1 / false)
    else sec = 1;

    for (int i = 0; i < num_matrices - 1; i++){
        comp = false;
        while (comp == false){

<<<<<<< HEAD
            DIF = (pref[i] - pref[k[2] - 1]) / 2;
            DIF_sup = (pref[i + 1] - pref[k[2] - 1]) / 2;      //DIF indica la diferencia entre ordenes de la matriz i / i+1 y la estructura elegida, para que al referenciar posiciones sea proporcional al centro de cada una

            if (DIF < 0) DIF *= -1;

            if ((cont != 0) && (pref[i] != pref[k[2] - 1])) backup = mat[i][fila + DIF][column + DIF];
            else backup = mat[i][fila][column];

            if(pref[k[2] - 1] != pref[i + 1]) backup_2 = mat[i + 1][fila + DIF_sup][column + DIF_sup];
            else backup_2 = mat[i + 1][fila][column];

            if(Escen < 4){
                if (sec == -1){

                    if(backup > backup_2){
                        comp = true;
                    }else Rotation(i + 1);

                } else {
                    if(backup < backup_2){
                        comp = true;
                    }else Rotation(i + 1);
                }
            }else{
                invalid = true;
                if (sec == -1){

                    if(backup > backup_2){
                        comp = true;
                    }else Rotation(i);

                } else {
                    if(backup < backup_2){
                        comp = true;
                    }else Rotation(i);
                }
            }

            if ((Escen > 5) && (invalid == true)){
                comp = true;
                cout << endl <<"No hay forma de cumplir con las condiciones" << endl;
            }
            Escen++;
        }
        if (sec == -1) sec += 2;
        else sec -= 2;
        cont++;
        Escen = 1;
=======
            backup = mat[i][fila][column];
            backup_2 = mat[i + 1][fila][column];

            if (sec == -1){

                if(backup > backup_2){
                    comp = true;
                }else Rotation(i + 1);

            } else {
                if(backup < backup_2){
                    comp = true;
                }else Rotation(i + 1);
            }
        }
        if (sec == -1) sec += 2;
        else sec -= 2;
>>>>>>> 421f30e386fe3af3a9d8ec5edd85e6853708ff4f
    }
}
//Fin
