#include <stdio.h>
#include <stdlib.h>


struct circular{
	int info;
	struct circular *next;
};
typedef struct circular node;

node *first;
node *last;

void insert(int);
void del(int);
void display();


int main(){
	int choice;
	do{
		system("cls");
		printf("1.Insert \n2.Delete \n3.Search \n4.Display \n5.Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				del();
				break;

			case 3:
				display();
				break;
			case 5:
				printf("Quitting...press any key to continue.");
				
		}
		getch();
	}while(choice!=5);
	return 0;
}


void insert(){
	int item;
	node *newNode=(node*)malloc(sizeof(node));
	if (newNode==NULL){
		printf("Unable to allocate the memory");
		return;
	}
	printf("Enter the data: ");
	scanf("%d",&item);
	newNode->info=item;
	
	if (first==NULL){
		first=last=newNode;
		newNode->next=first;
		return;
	}
	else{
		newNode->next=first;
		first=newNode;
		last->next=first;
		
	}
		
	
}

void display(){
	node* temp;
	int* i;
	*i=0;
	if(first==NULL){
		printf("Empty List");
		return;
	}
	temp=first;
	while(temp->next!=first){
		printf("\na[%d]=%d",*i,temp->info);
		temp=temp->next;
		(*i)++;
	}
	printf("\na[%d]=%d",*i,temp->info);
}

void del(){
	node* temp;
	if(first==NULL){
		printf("List Empty");
		return;
	}
	else if(first==last){
		printf("%d was deleted",first->info);
		free(first);
		first=last=NULL;
		return;
	}
	temp=first;
	first=first->next;
	last->next=first;
	printf("%d was deleted",temp->info);
	free(temp);
	return;
}

