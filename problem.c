#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N = 100000;  // Define the range limit
    clock_t start, end;
    
    start = clock(); // Start time measurement

    int primeCount = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            primeCount++;
        }
    }

    end = clock(); // End time measurement

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Total primes found: %d\n", primeCount);
    printf("Execution time (Sequential): %f seconds\n", time_taken);

    return 0;
}
