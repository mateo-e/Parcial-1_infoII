#include <iostream>
#include "CompararMatrices.cpp"
#include "CrearEstructura.cpp"

using namespace std;

int main()
{
    short int tam_A = 7, tam_B = 5;
    short int ** A = crear(tam_A), ** B = crear(tam_B);

    mostrarMatriz(A, tam_A);
    cout<<endl;
    mostrarMatriz(B, tam_B);

    cout<<endl;
    if(comparar(A,B, tam_A , tam_B ,1,1,-1))
        cout<<"si";
    else
        cout<<"no";


    return 0;
}
