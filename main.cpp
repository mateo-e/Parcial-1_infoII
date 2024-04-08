#include <iostream>
#include "crearCerradura.cpp"
#include "Validacion.cpp"

using namespace std;

int main()
{

    short int tam_key, *key = crear_key(tam_key);

    tam_key += 2; // se agregan las posiciones de las coordenadas

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
