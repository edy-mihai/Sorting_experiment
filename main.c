#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algs.h"

void readFromFile(char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void copyArray(int source[], int dest[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

int main()
{
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int *original = (int *)malloc(n * sizeof(int));
    int *test = (int *)malloc(n * sizeof(int));

    if (original == NULL || test == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }

    char filename[100];
    printf("File name: ");
    scanf("%s", filename);

    clock_t start, end;
    double time_used;

    readFromFile(filename, original, n);

    // bubble sort
    copyArray(original, test, n);
    start = clock();
    bubbleSort(test, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f s\n", time_used);

    // insertion sort
    copyArray(original, test, n);
    start = clock();
    insertionSort(test, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f s\n", time_used);

    // selection sort
    copyArray(original, test, n);
    start = clock();
    selectionSort(test, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f s\n", time_used);

    // merge sort
    copyArray(original, test, n);
    start = clock();
    mergeSort(test, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f s\n", time_used);

    // quick sort
    copyArray(original, test, n);
    start = clock();
    quickSort(test, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f s\n", time_used);

    // heap sort
    copyArray(original, test, n);
    start = clock();
    heapSort(test, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort: %f s\n", time_used);

    // radix sort
    copyArray(original, test, n);
    start = clock();
    radixSort(test, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Radix Sort: %f s\n", time_used);

    free(original);
    free(test);

    return 0;
}