/*
* This example helps demonstrate bubble using line by line output, and a possible table to display
* Variables as the update.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

long int _bs_opCount = 0;



void wait_for_keypress() {
    struct termios old, new;
    tcgetattr(STDIN_FILENO, &old);  // get current settings
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);  // disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    getchar();  // now returns immediately on any key

    tcsetattr(STDIN_FILENO, TCSANOW, &old);  // restore settings
}

// for each string, print a markdown like header
void display_table_header(const char** headers, int* col_sizes, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("| %-*s ", col_sizes[i], headers[i]);
    }
    printf("|\n");

    for (size_t i = 0; i < count; i++) {
        printf("|");
        // +2 for the spaces around the content
        for (int j = 0; j < col_sizes[i] + 2; j++) {
            printf("-");
        }
    }
    printf("|\n");
}

void print_array(int* array, int size, int col_width) {
    // Build the array string first to pad it properly
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if(i < size-1) {
            printf(", ");
        }
    }
    printf("]");
}

void print_table_row(int pass, int index, long int opCount, int* array, int size, int* col_sizes) {
    printf("| %*d | %*d | %*ld | ", col_sizes[0], pass, col_sizes[1], index, col_sizes[2], opCount);
    print_array(array, size, col_sizes[3]);
    printf(" |\n");
    // wait for keypress to continue
    wait_for_keypress();
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    _bs_opCount++;
}

void bubble_sort(int* array, int size, int* col_sizes) {
    print_table_row(-1, -1, _bs_opCount, array, size, col_sizes);

    for(int i = 0; i < size; i++){
        _bs_opCount++;
        bool swapped = false;
        for(int j = 0; j < size - i - 1; j++) {
            _bs_opCount++;
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = true;
            }

            print_table_row(i, j, _bs_opCount, array, size, col_sizes);
        } // inner loop
        if (!swapped) break;

    } // outer loop


}

int* get_randomized_array(int size) {
    int* array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));  // seed once at start of program

    int array_size = 4;
    if (argc > 1) {
        array_size = atoi(argv[1]);
    }
    int* array = get_randomized_array(array_size);

    const char* headers[] = { "Pass(i)", "Index(j)", "OpCount", "Array" };
    int col_sizes[4];
    for (size_t i = 0; i < 4; i++) {
        col_sizes[i] = strlen(headers[i]);
    }



    // Estimate array display width: "[" + numbers + ", " separators + "]"
    // Each number up to 2 digits, plus ", " between them
    if (array_size > 0) {
        int asize = 1 + (array_size * 2) + ((array_size - 1) * 2) + 1; // rough estimate
        if (asize > col_sizes[3]) {
            col_sizes[3] = asize;
        }
    }

    display_table_header(headers, col_sizes, 4);

    bubble_sort(array, array_size, col_sizes);

    free(array);
    return EXIT_SUCCESS;
}
