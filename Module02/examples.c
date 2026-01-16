
#include <stdio.h>
#include <stdlib.h>


/*
--
x = 5
--
array + 0
--
array + 1
--
array + 2
--
array + 3
--
array + 4
--


*/

typedef struct myArray {
    int arr[100];
    int size;
} myArray;

void set_struct(myArray *arr, int val) {

    for(int i = 0; i < arr->size; i++) {
        arr->arr[i] = val;
    }

}

void print_struct(myArray *arr) {
    printf("Struct Size %d\n", arr->size);

    for(int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }

    printf("\n");


}

void structExample() {

    myArray arr;
    arr.size = 10;

    set_struct(&arr, 20);
    print_struct(&arr);

}

void set_array(int * arr, int size, int val) {

    for(int i = 0; i < size; i++) {
        arr[i] = val;
    }
}

int array_example() {

    int array[5];

    set_array(array, 5, 10);

    for(int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}

int another_function(int x, int y) {
    int combined_value = x + y;
    return combined_value % 2; // can only 0 or 1
}

int main() {
    //print(f"hello {name}")
    printf("Aloha, World!");
    float num = 1.0;
    printf("Aloha %.2f\n", num);

    int x = 10;
    int my_val = 5;
    int even_odd = another_function(x, my_val);

    printf("The return value %d,  even or odd?\n", even_odd);
    if(even_odd == 1) {
        printf("The value is odd\n");
    }else {
        printf("The value is even\n");
    }

    array_example();
    structExample();

    // and is &&
    // or  is  ||
    // if (num > 0 && num < 10) {
    //     printf("this should not print");
    // } else if (num > 11 && num < 20) { // optional
    //         printf("will this work?");
    //     }
    // else {
    //         printf("Oh no!\n");
    // }

    return EXIT_SUCCESS;
}
