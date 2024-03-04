#include <stdio.h>
#include <stdlib.h>

// Define structure to represent time
typedef struct {
    int hour;
    int minute;
    int second;
} time;

// Function to read time from user input
void readTime(time *t) {
    printf("Enter hour, minute, and second (separated by spaces): ");
    scanf("%d %d %d", &(t->hour), &(t->minute), &(t->second));
}

// Function to display time
void displayTime(time *t) {
    printf("%02d:%02d:%02d\n", t->hour, t->minute, t->second);
}

// Function to update time by adding one second
void updateTime(time *t) {
    t->second += 1;
    if (t->second > 59) {
        t->second = 0;
        t->minute += 1;
        if (t->minute > 59) {
            t->minute = 0;
            t->hour += 1;
            if (t->hour == 24) {
                t->hour = 0;
            }
        }
    }
    printf("The updated time is: ");
    displayTime(t);
}

// Function to add two times
void addTimes(time *t1, time *t2) {
    time sum;
    sum.second = t1->second + t2->second;
    sum.minute = t1->minute + t2->minute;
    sum.hour = t1->hour + t2->hour;
    if (sum.second > 59) {
        sum.second -= 60;
        sum.minute++;
    }
    if (sum.minute > 59) {
        sum.minute -= 60;
        sum.hour++;
    }
    if (sum.hour > 23) {
        sum.hour -= 24;
    }
    printf("\nResult of adding Time 1 and Time 2: ");
    displayTime(&sum);
}

int main() {
    time *t, *t1, *t2;
    int choice;
    t = (time *)malloc(sizeof(time));
    t1 = (time *)malloc(sizeof(time)); // Allocate memory for t1
    t2 = (time *)malloc(sizeof(time)); // Allocate memory for t2
    do {
        printf("\nMenu:\n");
        printf("1. Read Time\n");
        printf("2. Display Time\n");
        printf("3. Update Time\n");
        printf("4. Add Two Times\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readTime(t);
                break;
            case 2:
                displayTime(t);
                break;
            case 3:
                updateTime(t);
                break;
            case 4:
                printf("Enter time 1:\n");
                readTime(t1);
                printf("Enter time 2:\n");
                readTime(t2);
                addTimes(t1, t2); // Pass pointers t1 and t2
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
    free(t);
    free(t1); // Free memory allocated for t1
    free(t2); // Free memory allocated for t2
    return 0;
}
