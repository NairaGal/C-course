/**
 * @file sort_array.c
 * @brief Program to sort an array of integers entered by the user.
 *
 * This program dynamically allocates an array of integers based on user input,
 * sorts the array using a separate function, and prints the sorted array.
 *
 * @author Naira
 * @date 2025-12-01
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Sorts an array of integers in ascending order using bubble sort.
 * 
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 */
void sortArray(int *arr, int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Main function that reads input, sorts array, and prints it.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    sortArray(arr, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

