// Implementation of Double Ended Queue using static memory allocation.
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Que;

void initQue(Que* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Que* q) {
    return ((q->front == -1) && (q->rear == -1));
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
    if(isEmpty(q)) {
        q->front = 0;
        q->arr[++q->rear] = val;
        printf("Inserted %d at front\n", val);
    } else if(q->front > 0) {
        q->arr[--q->front] = val;
        printf("Inserted %d at front\n", val);
    } else
        printf("Front insertion not possible\n");
}

void insertAtRear(Que* q, int val) {
    if(isEmpty(q)) {
        q->front = 0;
        q->arr[++q->rear] = val;
        printf("Inserted %d at rear\n", val);
    } else if(q->rear != MAX-1) {
        q->arr[++q->rear] = val;
        printf("Inserted %d at rear\n", val);
    } else
        printf("Rear insertion is not possible\n");
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
    int choice, val;
    do {
        printf("\n1- Insert at front\n2- Insert at rear\n");
        printf("3- Delete at front\n4- Delete at rear\n");
        printf("5- Display\n6- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value to insert at front: ");
                    scanf("%d", &val);
                    insertAtFront(&q, val);
                    break;
            case 2: printf("Enter value to insert at rear: ");
                    scanf("%d", &val);
                    insertAtRear(&q, val);
                    break;
            case 3: val = deleteAtFront(&q);
                    if(val != -1)
                        printf("Deleted element at front is: %d\n", val);
                    break;
            case 4: val = deleteAtRear(&q);
                    if(val != -1)
                        printf("Deleted element at rear is: %d\n", val);
                    break;
            case 5: display(&q);
                    break;
            case 6: printf("Exiting...\n");
                    break;
            default: printf("Invalid Choice\n... Retry");
        }
    } while(choice != 6);
    return 0;
}
