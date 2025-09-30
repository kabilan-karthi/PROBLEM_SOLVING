#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparator function for qsort (used to sort the string)
int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int t;
    scanf("%d", &t);   // read number of test cases

    while (t--) {      // repeat for each test case
        int n;
        char s[50];    // max n = 40, so 50 is safe
        scanf("%d", &n);   // read length of string
        scanf("%s", s);    // read the string

        char sorted_s[50];
        strcpy(sorted_s, s);   // copy original string into sorted_s

        // sort the copy using qsort
        qsort(sorted_s, n, sizeof(char), cmp);

        int k = 0;   // count of mismatched positions
        for (int i = 0; i < n; i++) {
            if (s[i] != sorted_s[i]) {
                k++;   // count the difference
            }
        }

        printf("%d\n", k);   // print result for this test case
    }

    return 0;
}
