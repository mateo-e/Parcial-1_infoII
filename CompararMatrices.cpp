#include <math.h>


using namespace std;

#define MAYOR 1
#define IGUAL 0
#define MENOR -1

bool comparar(short int ** A, short int ** B, short int A_tam, short int B_tam, short int f_A, short int c_A, short int norma)
{
    short int dif_tam = 0, f_B, c_B; //indica cuantos saltos en tamaño (numeros impares de diferencia hay entre la matriz)

    if(A_tam != B_tam)
        dif_tam = A_tam - B_tam; //calculamos la diferencia entre ambos tamaños (se divide entre dos para contar solo los saltos en numeros impares)

    dif_tam /= 2;

    // se alinean las coordenadas
    f_B = f_A - dif_tam;
    c_B = c_A - dif_tam;


    // en caso que la posicion en B no exista:

    if ( f_B < 0 || c_B < 0)
    {
        B = NULL;
        return false;
    }

    if ((A[f_A][c_A] > B[f_B][c_B]) && norma == MAYOR)
        return true;

    if ((A[f_A][c_A] < B[f_B][c_B]) && norma == MENOR)
        return true;

    if ((A[f_A][c_A] == B[f_B][c_B]) && norma == IGUAL)
        return true;

    return false;
}
