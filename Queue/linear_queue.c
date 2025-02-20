#include <stdio.h>
#define size 5
int queue[size];
int front= -1, rear= -1;

void enqueue() {
    if(rear == size-1) printf("Queue Overflow\n");
    else {
        int item;
        printf("Enter Element to add to queue: ");
        scanf("%d", &item);
        if(front == -1) front = 0;
        queue[++rear] = item;
    }
}

void dequeue() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element is: %d\n", queue[front++]);
    if(front > rear) front=rear=-1;
}

int main() {
    int choice;
    do{
        printf("1. Queue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: enqueue();break;
            case 2: dequeue();break;
            case 3: break;
            default: printf("Invalid Choice\n");
        }
    }while(choice != 3);
    
    return 0;
}