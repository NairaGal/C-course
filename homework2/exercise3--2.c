#include <stdio.h>

void unescape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            i++;
            if (t[i] == '\0') {
                s[j++] = '\\';
                break;
            }
            switch(t[i]) {
                case 'n': s[j++] = '\n'; break;
                case 't': s[j++] = '\t'; break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char escaped[] = "Hello\\teveryone\\n";
    char unescaped[200];

    unescape(unescaped, escaped);

    printf("escaped: %s\n", escaped);
    printf("unescaped:%s\n", unescaped);

    return 0;
}

