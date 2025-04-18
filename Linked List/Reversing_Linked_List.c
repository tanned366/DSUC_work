#include <stdio.h>

struct Node {
    int info;
    struct Node *next;
};
struct Node *head = NULL;

int main() {
    struct Node *prev=NULL, *curr=head, *nex;
    while(curr!=NULL) {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return 0;
}