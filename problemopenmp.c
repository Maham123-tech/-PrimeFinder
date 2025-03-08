#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>  // OpenMP for parallel execution

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void find_primes(int start, int end) {
    int count = 0;
    double start_time = omp_get_wtime();  // Start timer

    #pragma omp parallel for schedule(dynamic) reduction(+:count)
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            #pragma omp critical
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
    find_primes(start, end);
    return 0;
}
