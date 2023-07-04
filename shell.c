#include "shell.h"

#include "stats.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {

    uint32_t k_max = (uint32_t)(log(2 * n + 3) / log(3));
    for (uint32_t k = k_max; k > 0; k--) {
        uint32_t gap = (pow(3, k) - 1) / 2;
        for (uint32_t i = gap; i < n; i++) {
            uint32_t j = i;
            uint32_t temp = move(stats, A[i]);
            while (j >= gap && cmp(stats, temp, A[j - gap]) == -1) {
                A[j] = move(stats, A[j - gap]);
                j -= gap;
            }
            A[j] = move(stats, temp);
        }
    }
}
