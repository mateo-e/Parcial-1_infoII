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


void borrar_matriz(short int** matriz, short int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i]; // Borra cada fila de la matriz
    }
    delete[] matriz; // Borra el arreglo de punteros que apuntan a las filas
}
