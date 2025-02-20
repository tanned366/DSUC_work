#include <stdio.h>
#define size 5
int queue[size];
int front=-1, rear=-1;

void enqueue() {
    if((rear+1)%size == front) {
        printf("\nQueue is overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;   // First element insertion
    else rear = (rear+1)%size;    // Move rear in circular manner
    int item;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);
    queue[rear] = item;
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is underflow\n");
        return;
    }
    printf("\nElement %d dequeued successfully\n", queue[front]);
    if (front == rear) front = rear = -1;    // Last element removed, reset queue
    else front = (front + 1) % size;    // Move front in circular manner
}

void display() {
    if (front == -1) {
        printf("\nQueue is Underflow\n");
        return;
    }
    printf("\n Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice;
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: enqueue();break;
            case 2: dequeue();break;
            case 3: display();break;
            case 4: break;
            default: printf("\nInvalid Choice\n");
        }
    }while(choice != 4);
    
    return 0;
}