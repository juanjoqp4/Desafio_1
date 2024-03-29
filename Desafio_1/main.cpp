#include <Func_1.h>

int main()
{
    string rep;
    do
    {

    int num_matrices = User_Bob();          //Inicializa los arreglos a gusto del usuario

    for(int i = 0; i < num_matrices; i++) Value(i);     //Añade valores a las matrices que paso como argumentos

    Rule_K(num_matrices);       //Construye la regla K

    cout << endl << "Matrices construidas: " << endl;
    for(int j = 0; j < num_matrices; j++) Graph(j);   //Imprime matrices segun le indique
    cout << endl;

    cout << "Regla K : ";
    for(int h = 0; h < 5; h++){
        if (h != 4) cout << k[h] << " / ";      //Imprime la regla K
        else cout << k[h] << endl;
    }

    Locked(num_matrices);

    cout << "Configuracion de apertura : " << endl << endl;
    for(int j = 0; j < num_matrices; j++) Graph(j);

    Eraser(num_matrices);       //Libera memoria reservada

    cout << "Digite 0 para salir o cualquier otra tecla para repetir: ";
    cin.ignore();
    getline(cin , rep);
    }while(rep != "0");

    cout << endl <<" --> Programa Finalizado" << endl;
    return 0;
}


//PROBLEMA : Al pensar que la secuencia la podia determinar ell usuario, surgia un problema en cuanto a las rotaciones, ya que al buscar
        //un numero mas grande que el de mayor valor en la estructura entraba en un bucle infinito, por lo que la secuencia debia ser intercalada

/*          Al no comprender bien el enunciado, pense que podria haber un escenario en el que la matriz cambiaba su tamaño
//Funcion encargada de cambiar el tamaño de una matriz
void Dimension(int matriz){
    mat[matriz] = new int *[pref[matriz] += 2];           //Aqui se le asigna numero de filas a la matriz del tamaño de estructura #matriz
    for(int j = 0; j < pref[matriz]; j++){
        mat[matriz][j] = new int [pref[matriz]];      //Se le asigna numero de columnas a cada fila del tamaño de estructura i
    }
    Value(matriz);
}
//Fin
*/

//PROBLEMA : Al pensar que la secuencia la podia determinar el usuario, surgia un problema en cuanto a las rotaciones, ya que al buscar
        //un numero mas grande que el de mayor valor en la estructura entraba en un bucle infinito, por lo que la secuencia debia ser intercalada

//PROBLEMA : Revisar la operacion en [3][2]

