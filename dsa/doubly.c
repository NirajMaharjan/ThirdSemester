#include <stdio.h>
#include <stdlib.h>


struct doubly{
	int info;
	struct doubly *next;
	struct doubly *prev;
};
typedef struct doubly node;

node *start;



void insert(int);
void del(int);
void display();
void search();
void destruct();


int main(){
	int choice;
	do{
		system("cls");
		printf("1.Insert at beginning \n2.Insert at end \n3.Insert at nth node \n4.Delete beginning node");
		printf("\n5.Delete last node \n6.Delete nth node \n7.Display \n8.Search \n9.Quit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				insert(1);
				break;
			case 2:
				insert(2);
				break;
			case 3:
				insert(3);
				break;
			case 4:
				del(1);
				break;
			case 5:
				del(2);
				break;
			case 6:
				del(3);
				break;

			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				printf("Quitting...press any key to continue.");
				
		}
		getch();
	}while(choice!=9);
	destruct();

	return 0;
}


void insert(int x){
	int item;
	int pos,n=1;
	node *temp=start;
	
	
	node *newNode=(node*)malloc(sizeof(node));
	
	if (newNode==NULL){								//if no memory
		printf("Unable to allocate the memory");
		return;
	}
	
	printf("Enter the data: ");
	scanf("%d",&item);
	newNode->info=item;
	
	if (start==NULL){				//empty case
		newNode->next=newNode->prev=NULL;
		start=newNode;
		return;
	}
	if (x==1){						//at begin (non-empty)
		newNode->next=start;
		start->prev=newNode;
		start=newNode;
		newNode->prev=NULL;		
	}
	
	if(x==2){						//at end
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=NULL;
		newNode->prev=temp;
	
	}
	
	if (x==3){							//at nth node
		printf("Enter the position you want to enter:");
		scanf("%d",&pos);			
		while(n<pos-1){
			temp=temp->next;
			n++;
		}
		newNode->next=temp->next;
		newNode->next->prev=newNode;
		temp->next=newNode;
		newNode->prev=temp;
		
		
	}
		
	
}

void display(){
	node* temp;
	temp=start;
	int n=1;
	if(start==NULL){
		printf("List is empty.");
		return;
	}
	
	do{										
		printf("\na[%d]=%d",n,temp->info);
		temp=temp->next;
		n++;
	}while(temp!=NULL);

	return;
	
}

void del(int x){
	node* temp;
	node* temp1;

	int n=1,pos;
	temp=start;
	
	if(start==NULL){
		printf("List Empty");
		return;
	}
	else if(start->next==NULL){
		printf("%d was deleted",start->info);
		free(start);
		start=NULL;
		return;
	}
	if(x==1){
		start=temp->next;
		start->prev=NULL;
		printf("%d was deleted",temp->info);
		free(temp);
	}
	if(x==2){							//delete last
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		printf("%d was deleted",temp->next->info);
		free(temp->next);
		temp->next=NULL;
		

	}
	
	if(x==3){						//delete nth node    if pos =last or first may not work
		printf("Enter the node you want to delete:");
		
		scanf("%d",&pos);

		while(n<pos-1){
			temp=temp->next;
			n++;
		}
		temp->next->next->prev=temp;
		temp1=temp->next;
		temp->next=temp->next->next;
		printf("%d was deleted",temp1->info);
		free(temp1);
	}
	
}

void search(){
	node* temp;
	int key;
	int* n;
	*n=1;
	temp=start;
	printf("Enter the key you want to search: ");
	scanf("%d",&key);
	
	while(temp->next!=start){
		if(temp->info==key){
			printf("%d is found at node %d",key,*n);
			return;
		}
		(*n)++;
		temp=temp->next;
	}
	if (temp->info==key){
		printf("%d is found at node %d",key,*n);
	}
	else{
		printf("%d not found",key);
	}
	return;
}


void destruct(){
	node* temp=start;
	while(temp!=NULL){
		
		temp=temp->next;
		free(start);
		start=temp;
		
	}
}


