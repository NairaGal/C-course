#include <stdio.h>
#define MAXLINE 1000
#define LIMIT 80

int getline_custom(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = getline_custom(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            printf("%s", line);
        }
    }
    return 0;
}

int getline_custom(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}



