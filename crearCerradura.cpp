#include "CompararMatrices.cpp"
#include "CrearEstructura.cpp"
#include "RotarEstructura.cpp"
#include "validarRegla.cpp"

short int * crear_cerradura(short int ***cerradura, short int *key,short int tam_key)
{

    // declaracion matrices necesarias
    short int **A, **B;

    // declaracion variables auxiliares y contadores
    short int mayores_seguidos = 0, rot_A = 0, rot_B = 0,aux = 0, tam_A, tam_B, tam_min, pos_norma = 2, pos_matriz_actual = 0, dif_tam = 0,fila = key[0], columna = key[1];

    // declaracion de arreglos necesarios
    short int  *tam_matrices = new short int [tam_key];

    tam_A = max(key[0],key[1]); // sacamos valor mas grande de las coordenadas, para dar un tamaño minimo a las matrices

    if(tam_A < 2) // tamaño mini fjamo de la matriz debe ser 3
        tam_A = 3;

    else if(tam_A % 2 == 0) // si el valor es par, se vuelve impar
        tam_A++;
    else
        tam_A += 2; // si el valor es impar, se pasa al siguiente impar para salir de rango, ya que las coordenadas inician en (0,0)

    if((tam_A/2 == fila) && (tam_A/2 == columna))
        tam_A+=2; // si las coordenadas de key son el centro de la matriz delantera se agranda su tamaño

    // despues de contar cuantos 1 hay

    for(short int i = 2 ; i < tam_key ; i++ )
    {
        if (key[i] == 1)
            mayores_seguidos++;

        else if (mayores_seguidos > aux)
        {
            aux = mayores_seguidos;
            mayores_seguidos = 0;
        }
    }

    mayores_seguidos = aux;

    if(mayores_seguidos >= 3 && fila > tam_A / 2 && columna > tam_A / 2 && fila != 0 && columna != 0) //en caso que se tenga que crear una matriz mas grande para evitar problemas con los 1
        tam_A += (mayores_seguidos / 3) * 2 ;


    if(fila == tam_A - 1 || fila == tam_A - 1)
    {
        if(mayores_seguidos >= 3)
            tam_A += (mayores_seguidos / 3) * 2;
        else
            tam_A += 2;
    }

    if((tam_A/2 == fila) && (tam_A/2 == columna))
        tam_A+=2; // si las coordenadas de key son el centro de la matriz delantera se agranda su tamaño

    tam_B = tam_A;

    tam_min = tam_A;

    // se crean las primeras versiones de las matrices
    A = crear(tam_A);
    B = crear(tam_B);

    //se comprueban casos especiales
    if(key[pos_norma] == 1 && tam_A/2 > fila)
    {
        //roto la primera matriz de todas
        if(tam_A/2 > columna) // si esta arriba a la izquierda
        {
            A = rotar_matriz(A,tam_A,true);
            A = rotar_matriz(A,tam_A,true);
        }

        else
            A = rotar_matriz(A,tam_A,true);

        if(key[pos_norma + 1] == 1 && tam_A/2 > columna) // en caso que la siguiente norma es 1 y si esta arriba a la izquierda
        {
            B = rotar_matriz(B,tam_B,true);
            B = rotar_matriz(B,tam_B,true);
            B = rotar_matriz(B,tam_B,true);
        }

        else if (key[pos_norma + 1] == 1)
        {
            B = rotar_matriz(B,tam_B,true);
            B = rotar_matriz(B,tam_B,true);
        }

        if(! comparar(A,B,tam_A,tam_B, fila , columna , key[pos_norma]))
        {
            // en caso que por alguna razon no sirva lo que se hizo
            A = crear(tam_A);
            B = crear(tam_B);
        }
    }


    //mientras que no se cumpla la primera norma entre A y B se rotan o redimensionan

    while(! comparar(A,B,tam_A,tam_B, fila , columna , key[pos_norma]))
    {
        if(rot_A < 3 && rot_B < 3)
        {
            if(tam_A / 2 > fila)
            {
                if(key[pos_norma] == -1) // si esta arriba y necesito algo menor
                {
                    B = rotar_matriz(B, tam_B,true);
                    rot_B ++;
                }
                else  // si esta arriba y necesito algo mayor
                {
                    A = rotar_matriz(A, tam_A,true);
                    rot_A ++ ;
                }
            }
            else

            if(key[pos_norma] == 1) // si esta abajo y necesito algo menor
            {
                B = rotar_matriz(B, tam_B,true);
                rot_B ++;
            }
            else  // si esta abajo y necesito algo mayor
            {
                A = rotar_matriz(A, tam_A,true);
                rot_A ++ ;
            }
        }

        else
        {
            if(key[pos_norma] == 1) //se elige matriz mas conveniente
            {
                borrar_matriz(A, tam_A);
                tam_A += 2;
                A = crear(tam_A);

                if(tam_A > tam_B && (key[0] == 0 || key[0] == tam_A-1 || key [1] == 0 || key [1] == tam_A-1))
                {
                    borrar_matriz(B, tam_B);
                    tam_B = tam_A;
                    B = crear(tam_B);
                    tam_min = tam_B;
                }
            }
            else
            {
                borrar_matriz(B, tam_B);
                tam_B += 2;
                B = crear(tam_B);
            }
            rot_A = 0;
            rot_B = 0;
        }
    }

    // guardo A y B en cerradura

    cerradura[pos_matriz_actual] = A;
    tam_matrices[pos_matriz_actual] = tam_A;

    pos_matriz_actual ++;

    cerradura[pos_matriz_actual] = B;
    tam_matrices[pos_matriz_actual] = tam_B;

    rot_B = 0;

    //avanzamos a la siguiente norma

    while(pos_norma <= tam_key - 1)
    {

        if(key[pos_norma] == -1)
        {
            for(short int i = 0; i < 3; i++)
            {
                if (key[i] == -1)
                    break;
                if (i == 2)
                    tam_min += (mayores_seguidos / 3) * 2;
            }
        }

        tam_A = tam_B;

        A = B;

        tam_B = tam_min;

        B = crear(tam_B); // se crea nueva B

        if(tam_matrices[0] != tam_A) // calculamos la diferencia en tamaños, tomando como referencia la primera matriz
            dif_tam = tam_matrices[0] - tam_A;

        dif_tam /= 2; //contamos solo los saltos de tamaño de numeros impares

        fila = key[0] - dif_tam;
        columna = key[1] - dif_tam;


        while(! comparar(A,B,tam_A,tam_B, fila , columna, key[pos_norma]) || ( (key[pos_norma + 1] == 1 && tam_A/2 > fila && B[0][0] == 1) && rot_B == 0) )
        {

            if(B == NULL) // "A" se vuelve NULL cuando se produce un error dentro de la funcion comparar
                break;

            if (key[pos_norma + 1] == 1 && tam_A/2 > fila && B[0][0] == 1)
            {
                B = rotar_matriz(B,tam_B,true);
                rot_B ++;

                if (comparar(A,rotar_matriz(B,tam_B,false),tam_A,tam_B, fila , columna, key[pos_norma]))
                {
                    B = rotar_matriz(B,tam_B,true);
                    rot_B ++;
                    break;
                }

                continue;
            }

            if (rot_B < 4)
            {
                B = rotar_matriz(B, tam_B,true);
                rot_B ++;
            }

            else if(key [pos_norma] == -1)
            {
                // B se inicializa en la menor dimension posible, es por ello que solo es posible aumentar su tamaño
                borrar_matriz(B,tam_B);
                tam_B += 2;
                B = crear(tam_B);
                rot_B = 0;
            }
            else
            {

                borrar_matriz(B,tam_B);
                tam_B -= 2;

                if(tam_B == 1)
                {
                    cout<<"se ha llegado a un limite, es imposible continuar. <tam_b == 1>"<< endl;
                    B = NULL;
                    break;
                }

                B = crear(tam_B);
                rot_B = 0;

                tam_min = tam_B;
            }

        }

        if(B == NULL) // "B" se vuelve NULL cuando se produce un error dentro de la funcion comparar
        {
            delete[] tam_matrices;
            return NULL;

        }

        pos_norma++; //avanzamos a la siguiente norma

        //guardamos matriz B

        cerradura[pos_matriz_actual] = B;
        tam_matrices[pos_matriz_actual] = tam_B;

        pos_matriz_actual++;
    }

    return tam_matrices;
}
