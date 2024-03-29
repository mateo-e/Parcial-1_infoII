using namespace std;

short int ** crear(short int tam)
{
    short int ** nueva = new short int *[tam], cont = 1;

    for(int i = 0; i < tam ; i++)
    {
        nueva[i] = new short int [tam];

        for(int u = 0; u < tam; u++)
        {
            if(i == (tam / 2) && u == (tam / 2)) //si se llega al centro se rellena con un 0
            {
                nueva[i][u] = 0;
                continue;
            }
            nueva[i][u] = cont;
            cont ++;
        }
    }
    return nueva;
}

void mostrarMatriz(short int ** matriz,short int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        for(int u = 0; u < tam; u++)
        {
            if(matriz[i][u] == 0) //si se llega al medio
            {
                cout << "   ";
                continue;
            }

            cout << matriz[i][u];

            if(matriz[i][u]/10 > 0) // se crean espacios de diferentes tamaños dependiento de las cifras del numero
                cout << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
