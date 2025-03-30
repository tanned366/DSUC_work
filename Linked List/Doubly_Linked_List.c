#include<stdio.h>
#include<stdlib.h>
struct Node {
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *ptr=NULL;

struct Node *create(){
    struct Node *New;
    New = (struct Node*) malloc (sizeof(struct Node));
    New->next = NULL;
    New->prev = NULL;
    return New;
}

void traverse(struct Node *ptr) {
    if(ptr == NULL) printf("List Empty");
    else{
        while(ptr != NULL) {
            printf("|%d|->", ptr->info);
            ptr = ptr->next;
        }
        printf("X");
    }
}

struct Node *insert_beg(struct Node *start){
    struct Node *New = create();
	printf("\nEnter the data in New Node");
	scanf("%d",&New->info);
    if (start == NULL) start = New;
    else{
        New->next = start;
        start->prev = New;
        start = New;
    }
    traverse(start);
    return start;
}

struct Node *insert_end(struct Node *start){
    struct Node *New = create();
    printf("\nEnter the data in New Node");
	scanf("%d",&New->info);
    if (start == NULL) start = New;
    else{
        struct Node *temp = create();
        while(temp->next != NULL) temp = temp->next;
        temp->next = New;
        New->prev = temp;
    }
    printList(start);
	return start;
}

struct Node *insert_loc(struct Node *start){
    int item;
	printf("\nEnter the node data after which New node can be inserted");
	scanf("%d",&item);
    struct Node *temp=start;
    while(temp->next != NULL){
        if(temp->info == item) break;
        else temp = temp->next;
    }
    if(temp == NULL) printf("\nNode not found");
    else{
        struct Node *New = create();
        printf("\nEnter the data in New Node");
    	scanf("%d",&New->info);
        if(temp->next == NULL) {
            temp->next = New;
        }
        else{
            New->next = temp->next;
            temp->next->prev = New;
            temp->next = New;
            New->prev = temp;
            traverse(start);
        }
    }
    return start;
}

struct Node *del_beg(struct Node *start){
	if(start==NULL) printf("\nList is Empty");
	else{
		struct Node *temp=start;
        if(start->next == NULL) start = NULL;
		else {
            start=start->next;
	    	start->prev=NULL;
        }
        printf("\n%d is deleted from List",temp->info);
		free(temp);
		printList(start);
	}
	return start;
}

struct Node *del_last(struct Node *start) {
    if(start == NULL) printf("\nList is empty");
    else{
        struct Node *temp = start;
        while(temp->next != NULL) temp = temp->next;
        if(temp == start) start = NULL;
        else temp->prev->next = NULL;
        printf("\n%d is deleted from List",temp->info);
		free(temp);
        traverse(start);
    }
    return start;
}

struct Node *del_loc(struct node *start) {
    int item;
	printf("\nEnter the node value to be deleted");
	scanf("%d",&item);
	struct Node *temp=start;
	while(temp!=NULL) {
		if(item==temp->info) break;
        else temp=temp->next;
	}
    if(temp == NULL) printf("Node not found");
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("%d is deleted", temp->info);
        free(temp);
        traverse(start); 
    }
    return start;
}

struct Node *search(struct Node *start) {
    int item, pos = 1;
    printf("\nEnter node data to search: ");
    scanf("%d", &item);
    struct Node *temp = start;
    while (temp != NULL){
        if (temp->info == item){
            printf("Node found at %d", pos);
            return temp;
        }
        temp = temp->next;
        pos++;
    }
    printf("Node not found");
    return NULL;
}

void main(){
	int choice;
	do{
    printf("\n1.Insert at Beginning  2.Insert at End  3.Insert at Any Location\n"
        "4.Delete First Node  5.Delete Last Node  6.Delete by Data\n"
        "7..Exit");
	printf("\nEnter Choice: ");scanf("%d",&choice);
	switch(choice) {
		case 1: ptr=insert_beg(ptr); break;
		case 2: ptr=insert_end(ptr); break;
		case 3: ptr=insert_loc(ptr); break;
		case 4: ptr=del_beg(ptr); break;
		case 5: ptr=del_last(ptr); break;
		case 6: ptr=del_loc(ptr); break;
        case 7: break;
        default: printf("\nInvalid Choice");
	}
	}while(choice != 7);
}