#include <stdlib.h> // exit
#include <stdint.h>
#include <string.h>

#include "rules.h"
#ifndef DIM
#define DIM 9
#define SQUARE_DIM 3
#endif

uint8_t check_row(uint8_t* row) {
    // check if 1-9 are in the row
    uint8_t i, j, counter;
    uint8_t uniques[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (i=0; i < DIM; i++) {
        counter = 0;
        for (j = 0; j < DIM; j++) {
            if (row[j] > 0 && row[j] == uniques[i]) {
                // unique value
                counter++;
            }
        }
        if (counter > 1) {
            printf("ERROR: value %d occurs %d times in this row\n", \
                     uniques[i], counter);
            return 0;
            break;
        } else {
        printf("%d is counted %d times in this row\n", i+1, counter);
        counter = 0;
        }
    }
    return 1;
}

uint8_t check_col(uint8_t* col) {
    // check if 1-9 are in the column
    uint8_t i, j, counter;
    // 
    uint8_t uniques[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (i=0; i < DIM; i++) {
        counter = 0;
        for (j = 0; j < DIM*DIM; j+=9) {
            if (col[j] > 0 && col[j] == uniques[i]) {
                // unique value
                counter++;
            }
        }
        if (counter > 1) {
            printf("ERROR: value %d occurs %d\
            times in this col\n", uniques[i], counter);
            return 0;
            break;
        } else {
        printf("%d is counted %d times in this col\n", i+1, counter);
        counter = 0;
        }
    }
    return 1;
}

uint8_t is_in_col(uint8_t* col, uint8_t value, uint8_t offset) {
    // checks if value is in column nr offset 
    uint8_t i;
    for (i = 0; i < DIM; i++) {
        if (col[i * DIM + offset] == value) {
            return 1;
        }
    }
return 0;
}