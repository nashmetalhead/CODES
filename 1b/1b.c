// 1.b) Define a structure called Time containing 3 integer members (Hour, Minute,
// Second). Develop a menu driven program to perform the following by writing
// separate function for each operation.
// a) Read (T) :To read time
// b) Display (T):To display time
// c) update(T):To Update time
// d) Add (T1, T2) : Add two time variables.
// Update function increments the time by one second and returns the new time (if
// the increment results in 60 seconds, then the second member is set to zero and
// minute member is incremented by one. If the result is 60 minutes, the minute
// member is set to zero and the hour member is incremented by one. Finally, when
// the hour becomes 24, Time should be reset to zero. While adding two time
// variables, normalize the resultant time value as in the case of update function.
// Note: Illustrate the use of pointer to pass time variable to different functions.

#include <stdio.h>
#include <stdlib.h>

// Define structure to represent time
typedef struct {
    int hour;
    int minute;
    int second;
}time;

// Function to read time from user input
time readTime(time *t) {
    printf("Enter hour, minute, and second (separated by spaces): ");
    scanf("%d %d %d", &(t->hour), &(t->minute), &(t->second));
    return *t;
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
void addTimes(time t1, time t2) {
    time sum;
    sum.second = t1.second + t2.second;
    sum.minute = t1.minute + t2.minute;
    sum.hour = t1.hour + t2.hour;
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
    time *t, t1, t2;
    int choice;
    t = (time *)malloc(sizeof(time));
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
                *t = readTime(t);
                break;
            case 2:
                displayTime(t);
                break;
            case 3:
                updateTime(t);
                break;
            case 4:
                printf("Enter time 1:\n");
                t1 = readTime(&t1);
                printf("Enter time 2:\n");
                t2 = readTime(&t2);
                addTimes(t1, t2);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
    free(t);
    return 0;
}
