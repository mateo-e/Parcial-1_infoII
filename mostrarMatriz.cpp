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
