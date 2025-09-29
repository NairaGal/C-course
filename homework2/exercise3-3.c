#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    char start, end;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i != 0 && s1[i+1] != '\0') {
            start = s1[i-1];
            end = s1[i+1];

            if ((isdigit(start) && isdigit(end) && start <= end) ||
                (isalpha(start) && isalpha(end) && ((islower(start) && islower(end)) || (isupper(start) && isupper(end))))) {
                
                for (char c = start + 1; c <= end; c++)
                    s2[j++] = c;

                i++;
            } else {
                s2[j++] = s1[i];
            }
        } else if (!(s1[i] == '-' && (i == 0 || s1[i+1] == '\0'))) {
            s2[j++] = s1[i];
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-z0-9b-d-";
    char s2[500];

    expand(s1, s2);
    printf("Original: %s\n", s1);
    printf("Expanded: %s\n", s2);

    return 0;
}

