#include <iostream>
#include "mostrarMatriz.cpp"

using namespace std;

void validar(short int *** cerradura, short int tam_cerradura, short int * key, short int * tam_matrices)
{
    short int tam_A = 0, tam_B = 0,dif_tamaño = 0, f_A, c_A, f_B, c_B, **A, **B;

    tam_A = tam_matrices[0];
    tam_B = tam_matrices[1];

    A = cerradura[0];
    B = cerradura[1];

    // inicializamos las primeras coordenadas
    f_A = key[0];
    c_A = key[1];

    for(short int pos_matriz = 2; pos_matriz < tam_cerradura ; pos_matriz++)
    {
        mostrarMatriz(A,tam_A);
        cout<<endl;

        mostrarMatriz(B,tam_B);
        cout<<endl;

        if(tam_A != tam_B)
            dif_tamaño = tam_A - tam_B;

        dif_tamaño /= 2;

        // se alinean las coordenadas
        f_B = f_A - dif_tamaño;
        c_B = c_A - dif_tamaño;

        if ((A[f_A][c_A] > B[f_B][c_B]) && key[pos_matriz] == 1)
        {
            cout<<endl<<key[pos_matriz]<<endl<<"A: "<<A[f_A][c_A]<<endl<<"B: "<<B[f_B][c_B]<<endl<<endl;
        }

        else if ((A[f_A][c_A] < B[f_B][c_B]) && key[pos_matriz] == -1)
        {
            cout<<endl<<key[pos_matriz]<<endl<<"A: "<<A[f_A][c_A]<<endl<<"B: "<<B[f_B][c_B]<<endl<<endl;
        }

        else if ((A[f_A][c_A] == B[f_B][c_B]) && key[pos_matriz] == 0)
        {
            cout<<endl<<key[pos_matriz]<<endl<<"A: "<<A[f_A][c_A]<<endl<<"B: "<<B[f_B][c_B]<<endl<<endl;
        }

        else // en caso que alguna de las condiciones no se cumpla
        {
            cout<<endl<<"se ha presentado una incongruencia en la matriz numero "<<pos_matriz<<endl<<"La norma \""<<key[pos_matriz]<<"\" no se cumplio"<<endl;
            return;
        }

        //se actualizan los valores

        f_A = f_B;
        c_A = c_B;

        A = B;

        B = cerradura[pos_matriz];

        tam_A = tam_B;

        tam_B = tam_matrices[pos_matriz];
    }

    cout<<endl<<"la key otorgada es valida para la cerradura creada"<<endl;
}


