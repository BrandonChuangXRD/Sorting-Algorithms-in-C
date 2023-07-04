#include "stats.h"

#include <stdint.h>
#include <stdio.h>

int cmp(Stats *stats, uint32_t x, uint32_t y) {
    stats->compares += 1;
    if (x < y) {
        return -1;
    }
    if (x == y) {
        return 0;
    }
    if (x > y) {
        return 1;
    }
    return 2;
}

uint32_t move(Stats *stats, uint32_t x) {
    stats->moves += 1;
    return x;
}

void swap(Stats *stats, uint32_t *x, uint32_t *y) {
    stats->moves += 3;
    uint32_t temp = *x;
    *x = *y;
    *y = temp;
}

void reset(Stats *stats) {
    stats->moves = 0;
    stats->compares = 0;
}
