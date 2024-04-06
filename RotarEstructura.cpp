

short int ** rotar_matriz(short int ** matriz, short int tam , bool eliminar)
{
    short int cont_filas = tam-1 , cont_columnas = 0 , filas = tam-1;
    short int ** matriz_nueva = new short int *[tam];

    for(int i = 0; i < tam; i++)
        matriz_nueva[i] = new short int [tam];


    for(int i = 0; i <= tam-1 ; i++)
    {
        for(int u = 0; u <= tam-1 ;u++)
        {
            matriz_nueva[cont_filas][cont_columnas] = matriz[i][u];
            cont_filas--;
        }
        cont_columnas++;
        cont_filas = tam-1;
    }

    if(eliminar)
    {
        //se borra la matriz original
        for (int i = 0; i < filas; ++i) {
            delete[] matriz[i]; // Borra cada fila de la matriz
        }
        delete[] matriz; // Borra el arreglo de punteros que apuntan a las filas
    }

    return matriz_nueva;
}
