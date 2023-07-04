#include "heap.h"
#include "helpprints.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS                "haesiqr:n:p:"
#define DEFAULT_SEED           13371453
#define DEFAULT_ELEMENTS       100
#define DEFAULT_PRINT_ELEMENTS 100

int main(int argc, char **argv) {
    //this is how the set will be managed
    //-a (all) will just enable all the sorts
    //
    //... 1   |1   1   1   1   |1   1   1   1
    //(unused)|    R   N   P   |Q   S   I   E
    //
    //the R and N will be turned on and turned off to direct the seed and things
    //H does not require a spot because it just prints things and ends it

    Set options = empty_set();
    uint64_t seed = DEFAULT_SEED;
    uint32_t num_elements = DEFAULT_ELEMENTS;
    uint32_t num_print_elements = DEFAULT_PRINT_ELEMENTS;

    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            options = insert_set(0x00000000, options); //enables heap sort
            options = insert_set(0x00000001, options); //enables shell sort
            options = insert_set(0x00000002, options); //enables insert sort
            options = insert_set(0x00000003, options); //enables quick sort
            break;
        case 'e':
            options = insert_set(0x00000000, options); //enables heap sort
            break;
        case 's':
            options = insert_set(0x00000001, options); //enables shell sort
            break;
        case 'i':
            options = insert_set(0x00000002, options); //enables insert sort
            break;
        case 'q':
            options = insert_set(0x00000003, options); //enables quick sort
            break;
        case 'h': helpprints(); return 0;
        case 'r': seed = atoi(optarg); break;
        case 'n': num_elements = atoi(optarg); break;
        case 'p': num_print_elements = atoi(optarg); break;
        default:
            printf("THIS MESSAGE SHOULD NOT SHOW UP YOUR SWITCH STATMENT IS DISFUNCTIONAL\n");
            return 1;
        }
    }
    if (num_print_elements > num_elements) {
        num_print_elements = num_elements;
    }

    Stats Current_Stats;
    srandom(seed);
    uint32_t *elements = malloc(sizeof(uint32_t) * num_elements);
    for (uint32_t i = 0; i < num_elements; i++) {
        elements[i] = random() & 0x3FFFFFFF;
    }
    reset(&Current_Stats);

    if ((options & 0x0000000F) == 0x00000000) {
        printf("Select at least one sort to perform.\n");
        helpprints();
        return 0;
    }

    //HEAP SORT
    if (member_set(0x00000000, options)) {
        heap_sort(&Current_Stats, elements, num_elements);
        printf("Heap Sort, %u elements, %lu moves, %lu compares\n", num_elements,
            Current_Stats.moves, Current_Stats.compares);
        for (uint32_t i = 1; i < num_print_elements + 1; i++) {
            printf("%13u", elements[i - 1]);
            if (i % 5 == 0) {
                printf("\n");
            }
        }

        srandom(seed);
        for (uint32_t i = 0; i < num_elements; i++) {
            elements[i] = random() & 0x3FFFFFFF;
        }

        reset(&Current_Stats);
    }

    //SHELL SORT
    if (member_set(0x00000001, options)) {
        shell_sort(&Current_Stats, elements, num_elements);
        printf("Shell Sort, %u elements, %lu moves, %lu compares\n", num_elements,
            Current_Stats.moves, Current_Stats.compares);

        for (uint32_t i = 1; i < num_print_elements + 1; i++) {
            printf("%13u", elements[i - 1]);
            if (i % 5 == 0) {
                printf("\n");
            }
        }

        srandom(seed);
        for (uint32_t i = 0; i < num_elements; i++) {
            elements[i] = random() & 0x3FFFFFFF;
        }
        reset(&Current_Stats);
    }

    //INSERTION SORT
    if (member_set(0x00000002, options)) {
        reset(&Current_Stats);
        insertion_sort(&Current_Stats, elements, num_elements);
        printf("Insertion Sort, %u elements, %lu moves, %lu compares\n", num_elements,
            Current_Stats.moves, Current_Stats.compares);

        for (uint32_t i = 1; i < num_print_elements + 1; i++) {
            printf("%13u", elements[i - 1]);
            if (i % 5 == 0) {
                printf("\n");
            }
        }

        srandom(seed);
        for (uint32_t i = 0; i < num_elements; i++) {
            elements[i] = random() & 0x3FFFFFFF;
        }
        reset(&Current_Stats);

        //QUICK SORT
    }
    if (member_set(0x00000003, options)) {
        reset(&Current_Stats);
        quick_sort(&Current_Stats, elements, num_elements);
        printf(
            "Quick Sort: %lu moves, %lu compares\n", Current_Stats.moves, Current_Stats.compares);

        for (uint32_t i = 1; i < num_print_elements + 1; i++) {
            printf("%13u", elements[i - 1]);
            if (i % 5 == 0) {
                printf("\n");
            }
        }
    }
    free(elements);
    printf("\n"); 
    return 0;
}
