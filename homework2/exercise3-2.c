#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j = 0;
    for(i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

int main() {
    char text[] = "Hello\teveryone\n";
    char escaped[200];
    escape(escaped, text);
    printf("original: %s\n", text);
    printf("escaped: %s\n", escaped);
    return 0;
}

