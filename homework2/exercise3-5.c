#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i = 0;
    int isNegative = 0;
    unsigned int num;

    if (n == 0) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }

    if (n < 0 && b == 10) {
        isNegative = 1;
        num = -n;
    } else {
        num = (unsigned int)n;
    }

    while (num > 0) {
        int rem = num % b;
        s[i++] = (rem > 9) ? ('A' + rem - 10) : ('0' + rem);
        num /= b;
    }

    if (isNegative)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = 255;
    char s[50];

    itob(n, s, 2);
    printf("Binary: %s\n", s);

    itob(n, s, 8);
    printf("Octal: %s\n", s);

    itob(n, s, 10);
    printf("Decimal: %s\n", s);

    itob(n, s, 16);
    printf("Hexadecimal: %s\n", s);

    return 0;
}

