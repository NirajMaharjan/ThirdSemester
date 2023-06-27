//main ko last ma free al the nodes
//insert ko harek case ma euta item vako case add

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>





struct LinkedList{
	int info;
	struct LinkedList *next;
};
typedef struct LinkedList node;

node *start;

void dBegin();
void dEnd();
void dNth();
node *read();
void iBegin();
void iEnd();
void iNth();
void display();
void search();
void countNode();
void del();

int main(){
	int choice;
	do{
		system("cls");
		printf("1.insert at begin \n2.Insert at end  \n3.Insert at nth node \n4.Display \n5.Count Nodes \n");
		printf("6.Delete Beginning \n7.Delete End \n8.Delete nth node \n9.search \n0.Quit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				iBegin();
				break;
			case 2:
				iEnd();
				break;
			case 3:
				iNth();
				break;
			case 4:
				display();
				break;	
			case 5:
				countNode();
				break;	
			case 6:
				dBegin();
				break;
			
			case 7:
				dEnd();
				break;
				
			case 8:
				dNth();
				break;
			case 9:
				search();
				break;
			case 0:
				printf("Quitting...Press any key to continue.");
				break;
		}
		
		getch();
	}while(choice!=0);
	
	return 0;
}


node* read(){								//on test for creating nodes
	node *newNode;
	int item;
	newNode=(node*)malloc(sizeof(node));
	printf("Enter the item: ");
	scanf("%d",&item);
	newNode->info=item;
	return newNode;
}	


void iBegin(){										//beginning insertion
	if (start==NULL){							//to insert into empty
		node *newNode=read();
		newNode->next=start;
		start=newNode;
	}
	else{										//insert into beginning for non-empty
		node *newNode=read();
		newNode->next=start;
		start=newNode;
	}
}

void iEnd(){
	node *newNode=read();
	node* temp,*prevNode;

	
	temp=start;
	while(temp!=NULL){
		prevNode=temp;
		temp=temp->next;
	}
	newNode->next=NULL;
	prevNode->next=newNode;
}

void iNth(){
	node *newNode=read();
	node* temp,*prevNode;
	int pos,n=1;
	
	printf("Enter the position to insert at: ");
	scanf("%d",&pos);
	temp=start;
	while(n!=pos){
		prevNode=temp;
		temp=temp->next;
		n++;
	}
	newNode->next=prevNode->next;		//(or temp) temp contains next node address
	prevNode->next=newNode;

}
void display(){
	node* temp;
	int i=0;
	if(start==NULL){
		printf("List Empty");
	}
	temp=start;
	while (temp!=NULL){
		printf("\n a[%d]=%d",i,temp->info);
		i++;
		temp=temp->next;
	}
}

void countNode(){
	node *temp;
	int count=0;
	temp=start;
	while (temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("The total number of nodes is %d",count);
}


void search(){
	int key,i;
	node* temp;
	temp=start;
	if(start==NULL){
		printf("List Empty..");
		return;
	}
	printf("Enter the key you want to search: ");
	scanf("%d",&key);
	while(temp!=NULL){
		i++;
		if(temp->info==key){
			printf("%d found at node %d",key,i);
			return;
			
		}
		temp=temp->next;
	}
	printf("%d not found in the list.",key);
}
void del(){
	if(start==NULL){
		printf("Empty List");
		return;
	}
	else if(start->next==NULL){
		printf("%d is deleted.",start->info);
		free(start);
		start=NULL;
		return;
	}
}
void dBegin(){
	node *temp;


	del();
	printf("%d is deleted",start->info);
		/*	unexpected error
		temp=start->next;
		start=temp;
		free(temp);
		*/
	temp=start;
	start=start->next;
	free(temp);
	return;

	
	
}


void dEnd(){
	node *temp=start;
	
	del();
	
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	printf("%d is deleted",temp->next->info);
	free(temp->next);
	temp->next=NULL;
}


void dNth(){
	node *prevNode=start;
	node* temp;
	int n=1,node;
	del();
	printf("Enter the node you want to delete: ");
	scanf("%d",&node);
	while(n<node-1){
		prevNode=prevNode->next;
		n++;
	}
	temp=prevNode->next;
	prevNode->next=prevNode->next->next;
	printf("%d is deleted.",temp->info);
	free(temp);
	
}
