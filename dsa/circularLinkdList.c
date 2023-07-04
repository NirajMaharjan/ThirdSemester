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
void search();
//void destruct();

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
//	destruct();

	return 0;
}


void insert(int x){
	int item;
	int pos,n=1;
	node *temp=first;
	
	
	node *newNode=(node*)malloc(sizeof(node));
	
	if (newNode==NULL){								//if no memory
		printf("Unable to allocate the memory");
		return;
	}
	
	printf("Enter the data: ");
	scanf("%d",&item);
	newNode->info=item;
	
	if (first==NULL){				//empty case
		first=last=newNode;
		newNode->next=first;
		return;
	}
	if (x==1){						//at begin (non-empty)
		newNode->next=first;
		first=newNode;
		last->next=first;
		return;
		
	}
	if(x==2){						//at end
		last->next=newNode;
		last=newNode;
		last->next=first;
		return;
	}
	
	if (x==3){						//at nth node
		printf("Enter the position you want to insert");
		scanf("%d",&pos);
		while(n<pos-1){
			temp=temp->next;
			n++;
		}
		newNode->next=temp->next;
		temp->next=newNode;
		
		
	}
		
	
}

void display(){
	node* temp;

	int* i;
	*i=1;
	if(first==NULL){
		printf("Empty List");
		return;
	}
	temp=first;
	while(temp->next!=first){
		printf("\nnode %d=%d",*i,temp->info);
		temp=temp->next;
		(*i)++;
	}
	printf("\nnode %d=%d",*i,temp->info);
}

void del(int x){
	node* temp;
	node* temp1;
	int n=1,pos;
	temp=first;
	
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
	if(x==1){
		
		first=first->next;
		last->next=first;
		printf("%d was deleted",temp->info);
		free(temp);
		return;
	}
	if(x==2){							//delete last
		while(temp->next!=last){
			temp=temp->next;
		}
		printf("%d was deleted",last->info);
		free(last);
		temp->next=first;
		last=temp;
		return;
	}
	
	if(x==3){						//delete nth node    if pos =last or first may not work
		printf("Enter the node you want to delete:");
		scanf("%d",&pos);
		while(n<pos-1){
			temp=temp->next;
			n++;
		}
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
	temp=first;
	printf("Enter the key you want to search: ");
	scanf("%d",&key);
	
	while(temp!=last){
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


/*void destruct(){
	node* temp=first;
	while(temp!=last){
		
		temp=temp->next;
		free(first);
		first=temp;
		
	}
	free(first);
}
*/
