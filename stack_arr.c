#include <stdio.h>
#define size 5
int stack[size], top = -1;

void push() {
    if(top == size-1)   printf("Stack is full(Stack overflow)\n");
    else {
        int item;
        printf("Enter the element to be pushed: ");
        scanf("%d", &item);
        stack[++top] = item;
        printf("Element pushed successfully\n");
    }
}

void pop() {
    if(top == -1) printf("Stack is empty(Stack underflow)\n");
    else {
        printf("Element popped: %d\n", stack[top--]);
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

/* 1. Create an empty stack for operators.
2. Create an empty list for the output (postfix expression).
3. For each token in the infix expression:
   a. If the token is an operand, add it to the output.
   b. If the token is '(', push it onto the stack.
   c. If the token is an operator:
      - While the stack is not empty and the top of the stack has an operator with greater or equal precedence:
         - Pop the operator from the stack and add it to the output.
      - Push the current operator onto the stack.
   d. If the token is ')':
      - Pop from the stack to the output until '(' is found.
      - Pop and discard '('.
4. After reading the expression, pop all remaining operators from the stack and add them to the output.
5. The output list contains the postfix expression. */

/*Algorithm for Evaluating a Postfix Expression
1. Initialize an empty stack.
2. Scan the postfix expression from left to right.
3. For each token (operand or operator):
    >> If it is an operand (number), push it onto the stack.
    >> If it is an operator:
        * Pop the top two operands from the stack.
        * Apply the operator to them.
        * Push the result back onto the stack.
4. After processing the expression, the final result will be on top of the stack.*/