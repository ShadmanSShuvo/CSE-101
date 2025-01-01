#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char arr0[] = "listen";
char arr1[] = "earth";
char arr2[] = "binary";
int c0 = 1, c1 = 1, c2 = 1;

int len(char str[]) {
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++)
        n++;
    return n;
}

void randStr(char str[], char perm[]) {
    for (int i = 0; i < len(str); i++) {
        perm[i] = str[i];
    }
    perm[len(str)] = '\0'; // Null-terminate the perm array

    for (int i = 0; i < len(perm); i++) {
        int t = rand() % len(perm);
        char tmp = perm[i];
        perm[i] = perm[t];
        perm[t] = tmp;
    }
}

void anagram(int nmbr) {
    char t[10];
    char perm[10];
    printf("Starting Anagram Challenge...\n");

    switch (nmbr) {
        case 0: {
            for (int j = 0; j < 3; j++) {
                randStr(arr0, perm);
                printf("Scrambled word: %s\n", perm);

                // Clear input buffer and take user input
                scanf(" %[^\n]s", t);

                int a[26] = {0};
                int i;
                for (i = 0; i < len(arr0); i++) {
                    a[tolower(arr0[i]) - 'a']++;
                }
                for (i = 0; i < len(t); i++) {
                    a[tolower(t[i]) - 'a']--;
                }

                int is_correct = 1;
                for (i = 0; i < 26; i++) {
                    if (a[i] != 0) {
                        is_correct = 0;
                        break;
                    }
                }

                if (is_correct) {
                    printf("Correct! You solved it in %d attempt(s).\n", c0);
                    break;
                } else {
                    printf("Your guess: %s\n", t);
                    printf("Incorrect! Try again.\n");
                    c0++;
                }
            }
            break;
        }
        // Add cases for `arr1` and `arr2` if needed
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int nmbr = rand() % 3;

    char s[10];
    char perm[10];

    printf("Enter a string to scramble: ");
    scanf("%9s", s); // Limit input to prevent overflow

    randStr(s, perm);
    printf("Scrambled string: %s\n", perm);

    anagram(nmbr);

    return 0;
}
