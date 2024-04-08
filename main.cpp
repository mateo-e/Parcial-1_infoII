#include <iostream>
#include "crearCerradura.cpp"

using namespace std;

int main()
{

    // ingresar key
    short int key[] = {4,3,1,1,1,1,-1,1,1,-1,-1,0,1,1,-1,0};

    // validar key

    short int tam_key = sizeof key / 2;


    //creacion de cerradura
    short int ***cerradura = new short int **[tam_key-1], *tam_matrices = new short int [tam_key - 1];

    tam_matrices = crear_cerradura(cerradura,key,tam_key);



    if (tam_matrices != NULL) //si no se produjo algun error
        validar(cerradura, tam_key, key,tam_matrices);

    else
        cout<<endl<<"Se produjo un error al crear la cerradura, por lo tanto no es posible validar"<<endl;

    delete[] tam_matrices;

    return 0;
}
