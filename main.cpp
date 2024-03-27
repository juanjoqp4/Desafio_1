#include <Func_1.h>

int main()
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

    Eraser(num_matrices);       //Libera memoria reservada

    return 0;
}
