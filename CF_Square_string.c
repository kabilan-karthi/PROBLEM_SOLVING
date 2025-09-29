#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        char s[105];            // input strings have length <= 100
        scanf("%s", s);         // read the string
        int n = strlen(s);

        // If length is odd, it cannot be square
        if (n % 2 == 1) {
            printf("NO\n");
            continue;
        }

        int half = n / 2;
        int is_square = 1;      // assume it's square until proven otherwise

        // Compare first half with second half
        for (int i = 0; i < half; i++) {
            if (s[i] != s[i + half]) {
                is_square = 0;
                break;
            }
        }

        printf(is_square ? "YES\n" : "NO\n");
    }

    return 0;
}
