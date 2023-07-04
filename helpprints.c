#include "helpprints.h"

#include <stdio.h>

int helpprints(void) {
    //taken from the output of the executable in rseources
    printf("SYNOPSIS\n");
    printf("   A collection of comparison-based sorting algorithms.\n\n");
    printf("USEAGE\n");
    printf("   ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
    printf("OPTIONS \n");
    printf("   -h              display program help and usage.\n");
    printf("   -a              enable all sorts.\n");
    printf("   -e              enable Heap Sort.\n");
    printf("   -i              enable Insertion Sort.\n");
    printf("   -s              enable Shell Sort.\n");
    printf("   -q              enable Quick Sort.\n");
    printf("   -n length       specify number of array elements (default: 100).\n");
    printf("   -p elements     specify number of elements to print (default: 100).\n");
    printf("   -r seed         specify random seed (default: 13371453).\n");
    return 0;
}
