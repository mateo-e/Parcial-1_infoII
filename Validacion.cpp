#include <iostream>


using namespace std;

short int * crear_key(short int & longitud)
{
    short int posicion_x , posicion_y;

    do
    {
        cout << "INGRESA SOLO VALORES POSITIVOS: "<<endl;
        cout << "Ingrese el valor de la fila: ";
        cin >> posicion_x;
        cout <<"Ingrese el valor de la columna: ";
        cin >> posicion_y;

        cout<<endl;

    }while(posicion_x < 1 || posicion_y < 1);


    short int* cadena = nullptr, norma, cont = 2;


    cout << "Cuantas normas va a ingresar: ";
    cin  >> longitud;

    while(longitud <= 0)
    {
        cout<<endl<<"Ingresaste un numero invalido, intentelo de nuevo"<<endl;
        cout << "Cuantas normas va a ingresar: ";
        cin  >> longitud;

    }

    cadena = new short int[longitud];

    cadena[0] = posicion_x;
    cadena[1] = posicion_y;

    do{
        cout << "Ingrese la norma numero "<< cont - 1<< " para la comparacion de matriz (recuerde solo 1, -1, 0): ";
        cin >> norma;

        while(! (norma == 1 || norma == -1 || norma == 0))
        {
            cout<<endl<<endl<<"Para que sea una norma Ingrese solo 1,-1 o 0"<<endl<<"Intentelo de nuevo: ";
            cin>> norma;
        }

        cadena[cont] = norma;
        cont++;

    }while(cont - 2 < longitud);

    return cadena;

}









