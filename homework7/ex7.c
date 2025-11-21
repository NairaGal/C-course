#include <stdio.h>

int main() {
    int arr1[25], i, n = 5; 

    printf(" Input 5 number of elements in the array :\n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : ", i);
        scanf("%d", arr1 + i);
    }

    printf(" The elements you entered are : \n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : %d \n", i, *(arr1 + i)); 
    }
    return 0;
}

