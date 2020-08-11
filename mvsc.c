#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
recber os numeros
por em ordem crescente
verificar se há uma pg
informar se há a pg
informar a razão da pg


n2 = n1 * q
*/

void ler_nums(int num[], int i ){
    if(i >= 5){
        return;
    }else{
        scanf("%d", &num[i]);
        ler_nums(num, i+1);
    }
}
int achar_maior(int array[], int i, int maiorI, int tam)
{
    if (i < tam)
    {
        if (array[i] > array[maiorI])
        {
            maiorI = i;
        }
        achar_maior(array, i + 1, maiorI, tam);
    }
    else
    {
        return maiorI;
    }
}
void ordenar(int array[], int tam){
    if (0 < tam)
    {
        int maiorI = achar_maior(array, 0, 0, tam);
        int aux = array[maiorI];
        array[maiorI] = array[tam - 1];
        array[tam - 1] = aux;
        ordenar(array, tam - 1);
    }
}

void imprimir(int array[], int i)
{
    if (i < 5)
    {
        printf("%d", array[i]);
        if(i < 4){
            printf(" ");
        }
        imprimir(array, i + 1);
    }
}

void tem_pg(int array[], int tam){
    int r1 = array[tam-1]/array[tam-2];
    while(tam >= 2){
        if((array[tam-1]/array[tam-2]) == r1){
            tam--;
        }else{
            return;
        }
        printf("tem pg com razão %d ", r1);
    }
}

int main(){
    int num[5];
    
//receber os numeros;
    ler_nums(num, 0);

//por em ordem crescente
    ordenar(num, 5);

//imprimir sequencia ordenada
    imprimir(num, 0);

//verificar se há uma pg
    tem_pg(num, 5);
}
