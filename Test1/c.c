#include <stdio.h>
void quicksort(int number[10000], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    // Declare the array, it will contains 10k integer values
    int integers[10000], rows = 10000, i = 0;

    // File pointer
    FILE *fptr;

    // Opens the existing file for reading.
    fptr = fopen("../data/10k_integers.txt", "r");
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
    quicksort(integers, 0, 10000 - 1);

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