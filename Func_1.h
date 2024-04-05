#ifndef FUNC_1_H
#define FUNC_1_H

#endif // FUNC_1_H

#include <iostream>     //Entrada y salida estandar (cout y cin)
#include <stdlib.h>      //Manejo de memoria dinamica (new y delete)

using namespace std;

int ***mat;                 //Estructura de datos M
int *pref, *k;              //pref guarda el orden de cada matriz en M //k es la encargada de guarda la entrada K


//Funcion para imprimir la matriz ( Meramente grafica )
void Graph(int matriz){
    for(int i = 0; i < pref[matriz]; i++){              //Itera en funcion a el orden de la matriz dada en el argumento
        for(int j = 0; j < pref[matriz]; j++){
            if(mat[matriz][i][j] != 0){                 //Si se encuentra en el punto medio no imprime
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

//Funcion para liberar memoria dinamica
void Eraser(int num_matrices){
    for(int i = 0; i < num_matrices; i++){
        for(int j = 0; j < pref[i]; j++){       //Itera segun el orden de la matriz referenciada por i
            delete[] mat[i][j];             //Libera cada columna por fila (nivel 3)
        }
        delete[] mat[i];            //Libera cada fila (nivel 2)
    }
    delete[] mat;           //Libera cada espacio para matrices
    mat = nullptr;

    delete[] k;         //Libera el espacio reservado para k
    k = nullptr;

    delete[] pref;      //Libera el espacio reservado para pref
    pref = nullptr;
}
//Fin

//Funcion que añade valores a cada una de las matrices
void Value(int matriz){
    int cont = 1, lineal = pref[matriz] / 2;        //Tomo la mitad del orden en matriz, al ser impar siempre me va a dar
                                                    //el punto medio de esa matriz, ejm: en una 7x7, va de 0 a 6 y su mitad es [3][3]
    for(int i = 0; i < pref[matriz]; i++){
        for(int j = 0; j < pref[matriz]; j++){
            if((i == lineal) && (j == lineal)){         //Si se encuentra en la mitad de la matriz asigna valor 0 a esa posicion
                mat[matriz][i][j] = 0;
            } else {
                mat[matriz][i][j] = cont;
                cont++;
            }
        }                                           //Gracias al doble ciclo cada espacio por fila es ocupado por un numero consecutivo
    }
}
//Fin

//Funcion encargada de cambiar el tamaño de una matriz
void Dimension(int matriz){
    mat[matriz] = new int *[pref[matriz] += 2];           //Aqui se le asigna numero de filas a la matriz del tamaño de estructura #matriz
    for(int j = 0; j < pref[matriz]; j++){
        mat[matriz][j] = new int [pref[matriz]];      //Se le asigna numero de columnas a cada fila del nuevo tamaño de estructura i
    }
    Value(matriz);                              //Se le agregan los valores a la nueva matriz
}
//Fin

//Funcion para rotar la matriz
void Rotation(int matriz){
    int backup = 0, help = 0, orden = pref[matriz], min = 0, max = 0;
    for(int capa = 0; capa < orden / 2; capa++){

        min = capa;                     //Se toma los bordes como "capas"
        max = (orden - 1) - capa;       //Al iterar se adentra en la siguiente capa, cambiando asi los limites

        for(int j = min; j < max; j++){

            help = j - min;             //help ayuda a referenciar los nuevos limites, ya que no puedo modificar j

            backup = mat[matriz][min][j];       //Siempre habra un valor que se debe guardar, debido a que esa posicion sera ocupada por otro

            mat[matriz][min][j] = mat[matriz][max - help][min];             //En cuanto a la rotacion siempre hay un patron con las posiciones, no los valores

            mat[matriz][max - help][min] = mat[matriz][max][max - help];    //Siempre que un valor pasa a otra posicion, la posicion anterior debe ser ocupada por otro

            mat[matriz][max][max - help] = mat[matriz][j][max];

            mat[matriz][j][max] = backup;       //En este caso el ultimo valor pasa a ser el primero que guardamos
        }
    }
    //cout << "Rotacion : " << "Matriz #" << matriz + 1 << endl;     //Pruebas
}
//Fin

//Funcion encargada de validaciones de rango
int Comp (int var, int range){
    while ((var > range) || (var < 1)){
        cout << "Error, no corresponde con los limites\n" << "Digite nuevamente: ";     //Me sirve cuando solo se puede escoger entre 1 y n
        cin >> var;
    }
    return var;     //Retorna el valor que cumple con las condiciones
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

//Funcion para validar la apertura de X
void Locked(int num_matrices){

    bool comp = false;
    int PIN, backup = 0, backup_2 = 0, fila = k[0] - 1, column = k[1] - 1, sec = 0, cont = 0, Escen = 0, DIF = 0, DIF_sup = 0;

    if (k[3] == -1) sec = -1;           //sec indica si la secuencia es mayor / menor(-1 / 1 /true) o menor / mayor(1 / -1 / false)
    else sec = 1;


    PIN = pref[k[2] - 1];               //Se guarda el orden de la primera matriz, asi no se pierde la proporcion entre matrices aunque la de referencia cambie su tamaño
    for (int i = k[2] - 1; i < num_matrices - 1; i++){              //Inicia desde la estructura deseada
        comp = false;
        while (comp == false){

            while((fila > pref[i + 1]) || (column > pref[i + 1])){
                cout << endl << "Las dimensiones podrian no corresponder con la matriz " << i + 2 <<",\npor lo que su orden aumentara" << endl;
                Dimension(i + 1);
            }                           //Se aplica por si las coordenadas digitadas superan el orden de algunas matrices

            DIF = (pref[i] - PIN) / 2;                                  //DIF y DIF_sup indican la diferencia entre ordenes de la matriz i / i + 1 y
            DIF_sup = (pref[i + 1] - PIN) / 2;                     //la estructura elegida (PIN), para que al indicar posiciones sean proporcionales al centro de cada una

            if ((((cont != 0) || (pref[i] != PIN)) && (pref[i] != PIN))){   //Puede haber un escenario en que la matriz i haya cambiado de tamaño, por lo que se debe tomar como una de distinto tamaño

                if((fila + DIF >= 0) && (column + DIF >= 0)) backup = mat[i][fila + DIF][column + DIF];
                else if((fila + DIF < 0) && (column + DIF >= 0)) backup = mat[i][fila + DIF][column];                        //En caso de que alguna de las coordenadas menos la diferencia sean menores a 0,
                else if ((column + DIF < 0) && (fila + DIF >= 0)) backup = mat[i][fila][column + DIF];                    //no se aplicara la diferencia
                else backup = mat[i][fila][column];

            }else backup = mat[i][fila][column];         //En el caso de que sea del mismo orden a PIN, no hay necesidad de aplicar proporciones

            if(PIN != pref[i + 1]){     //Si son de diferente orden se aplica la diferencia

                if((fila + DIF_sup >= 0) && (column + DIF_sup >= 0)) backup_2 = mat[i + 1][fila + DIF_sup][column + DIF_sup];
                else if((fila + DIF_sup < 0) && (column + DIF_sup >= 0)) backup_2 = mat[i + 1][fila + DIF_sup][column];                        //En caso de que alguna de las coordenadas menos la diferencia sean menores a 0,
                else if ((column + DIF_sup < 0) && (fila + DIF_sup >= 0)) backup_2 = mat[i + 1][fila][column + DIF_sup];                    //no se aplicara la diferencia
                else backup_2 = mat[i + 1][fila][column];

            }else backup_2 = mat[i + 1][fila][column];

            if(Escen < 4){                  //Indica si la matriz dio todas las rotaciones necesarias
                if (sec == 1){                 //Si la secuencia indica mayor / menor aplica el siguiente condicional

                    if(backup > backup_2){
                        comp = true;
                    }else Rotation(i + 1);

                } else {                        //Si la secuencia indica menor / mayor aplica el siguiente condicional
                    if(backup < backup_2){
                        comp = true;
                    }else Rotation(i + 1);
                }
            }else{                      //Si ya dio todas las vueltas necesarias, ahora la que gira es la matriz i
                if (sec == 1){

                    if(backup > backup_2){
                        comp = true;
                    }else Rotation(i);

                } else {
                    if(backup < backup_2){
                        comp = true;
                    }else Rotation(i);
                }
            }

            if ((Escen > 7) && (sec == 1)){   //Si la secuencia indica mayor / menor, el orden de la matriz i cambia para poder cumplir con esa condicion
                Dimension(i);
                Escen = 0;
            }else if ((Escen > 7) && (sec == -1)){   //Si la secuencia indica menor / mayor, el orden de la matriz i cambia para poder cumplir con esa condicion
                Dimension(i + 1);
                Escen = 0;          //Escen toma valor 0, para poder comprobar la matriz "nueva"
            }

            Escen++;            //Contabiliza el numero de rotaciones
        }
        if (cont % 2 == 0) sec = k[4];              //Si cont es 0 por ejm (primera iteracion), toma el valor en la siguiente posicion de K
        else sec = k[3];                            //Cuando sea impar toma la anterior
        cont++;                 //Sirve para indicar la primera vuelta
        Escen = 0;          //Toma valor 0 para contabilizar las vueltas de la nueva comparacion
    }
}
//Fin
