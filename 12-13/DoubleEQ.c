// Implementation of Double Ended Queue using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

#define INITIAL_CAPACITY 2

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int CAP;
} Que;

void initQue(Que* q) {
    q->front = -1;
    q->rear = -1;
    q->CAP = INITIAL_CAPACITY;
    q->arr = (int*)malloc(q->CAP * sizeof(int));
}

int isEmpty(Que* q) {
    return ((q->front == -1) && (q->rear == -1));
}

void resize(Que* q) {
    int newCapacity = q->CAP * 2;
    int *newArr = (int*)malloc(newCapacity * sizeof(int));
    
    // Copy elements to the new array
    for (int i = q->rear, j = q->rear; i >= q->front; i--, j--) {
        newArr[j] = q->arr[i];
    }

    free(q->arr);
    q->arr = newArr;
    q->front = 0;
    q->rear = q->CAP - 1;
    q->CAP = newCapacity;
    printf("Queue resized to %d capacity\n", q->CAP);
}

void display(Que* q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void insertAtFront(Que* q, int val) {
    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->arr[q->front] = val;
        printf("Inserted %d at front\n", val);
    } else if (q->rear < q->CAP - 1) {
        // Shift existing elements to make room for new element
        for (int i = q->rear + 1; i > q->front; i--) {
            q->arr[i] = q->arr[i - 1];
        }
        q->rear++;
        q->arr[q->front] = val;
        printf("Inserted %d at front\n", val);
    } else {
        printf("Front insertion not possible\n");
        printf("Resizing...\n");
        resize(q);
        // After resizing, update rear index
        q->rear++;
        // Shift existing elements to make room for new element
        for (int i = q->rear; i > q->front; i--) {
            q->arr[i] = q->arr[i - 1];
        }
        q->arr[q->front] = val;
        printf("Inserted %d at front\n", val);
    }
}

void insertAtRear(Que* q, int val) {
    if(isEmpty(q)) {
        q->front = 0;
        q->arr[++q->rear] = val;
        printf("Inserted %d at rear\n", val);
    } else if(q->rear != q->CAP - 1) {
        q->arr[++q->rear] = val;
        printf("Inserted %d at rear\n", val);
    } else {
        printf("Rear insertion is not possible\n");
        printf("Resizing...\n");
        resize(q);
        q->arr[++q->rear] = val;
        printf("Inserted %d at rear\n", val);
    }
}

int deleteAtFront(Que* q) {
    if(isEmpty(q)) {
        printf("Empty Queue\nDelete At Front Not Possible\n");
        return -1;
    }
    int item = q->arr[q->front++];
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

int deleteAtRear(Que* q) {
    if(isEmpty(q)) {
        printf("Empty Queue\nDelete At Rear Not Possible\n");
        return -1;
    }
    int item = q->arr[q->rear--];
    if(q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

int main() {
    Que q;
    initQue(&q);
    int choice, data;
    do {
        printf("\nQueue Operations Menu\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&q, data);
                display(&q);
                break;
            case 2:
                printf("Enter the data to insert at rear: ");
                scanf("%d", &data);
                insertAtRear(&q, data);
                display(&q);
                break;
            case 3:
                data = deleteAtFront(&q);
                if(data != -1)
                    printf("Deleted element from front: %d\n", data);
                display(&q);
                break;
            case 4:
                data = deleteAtRear(&q);
                if(data != -1)
                    printf("Deleted element from rear: %d\n", data);
                display(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
    
    free(q.arr);
    
    return 0;
}
