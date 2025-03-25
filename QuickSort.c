#include <stdio.h>
#include <time.h>

void troca(int vetor[], int i, int j)
{
    int temp = vetor[i]; // armazena a posição inicial do vetor
    vetor[i] = vetor[j]; // substitui a posição inicial pela posição final
    vetor[j] = temp;     // substitui a posição final pela inicial
}

int part(int vetor[], int inicio, int fim)
{
    int pivot = vetor[fim]; // pivot = fim do vetor
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (vetor[j] < pivot) // se o elemento for menor que o pivot...
        {
            i++;
            troca(vetor, i, j); // troca os elementos
        }
    }
    troca(vetor, i + 1, fim); // coloca o pivot na posição correta
    return i + 1; // retorna o indice do pivot
}

void QuickSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = part(vetor, inicio, fim); // encontra o pivo
        QuickSort(vetor, inicio, pivo - 1); // ordena o inicio do pivo
        QuickSort(vetor, pivo + 1, fim); // ordena o final do pivo
    }
}

    void print(int vetor[], int tam)
    {
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]); // printa os resultados do vetor
    }
    printf("\n");
}

int main()
{
    int vetorInicial[] = {1, 5, 10, 4, 8, 3, 9};
    int tamVetor = sizeof(vetorInicial) / sizeof(vetorInicial[0]);

    printf("Array antes da ordenacao: ");
    print(vetorInicial, tamVetor);
    QuickSort(vetorInicial, 0, tamVetor - 1);
    printf("Array apos a ordenacao: ");
    print(vetorInicial, tamVetor);

    return 0;
}