#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int info;
	struct Queue* next;
};
typedef struct Queue q;


q* front;
q* rear;
void enqueue();
void dequeue();
void display();

int main(){
	
	int choice;
	front=rear=NULL;
	do{
		system("cls");
		printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Quitting...Press any key to continue.");
		}
		getch();	
	}while(choice!=4);
	
	return 0;
}

void enqueue(){
	q *newNode;
	int item;
	newNode=(q*)malloc(sizeof(q));
	printf("Enter the data: ");
	scanf("%d",&item);
	newNode->info=item;
	newNode->next=NULL;
	if (front==NULL && rear==NULL){
		front=newNode;
	}
	else{
		
		rear->next=newNode;
	}
	rear=newNode;
}

void display(){
	q *temp;
	if (front==NULL){
		printf("Queue Empty");
		return;
	}
	temp=front;
	while(temp!=NULL){
		printf("%3d",temp->info);
		temp=temp->next;
	}
	
}

void dequeue(){
	q *temp;
	if (front==NULL){
		printf("Queue Empty");
		return;
	}

	temp=front;
	front=front->next;
	printf("%d is dequeued",temp->info);
	free(temp);
	
	
}
