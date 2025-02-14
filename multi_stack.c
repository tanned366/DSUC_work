#include <stdio.h>
#define size 10
int stack[size];
int topA = -1, topB = size;

void pushA() {
    if(topA == topB - 1) printf("Stack Overflow\n");
    else{
        int item;
        printf("Enter element to push in stack A: ");
        scanf("%d", &item);
        stack[++topA] = item;
    }
}

void popA() {
    if(topA == -1) printf("Stack Underflow\n");
    else printf("Popped element from stack A is: %d\n", stack[topA--]);
}

void pushB() {
    if(topB == topA + 1) printf("Stack Overflow\n");
    else{
        int item;
        printf("Enter element to push in stack B: ");
        scanf("%d", &item);
        stack[--topB] = item;
    }
}

void popB() {
    if(topB == size) printf("Stack Underflow\n");
    else printf("Popped element from stack B is: %d\n", stack[topB++]);
}

void traverseA() {for(int i=topA; i>=0; i--) printf("%d ", stack[i]);}

void traverseB() {for(int i=topB; i<size; i++) printf("%d ", stack[i]);}

int main() {
    int choice;
    do {
        printf("\n1. Push A\n2. Pop A\n3. Traverse A\n4. Push B\n5. Pop B\n6. Traverse B\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: pushA(); break;
            case 2: popA(); break;
            case 3: traverseA(); break;
            case 4: pushB(); break;
            case 5: popB(); break;
            case 6: traverseB(); break;
            case 7: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(1);
    
    return 0;
}