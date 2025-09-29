#include <stdio.h>

int main() {
    int c, length = 0;
    int lengths[20];  
    int i, j;

    for (i = 0; i < 20; i++) 
        lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (length > 0 && length < 20) {
                lengths[length]++;
                length = 0;
            }
        } else {
            length++;
        }
    }

    printf("Word length histogram:\n");
    for (i = 1; i < 20; i++) {
        if (lengths[i] > 0) {
            printf("%2d: ", i);
            for (j = 0; j < lengths[i]; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}

