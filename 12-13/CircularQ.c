// Implementation of Circular Queue using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
typedef struct {
    int front, rear;
    int CAP;
    int *arr;
} Que;

void initQ(Que *q) {
    q->front = -1;
    q->rear = -1;
    q->CAP = MAX;
    q->arr = (int*)malloc(q->CAP * sizeof(int));
}

int isEmpty(Que* q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Que* q) {
    return ((q->rear + 1) % q->CAP == q->front);
}

void resize(Que* q) {
    int newSize = q->CAP * 2;
    int *newArr = (int*)malloc(newSize * sizeof(int));
    printf("Resizing...\n");
    int i = 0;
    int temp = q->front;
    do {
        newArr[i++] = q->arr[temp];
        temp = (temp + 1) % q->CAP;
    } while (temp != (q->rear + 1) % q->CAP);

    free(q->arr);
    q->arr = newArr;
    q->front = 0;
    q->rear = i - 1;
    q->CAP = newSize; // Update the MAX size
}

void enque(Que* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!!!\n");
        resize(q);
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->CAP;
    }
    q->arr[q->rear] = value;
    printf("%d inserted into the Queue\n", value);
}

int deque(Que* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!!!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->CAP;
    }
    return data;
}

void display(Que* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int temp = q->front;
    do {
        printf("%d ", q->arr[temp]);
        temp = (temp + 1) % q->CAP;
    } while (temp != (q->rear + 1) % q->CAP);
    printf("\n");
}

int main() {
    Que q;
    initQ(&q);
    int choice, data;
    do {
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                enque(&q, data);
                display(&q);
                break;
            case 2:
                data = deque(&q);
                if(data != -1)
                    printf("Dequeued element is : %d\n", data);
                display(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
    free(q.arr);
    return 0;
}
