// Enter your code here
#include <stdio.h>

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);

    // Compute GCD
    long long a = A, b = B;
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    long long g = a; // GCD of A and B

    if (g == 1) {
        printf("-1\n"); // No common prime factor
        return 0;
    }

    // Find smallest prime factor of GCD
    if (g % 2 == 0) {
        printf("2\n");
        return 0;
    }

    for (long long i = 3; i * i <= g; i += 2) {
        if (g % i == 0) {
            printf("%lld\n", i);
            return 0;
        }
    }

    // If no factor found, GCD itself is prime
    printf("%lld\n", g);
    return 0;
}
