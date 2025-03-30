// Write a Program to implement Circular Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *next;
};
struct Node *start=NULL;

void traverse(struct Node *start){
	if(start==NULL) printf("\nList is Empty");
	else{
		struct Node *ptr=start;
		while(ptr->next!=start) {
			printf("|%d|->",ptr->info);
			ptr=ptr->next;
		}
		printf("|%d|",ptr->info);
	}
}
struct Node *insert_beg(struct Node *start){
	struct Node *New;
	New=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the data in New Node: ");
	scanf("%d",&New->info);
	if(start==NULL){
		start=New;
		start->next=start;
	} else{
		struct Node *temp;
		temp=start;
		while(temp->next!=start) temp=temp->next;
		New->next=start;
		start=New;
		temp->next=start;
	}
	traverse(start);
	return start;
}
struct Node *insert_end(struct Node *start){
	struct Node *New;
	New=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the data in New Node: ");
	scanf("%d",&New->info);
	if(start==NULL){
		start=New;
		start->next=start;
	} else{
		struct Node *temp=start;
		while(temp->next!=start) temp=temp->next;
		temp->next=New;
		New->next=start;		
	}
	traverse(start);
	return start;
}
struct Node *insert_loc(struct Node *start) {
    int item;
    printf("Enter the node value after which you want to insert: ");
    scanf("%d", &item);
    struct Node *temp = start;
    while (temp != NULL){
        if (temp->info == item) break;
        else temp = temp->next;
    }
    if(temp == NULL) printf("\nNode not Found");
    else{
        struct Node *New;
        New=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &New->info);
        New->next = temp->next;
        temp->next = New;
    }
    traverse(start);
    return start;
}

struct Node *del_beg(struct Node *start) {
	if(start==NULL) printf("\nList is Empty");
	else{
		struct Node *temp;
		temp=start;
		if(start==start->next) start=NULL;
		else{
			struct Node *ptr;
			ptr=start;
			while(ptr->next!=start) ptr=ptr->next;
			start=start->next;
			ptr->next=start;
		}
		printf("%d is deleted from List\n",temp->info);
		free(temp);
		traverse(start);
	}
	return start;
}
struct Node *del_last(struct Node *start){
	if(start==NULL) printf("\nList is Empty");
	else{
		struct Node *temp=start;
		if(start==start->next) start=NULL;
		else{
			struct Node *ptemp;
			while(temp->next!=start){
				ptemp=temp;
				temp=temp->next;
			}
			ptemp->next=start;
		}
		printf("%d is deleted from List\n",temp->info);
		free(temp);
		traverse(start);
	}
	return start;
}
struct Node *del_loc(struct Node *start) {
    int item;
    printf("Enter the Node data to be deleted: ");
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
    else {
        if(temp == start) start = del_beg(start);
        else{
            ptemp->next = temp->next;
            printf("%d is deleted\n", temp->info);
            free(temp);
            traverse(start);
        }
    }
    return start;
}

void main(){
	int choice;
	do{
    printf("\n1.Insert at Beginning  2.Insert at End  3.Insert at Any Location\n"
        "4.Delete First Node  5.Delete Last Node  6.Delete by Data\n"
        "7..Exit");
	printf("\nEnter Choice: ");scanf("%d",&choice);
	switch(choice) {
		case 1: start=insert_beg(start); break;
		case 2: start=insert_end(start); break;
		case 3: start=insert_loc(start); break;
		case 4: start=del_beg(start); break;
		case 5: start=del_last(start); break;
		case 6: start=del_loc(start); break;
        case 7: break;
        default: printf("\nInvalid Choice");
	}
	}while(choice != 7);
}