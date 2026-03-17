#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
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

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    double time_used_ns;
    QueryPerformanceFrequency(&frequency);

    readFromFile(filename, original, n);

    // bubble sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    bubbleSort(test, n);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Bubble Sort: %.0f ns\n", time_used_ns);

    // insertion sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    insertionSort(test, n);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Insertion Sort: %.0f ns\n", time_used_ns);

    // selection sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    selectionSort(test, n);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Selection Sort: %.0f ns\n", time_used_ns);

    // merge sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    mergeSort(test, 0, n - 1);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Merge Sort: %.0f ns\n", time_used_ns);

    // quick sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    quickSort(test, 0, n - 1);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Quick Sort: %.0f ns\n", time_used_ns);

    // heap sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    heapSort(test, n);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Heap Sort: %.0f ns\n", time_used_ns);

    // radix sort
    copyArray(original, test, n);
    QueryPerformanceCounter(&start);
    radixSort(test, n);
    QueryPerformanceCounter(&end);
    time_used_ns = (double)(end.QuadPart - start.QuadPart) * 1000000000.0 / (double)frequency.QuadPart;
    printf("Radix Sort: %.0f ns\n", time_used_ns);

    free(original);
    free(test);

    return 0;
}