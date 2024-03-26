#include <Func_1.h>

int main()
{
    int num_matrices = User_Bob();          //Inicializa los arreglos a gusto del usuario

    for(int i = 0; i < num_matrices; i++) Value(i);     //Añade valores a las matrices que paso como argumentos
    //for(int j = 0; j < num_matrices; j++) Graph(j);   //Imprime matrices segun le indique

    Eraser(num_matrices);       //Libera memoria dinamica

    return 0;
}
