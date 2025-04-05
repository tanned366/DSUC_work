#include<stdio.h>
#include<stdlib.h>
struct Node {
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *ptr=NULL;

void traverse(struct Node *start)
{
	if(start==NULL)
	printf("\nList is Empty");
	else
	{
		struct Node *ptr=start;
		while(ptr->next!=start)
		{
			printf("|%d|",ptr->info);
			ptr=ptr->next;
		}
		printf("|%d|",ptr->info);
	}
}

struct Node *insert_beg(struct Node *start) {
	struct Node *New;
	New=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter the data in new Node");
	scanf("%d",&New->info);
	if(start==NULL){
		start=New;
		start->next=start;
		start->prev=start;
	} else{
		New->next = start;
		New->prev = start->prev;
		start->prev->next = New;
		start->prev = New;
		start = New;
	}
	traverse(start);
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