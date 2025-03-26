#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *start = NULL;

void printList(struct Node *ptr) {
    if(ptr == NULL) printf("Linked List is empty\n");
    else{
        while(ptr != NULL) {
            printf("|%d|->", ptr->info);
            ptr = ptr->next;
        }
        printf("X\n");
    }
}

struct Node *create() {
    struct Node *New;
    New = (struct Node*) malloc (sizeof(struct Node));
    New->next = NULL;
    return New;
}

struct Node *insert_beg(struct Node *start){
    struct Node *New = create();
    printf("\nEnter data: ");
    scanf("%d", &New->info);
    New->next = start;    // if(start == NULL){
    start = New;          // start = New;
    printList(start);     // start->next = NULL;
    return start;         // }
}

struct Node *insert_end(struct Node *start) {
    struct Node *New = create();
    printf("\nEnter data: ");
    scanf("%d", &New->info);
    if(start == NULL) start = New;
    else {
        struct Node *temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next  = New;
    }
    printList(start);
    return start;
}

struct Node *insert_loc(struct Node *start) {
    int item;
    printf("\nEnter the node value after which you want to insert: ");
    scanf("%d", &item);
    struct Node *temp = start;
    while (temp != NULL){
        if (temp->info == item) break;
        else temp = temp->next;
    }
    if(temp == NULL) printf("\nNode not Found");
    else{
        struct Node *New = create();
        printf("\nEnter data: ");
        scanf("%d", &New->info);
        New->next = temp->next;
        temp->next = New;
    }
    printList(start);
    return start;
}

int main() {
    int choice;
    do {
        printf("\n1.Insert at Beginning  2.Insert at End  3.Insert at Any Location\n"
                "4.Delete First Node  5.Delete Last Node  6.Delete by Data\n"
                "7.Search  8.Print List  9.Exit");     
        printf("\nEnter choice: "); scanf("%d", &choice);
        switch (choice) {
            case 1: start = insert_beg(start); break;
            case 2: start = insert_end(start); break;
            case 3: start = insert_loc(start); break;
            case 8: printList(start); break;
            case 9: break;
            default: printf("\nInvalid Choice\n");
        }
    } while (choice != 9);

    return 0;
}