#include <stdio.h> // fopen, fclose, fscanf
#include <stdlib.h> // exit
#include <stdint.h>
#include <string.h>

// own stuff

#define DIM 9
#define SQUARE_DIM 3

#include "rules.h"


void print_sudoku(uint8_t* mat);
void fill_sudoku(FILE *fp, uint8_t* mat);
void sort_array(uint8_t* arr);
int length(uint8_t* arr);
void swap(uint8_t* ptr1, uint8_t* ptr2);
void brute_force(uint8_t* S);


int main(int argc, char* argv) {
    printf("Dit is een echte serverkoe!\n");

    // initialise sudoku matrix with zeros and print it.
    static uint8_t matrix[DIM][DIM];
    uint8_t *S = &matrix[0][0];
    unsigned char counter = 0;
    uint8_t i, j;
    printf("-----------------------\n");
    for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                matrix[i][j] = (uint8_t)0;
                if (((j+1) % SQUARE_DIM) == 0)
                {
                    printf("%d | ", matrix[i][j]);
                }
                else
                {
                    printf("%d ", matrix[i][j]);
                }
            }
            printf("\n");
            if ((i+1) % SQUARE_DIM == 0)
            {
                printf("-----------------------\n");
            }
        }
    // file pointer
    FILE *fptr;

    //open file
    fptr = fopen("test.txt", "r");
    if (fptr == NULL)
    {
        printf("Error in opening the sudoku file\n");
        exit(1);
    }

    // fill sudoku from file
    fill_sudoku(fptr, S);
    
    // close file
    fclose(fptr);

    // print sudoku as it is
    print_sudoku(S);
    // test check_row function
    for (uint8_t i = 0; i < DIM*DIM; i+=DIM) {
        // printf("\nchecking row %d\n", (i/DIM)+1);
        // check_row(&S[i]);
        // printf("\nchecking column %d\n", (i/DIM)+1);
        // check_col(&S[i/DIM]);
        // printf("row %d: %d\n", i, S[i]);
    }
    printf("\nChecking squares...\n");
    check_square(&S[0]); 

    return 0;
}

void print_sudoku(uint8_t* mat) {
    uint8_t i, j;
    printf("-----------------------\n");
    for (i = 0; i < DIM; i++) {
            for (j = 0; j < DIM; j++) {
                if (((j+1) % SQUARE_DIM) == 0) {
                    printf("%d | ", *((mat + i*DIM)+ j)); 
                } else {
                    printf("%d ",  *((mat + i*DIM)+ j));
                }
            }
            printf("\n");
            if ((i+1) % SQUARE_DIM == 0) {
                printf("-----------------------\n");
            }
        }
}

void fill_sudoku(FILE* fp, uint8_t* mat) {
    uint8_t i = 0;
    int v;
    // read the file char for char and replace the zero in mat
    // if you see 218, this is 13, which is carriage return
    while((v = fgetc(fp)) != EOF) {
        if (v != '\n') {
            // printf("%d ", v);
            *(mat+i) = v - '0';
            i++;
        } 
    }       
}

void solve_bruteforce(uint8_t* mat) {
    // takes a filled sudoku, starts at the top 
    printf("attempting to solve the crap out of this thing\n");
}




   
void sort_array(uint8_t* arr) {
    int n = length(arr);
    int i;
    uint8_t counter;
    do  {
        counter = 0;
        for (i=1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                // swap array elements
                swap(&arr[i-1], &arr[i]);
                counter++;
            }
        }
     } while (counter > 0);
}

int length(uint8_t* arr) {
    return sizeof(arr) / sizeof(*arr);
}

void swap(uint8_t* ptr1, uint8_t* ptr2) {
    uint8_t* tmp;
    tmp = ptr2;
    ptr2 = ptr1;
    ptr1 = tmp;
}








