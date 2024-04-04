#include <iostream>
#include "CompararMatrices.cpp"
#include "CrearEstructura.cpp"
#include "RotarEstructura.cpp"

using namespace std;

int main()
{
    // ingresar key
    short int tam_key = 5;
    short int key[tam_key] = {1,1,1,1,1}, tam_A, tam_B, tam_min,  fila = key[0], columna = key[1];
    // validar key


    short int X[4],R[4]; // se debe hacer con new en la implementacion final

    tam_min = max(key[0],key[1]); // sacamos valor mas grande de las coordenadas, para dar un tamaño minimo a las matrices

    if(tam_min < 2) // tamaño minimo de la matriz debe ser 3
        tam_min = 3;

    else if(tam_min % 2 == 0) // si el valor es par, se vuelve impar
        tam_min++;
    else
        tam_min += 2; // si el valor es impar, se pasa al siguiente impar para salir de rango, ya que las coordenadas inician en (0,0)

    tam_A = tam_min;
    tam_B = tam_min; //iniciamos ambas matrices del mismo tamaño

    if((tam_A/2 == fila) && (tam_A/2 == columna))
        tam_A+=2; // si las coordenadas de key son el centro de la matriz delantera se agranda su tamaño

    short int ** A = crear(tam_A), ** B = crear(tam_B), pos_norma = 2,num_rotaciones = 0 , pos_matriz_actual = 0, dif_tam = 0; // se crean las primeras versiones de las matrices

    while(! comparar(A,B,tam_A,tam_B, fila , columna , key[pos_norma])) //mientras que no se cumpla la primera norma entre A y B
    {
        if (num_rotaciones < 3) // se verifican rotaciones
        {
            A = rotar_matriz(A, tam_A);
            num_rotaciones ++;
        }

        else
        {
            if(key[pos_norma] == 1) //se elige matriz mas conveniente
            {
                borrar_matriz(A, tam_A);
                tam_A += 2;
                A = crear(tam_A);
            }
            else
            {
                borrar_matriz(B, tam_B);
                tam_B += 2;
                B = crear(tam_B);
            }
            num_rotaciones = 0;
        }
    }

    cout<<"a: "<<endl;
    mostrarMatriz(A,tam_A);
    cout<<endl<<"b:"<<endl;
    mostrarMatriz(B,tam_B);
    cout<<endl<<"------------";

    fflush(stdin);

    // guardo los tamaños de A y B en cerradura (X) y las rotaciones en (R)

    X[pos_matriz_actual] = tam_A;
    //R[pos_matriz_actual] = num_rotaciones;

    pos_matriz_actual ++;

    X[pos_matriz_actual] = tam_B;

    num_rotaciones = 0; //reiniciamos rotaciones



    pos_norma++; //avanzamos a la siguiente norma

    while(pos_norma <= tam_key - 1)
    {
        //R[pos_matriz_actual] = num_rotaciones;

        borrar_matriz(A,tam_A);

        tam_A = tam_B;

        A = B;

        tam_B = max(key[0],key[1]); // sacamos valor mas grande de las coordenadas, para dar un tamaño minimo a la matriz

        if(tam_B < 2) // tamaño minimo de la matriz debe ser 3
            tam_B = 3;

        else if(tam_B % 2 == 0) // si el valor es par, se vuelve impar
            tam_B++;

        else
            tam_B += 2;

        B = crear(tam_B); // se crea nueva B

        if(X[0] != tam_A) // calculamos la diferencia en tamaños, tomando como referencia la primera matriz
            dif_tam = X[0] - tam_A;

        dif_tam /= 2; //contamos solo los saltos de tamaño de numeros impares

        fila = key[0] - dif_tam;
        columna = key[0] - dif_tam;

        while(! comparar(A,B,tam_A,tam_B, fila , columna, key[pos_norma]))
        {
            if (num_rotaciones < 3)
            {
                B = rotar_matriz(B, tam_B);
                num_rotaciones ++;
            }

            else if(tam_A == tam_min && key[pos_norma] == 1)
            {
                // aumentar una unidad para cada rotacion en r hasta pos_matriz_actual
                cout<<"aumento de rotaciones";
                rotar_matriz(A,tam_A);
                num_rotaciones = 0;
            }

            else
            {
                // B se inicializa en la menor dimension posible, es por ello que solo es posible aumentar su tamaño
                borrar_matriz(B,tam_B);
                tam_B += 2;
                B = crear(tam_B);
                num_rotaciones = 0;
            }

        }

        cout<<"a: "<<endl;
        mostrarMatriz(A,tam_A);
        cout<<endl<<"b:"<<endl;
        mostrarMatriz(B,tam_B);
        cout<<endl<<"------------";

        fflush(stdin);

        pos_norma++; //avanzamos a la siguiente norma

        X[pos_matriz_actual] = tam_A;
        pos_matriz_actual++;
    }

    return 0;
}
