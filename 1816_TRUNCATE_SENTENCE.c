#include <stdio.h>
#include <string.h>

char* truncateSentence(char* s, int k) {
    int count = 0;   // to count words
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {   // whenever we see a space, one word ended
            count++;
            if (count == k) {   // if we reached k words
                s[i] = '\0';    // cut the string here
                break;
            }
        }
    }
    return s;
}

int main() {
    char s1[] = "Hello how are you Contestant";
    int k1 = 4;
    printf("%s\n", truncateSentence(s1, k1)); // Output: Hello how are you

    char s2[] = "What is the solution to this problem";
    int k2 = 4;
    printf("%s\n", truncateSentence(s2, k2)); // Output: What is the solution

    char s3[] = "chopper is not a tanuki";
    int k3 = 5;
    printf("%s\n", truncateSentence(s3, k3)); // Output: chopper is not a tanuki

    return 0;
}
