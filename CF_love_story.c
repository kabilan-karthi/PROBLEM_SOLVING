#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    char target[] = "codeforces";  // the fixed string we compare with

    while (t--) {
        char s[15];  // string length is always 10, but keep a bit extra
        scanf("%s", s);

        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != target[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
