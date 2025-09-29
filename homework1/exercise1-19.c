#include <stdio.h>

#define MAXLINE 1000

int getline_custom(char line[], int limit) {
    int c, i = 0;
    while (i < limit - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int i = 0, j = 0;
    char temp;

    while (s[j] != '\0')  
        j++;
    j--;  

    if (s[j] == '\n')
	    j--;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char line[MAXLINE];
    int len;

    while ((len = getline_custom(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

