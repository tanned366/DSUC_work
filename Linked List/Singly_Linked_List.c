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

struct Node *del_beg(struct Node *start) {
    if(start == NULL) printf("\nLinked List is empty");
    else{
        struct Node *temp = start;
        start = start->next;
        printf("\n%d is deleted", temp->info);
        free(temp);
        printList(start);
    }
    return start;
}

struct Node *del_last(struct Node *start) {
    if(start == NULL) printf("\nLinked List is empty");
    else{
        struct Node *temp, *ptemp;
        temp = start;

        if(start->next == NULL) start = NULL;
        else{
            while(temp->next != NULL) {
                ptemp = temp;
                temp = temp->next;
            }
            ptemp->next = NULL; // deleted last node
        }
        printf("%d is deleted\n", temp->info);
        free(temp);
    }
    return start;
}

struct Node *del_loc(struct Node *start) {
    int item;
    printf("\nEnter the Node data to be deleted: ");
    scanf("%d", &item);

    struct Node *temp, *ptemp=NULL;
    temp = start;

    while(temp != NULL) {
        if(temp->info == item) break;
        else{
            ptemp = temp;
            temp = temp->next;
        }
    }

    if(temp == NULL) printf("\nLinked List is empty");
    else{
        if(temp == start) start = del_beg(start);
        else{
            ptemp->next = temp->next;
            printf("%d is deleted\n", temp->info);
            free(temp);
            printList(start);
        }
    }
    return start;
}

void search(struct Node *start) {
    int item, pos=1;
    printf("\nEnter the data to be searched: ");
    scanf("%d", &item);
    struct Node *temp = start;

    while (temp != NULL) {
        if (temp->info == item) {
            printf("\nNode found at: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\nNode Not Found\n");
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
            case 4: start = del_beg(start); break;
            case 5: start = del_last(start); break;
            case 6: start = del_loc(start); break;
            case 7: search(start); break;
            case 8: printList(start); break;
            case 9: break;
            default: printf("\nInvalid Choice\n");
        }
    } while (choice != 9);

    return 0;
}