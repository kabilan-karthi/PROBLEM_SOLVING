#include <stdio.h>   // for input/output functions
#include <string.h>  // for strcmp()

int main() {
    int n;                      // number of names
    scanf("%d", &n);            // read n from input

    char names[100][101];       // array to store up to 100 names, each up to 100 chars + '\0'

    for (int i = 0; i < n; i++) {         // process each name in order
        scanf("%100s", names[i]);         // read the i-th name into names[i]
        int found = 0;                    // flag: 0 means not seen before, 1 means seen before

        for (int j = 0; j < i; j++) {     // compare with all previous names (0 .. i-1)
            if (strcmp(names[i], names[j]) == 0) { // strcmp == 0 means strings are equal
                found = 1;                // mark as seen before
                break;                    // no need to check further
            }
        }

        if (found)                        // if name was seen earlier
            printf("YES\n");              // print YES
        else
            printf("NO\n");               // else print NO
    }

    return 0;                             // end program
}
