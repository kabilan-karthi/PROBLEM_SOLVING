#include <stdio.h>
#include <string.h>

int main() {
    // Example input string b
    char b[] = "bccddaaf";

    int len = strlen(b);   // Length of b
    char a[105];           // To store the secret string a
    int index = 0;         // Index for a[]

    // Step 1: Take the first character of b
    a[index++] = b[0];

    // Step 2: Take every second character starting from index 1
    for (int i = 1; i < len; i += 2) {
        a[index++] = b[i];
    }

    // Step 3: Terminate the string
    a[index] = '\0';

    // Step 4: Output the secret string a
    printf("Original string a: %s\n", a);

    return 0;
}
