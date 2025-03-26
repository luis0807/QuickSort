#include <stdio.h>
#include <time.h>

int count = 0;

void troca(int vetor[], int i, int j)
{
    int temp = vetor[i]; // armazena a posição inicial do vetor
    vetor[i] = vetor[j]; // substitui a posição inicial pela posição final
    vetor[j] = temp;     // substitui a posição final pela inicial
    count++;
}

int part(int vetor[], int inicio, int fim)
{
    int pivot = vetor[inicio]; // pivot = inicio do vetor
    int i = inicio + 1;
    int j = fim;
    
    for (j = fim; i <= j; i++)
    {
        if (vetor[i] > pivot) // se o elemento for menor que o pivot...
        {
            for (j = fim; j >= i; j--)
            {
                if (vetor[j] < pivot)
                {
                    troca(vetor, i, j);
                    break;
                }
            }
        }
    }
    troca(vetor, inicio, j); // coloca o pivot na posição correta
    return j;                // retorna o indice do pivot
}

void QuickSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = part(vetor, inicio, fim); // encontra o pivo
        QuickSort(vetor, inicio, pivo - 1);  // ordena o inicio do pivo
        QuickSort(vetor, pivo + 1, fim);     // ordena o final do pivo
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

    clock_t start, end;

    printf("Array antes da ordenacao: ");
    print(vetorInicial, tamVetor);

    start = clock();
    QuickSort(vetorInicial, 0, tamVetor - 1);
    end = clock();

    double TempoExec = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Array apos a ordenacao: ");
    print(vetorInicial, tamVetor);

    printf("\nTempo de execucao: %f\n", TempoExec);
    printf("Quantidade de Iteracoes: %d", count);

    return 0;
}