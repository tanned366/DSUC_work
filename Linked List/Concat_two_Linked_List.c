#include<stdio.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *concat(struct Node *start1, struct Node *start2) {
    if(start1 == NULL && start2 == NULL) {
        printf("\nList is empty");
        return NULL;
    }
    else if(start1 == NULL) return start2;
    else if(start2 == NULL) return start1;
    else{
        struct Node* temp = start1;
        while(temp->next !=NULL) temp = temp->next;
        temp->next = start2;
        return start1;
    }
}