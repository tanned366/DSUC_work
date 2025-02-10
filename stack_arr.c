#include <stdio.h>
#define size 5
int stack[size], top = -1;

void push() {
    if(top == size-1)   printf("Stack is full(Stack overflow)\n");
    else {
        int item;
        printf("Enter the element to be pushed: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Element pushed successfully\n");
    }
}

void pop() {
    if(top == -1) printf("Stack is empty(Stack underflow)\n");
    else {
        printf("Element popped: %d\n", stack[top]);
        top--;
    }
}


int main() {
    char choice;
    do {
        printf("1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1': push(); break;
            case '2': pop(); break;
            case '3': break;
            default: printf("Invalid choice\n");
        }
    } while(choice != '3');

    return 0;
}