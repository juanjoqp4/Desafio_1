#ifndef FUNC_CONSTRUCTORAS_H
#define FUNC_CONSTRUCTORAS_H

#endif // FUNC_CONSTRUCTORAS_H

#include <Func_Operadoras.h>

//Funcion para inicializar l@s matrices / arreglos
int User_Bob(){
    unsigned short int est, orden;              //No se necesitan numeros negativos ni valores muy grandes
    cout << "Digite numero de estructuras para X: ";
    cin >> est;
    pref = new int [est];                       //pref se encarga de guardar el orden de cada matriz
    k = new int [5];

    cout << "Digite el orden de cada una" << endl;
    for(int i = 0; i < est; i++){                               //Este ciclo se encarga de darle a cada matriz un orden
        cout << "Orden para estructura #" << i + 1 << " : ";
        cin >> orden;
        while ((orden < 3) || (orden % 2 == 0)){                                                            //Validacion
            cout << "Orden invalido, vuelva a intentarlo" << endl << "Estructura #" << i + 1 << " : ";
            cin >> orden;
        }
        pref[i] = orden;            //En la posicion i se guarda n orden, se podria decir que pref esta alineada a mat (primer nivel)
    }

    mat = new int **[est];              //CERRADURA X
    for (int i = 0; i < est; i++){      //i referencia cada estructura  (1)
        mat[i] = new int *[pref[i]];           //Aqui se le asigna numero de filas a la matriz del tamaño de estructura i (2)
        for(int j = 0; j < pref[i]; j++){
            mat[i][j] = new int [pref[i]];      //Se le asigna numero de columnas a cada fila del tamaño de estructura i (3)
        }
    }

    return est;         //Retorna el numero de matrices que hay en el arreglo
}
//Fin

//Funcion encargada de construir la regla K
void Rule_K(int num_matrices){

    int fila = 0, columna = 0, est = 0, m1 = 0, m2 = 0, orden = 0;          //No me gusta tenerlos divagando con valores sin sentido

    cout << "Regla K" << endl << "Digite # de estructura: ";
    cin >> est;                                                 //Al comprobar primero la estructura deseada, puedo determinar facilmente su orden
    est = Comp(est, num_matrices);                              // y realizar las respectivas validaciones
    k[2] = est;                         //Se añade al arreglo

    orden = pref[est - 1];

    cout << "Digite Fila: ";
    cin >> fila;
    fila = Comp(fila, orden);               //Se comprueba que corresponda al orden de esa matriz
    k[0] = fila;

    cout << "Digite Columna: ";
    cin >> columna;
    columna = Comp(columna, orden);         //Se comprueba que corresponda al orden de esa matriz
    k[1] = columna;

    while(mat[est - 1][fila - 1][columna - 1] == 0){
        cout << "Esta coordenada corresponde al centro de la matriz, digite otra diferente" << endl;
        cout << "Digite Fila: ";
        cin >> fila;
        fila = Comp(fila, orden);               //Se comprueba que corresponda al orden de esa matriz
        k[0] = fila;

        cout << "Digite Columna: ";
        cin >> columna;
        columna = Comp(columna, orden);         //Se comprueba que corresponda al orden de esa matriz
        k[1] = columna;
    }

    cout << "Digite -1 o 1 para la secuencia: ";
    cin >> m1;
    while ((m1 != 1) && (m1 != -1)){
        cout << "Error\nDigite -1 para menor o 1 para mayor: ";
        cin >> m1;
    }
    k[3] = m1;

    cout << "Digite -1 o 1 para la secuencia: ";
    cin >> m2;
    while ((m2 != 1) && (m2 != -1)){
        cout << "Error\nDigite -1 para menor o 1 para mayor: ";
        cin >> m2;
    }
    k[4] = m2;
}
//Fin
