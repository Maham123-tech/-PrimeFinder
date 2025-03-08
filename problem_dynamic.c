#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to find prime numbers using OpenMP with dynamic scheduling
void find_primes(int start, int end) {
    int count = 0;

    double start_time = omp_get_wtime();  // Start timer

    #pragma omp parallel for schedule(dynamic) reduction(+:count)
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            #pragma omp critical  // Prevent race conditions in printing
            printf("%d ", i);
            count++;
        }
    }

    double end_time = omp_get_wtime();  // End timer

    printf("\nTotal prime numbers: %d\n", count);
    printf("Execution Time: %f seconds\n", end_time - start_time);
}

int main() {
    int start, end;

    printf("Enter the range (start end): ");
    scanf("%d %d", &start, &end);

    printf("Finding primes using OpenMP (Dynamic Scheduling)...\n");
    find_primes(start, end);

    return 0;
}
