// 2. Develop a menu driven program to implement the following operations on an
// array of integers with dynamic memory allocation. Display the array contents
// after each operation.
// i) Insert by position
// ii) Delete by key
// iii) Search by position
// iv) Reverse the contents.
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertByPosition(int *arr, int *n, int pos, int key);
void deleteByKey(int *arr, int *n, int key);
void searchByPosition(int *arr, int *n, int pos);
void reverse(int *arr, int *n);
void printArray(int *arr, int *n);

// Function to insert an element at a specified position
void insertByPosition(int *arr, int *n, int pos, int key) {
    if (pos < 0 || pos > *n + 1) { // pos < 1 is start is 0
        printf("Invalid position\n");
        return;
    }
    (*n)++;
    for (int i = *n - 1; i > pos; i--) { // pos-1 if start is 1
        arr[i] = arr[i - 1];
    }
    arr[pos] = key; // same applies for this also
    printf("Element %d inserted at position %d\n", key, pos);
}

// Function to delete an element by its value
void deleteByKey(int *arr, int *n, int key) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == key) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            printf("Element %d deleted\n", key);
            break;
        }
    }
    if (found == 0) {
        printf("Key not found\n");
    }
}

// Function to search for an element by its position
void searchByPosition(int *arr, int *n, int pos) {
    if (pos >= 0 && pos <= *n - 1) {
        printf("Element at position %d is %d\n", pos, arr[pos]);
    } else {
        printf("Invalid position\n");
    }
}

// Function to reverse the elements of the array
void reverse(int *arr, int *n) {
    for (int i = 0; i < *n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[*n - i - 1];
        arr[*n - i - 1] = temp;
    }
    printf("Array reversed\n");
}

// Function to print the elements of the array
void printArray(int *arr, int *n) {
    printf("Current array: ");
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr, n, choice;
    int pos, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }
    do {
        printf("\nMenu: \n");
        printf("1. Insert by position.\n");
        printf("2. Delete by Key.\n");
        printf("3. Search By Position.\n");
        printf("4. Reverse the content.\n");
        printf("5. Exit\n\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the position and element to insert: ");
                scanf("%d %d", &pos, &key);
                insertByPosition(arr, &n, pos, key);
                break;
            case 2:
                printf("Enter the key element to delete: ");
                scanf("%d", &key);
                deleteByKey(arr, &n, key);
                break;
            case 3:
                printf("Enter the position to search: ");
                scanf("%d", &pos);
                searchByPosition(arr, &n, pos);
                break;
            case 4:
                printf("Reversing the array...\n");
                reverse(arr, &n);
                break;
            case 5:
                printf("Exiting the program\n");
                free(arr);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        printArray(arr, &n);
    } while (choice!=5);
    return 0;  
}
