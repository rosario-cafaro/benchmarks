#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    // Declare the array, it will contains 10k integer values
    int integers[10000], rows = 10000, i = 0;

    // File pointer
    FILE *fptr;

    // Opens the existing file for reading.
    fptr = fopen("../../data/10k_integers.txt", "r");
    if (fptr == NULL)
    {
        printf("10k_integers.txt file not found \n");
        return 1;
    }
    else
    {
        // Store the integers into an array
        while (rows--)
        {
            fscanf(fptr, "%d", &integers[i]);
            i++;
        }
    }

    // Sort the array
    quickSort(integers, 0, 10000 - 1);

    // Print the resulting array and save the integers into another file
    // for (int y = 0; y < 10000; y++)
    // {
    //     printf("%d: %d\n", y, integers[y]);
    //     FILE *fptr_sorted;
    //     fptr_sorted = fopen("../data/10k_integers_sortedC.txt", "a");
    //     fprintf(fptr_sorted, "%d\n", integers[y]);
    // }

    // Print first & last elements
    printf("First element: %d\nLast element: %d\n", integers[0], integers[10000 - 1]);

    // Close the stream
    fclose(fptr);

    return 0;
}