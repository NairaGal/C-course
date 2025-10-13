#include <stdio.h>
#include <stdlib.h> // for malloc()

int main() {
    int *a, i, j, tmp, n;

    printf("\n\n Pointer : Sort an array using pointer :\n");
    printf("--------------------------------------------\n");

    // Input number of elements
    printf(" Input the number of elements to store in the array : ");
    scanf("%d", &n);

    // Allocate memory dynamically
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf(" Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf(" Input %d number of elements in the array : \n", n);
    for (i = 0; i < n; i++) {
        printf(" element - %d : ", i + 1);
        scanf("%d", a + i);
    }

    // Sorting the array using pointer
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    // Displaying sorted array
    printf("\n The elements in the array after sorting : \n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : %d \n", i + 1, *(a + i));
    }

    free(a); // Free allocated memory
    printf("\n");
    return 0;
}

