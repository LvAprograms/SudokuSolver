#include <stdio.h> // printf
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

void check_square(uint8_t* sq) {
    // in fact, you only need to know if something is already in the square.
    // plan: start at top left: index 0. increment up to SQUARE_DIM. Then add 
    // DIM and do the same, up to index = SQUARE_DIM * DIM, after which index is
    // reset to 0 + SQUARE_DIM
    uint8_t topleft,i, r, c, counter;
    uint8_t* vals = malloc(DIM * sizeof(uint8_t*) );

    topleft = 0;
    uint8_t last_square = DIM * DIM - (SQUARE_DIM-1) * DIM - SQUARE_DIM; 
    printf("last square should be 80 - 20 = 60 : %d\n", last_square);
    while (topleft <= last_square) {
        counter++;
        for (r = 0; r < SQUARE_DIM; r++) {
            for (c = 0; c < SQUARE_DIM; c++) {
                vals[r*SQUARE_DIM+c] = sq[topleft + r*DIM+c];
                // printf("mat[%d] = %d?\n", topleft+c+(r*DIM), vals[r*SQUARE_DIM+c]);
            }
        }
        for (i = 0; i < DIM; i++) {
            if (count_in_square(vals, i+1) > 1) {
                printf("There are too many %ds found at point(TODO, TODO)\n", i+1);
                exit(1);
                break;
            } 
        }
        calloc(*vals, DIM*sizeof(uint8_t*));
        if (counter % SQUARE_DIM == 0) {
            topleft += (SQUARE_DIM - 1) * DIM + SQUARE_DIM;
        } else {
            topleft += SQUARE_DIM;
        }
        printf("topleft = %d\n", topleft);
    }
    free(vals);
}

uint8_t count_in_square(uint8_t* square, uint8_t val) {
    uint8_t i, counter; 
    counter = 0;

    printf("counting %d in square %d\n", val, *square);
    for (i = 0; i < DIM; i++) {
        if (val == square[i]) {
            counter++;
        }
    }
    return counter;
}