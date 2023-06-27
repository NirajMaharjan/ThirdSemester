#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Stack{
	int info;
	struct Stack* next;
};
typedef struct Stack stack;


stack* top;
void push();
void pop();
void display();

int main(){
	
	int choice;
	top=NULL;
	do{
		system("cls");
		printf("1.Push \n2.Pop \n3.Display \n4.Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
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

void push(){
	stack *newNode;
	int item;
	newNode=(stack*)malloc(sizeof(stack));
	printf("Enter the data: ");
	scanf("%d",&item);
	if (top==NULL){
		top=newNode;
		newNode->info=item;
		newNode->next=NULL;
		return;
	}
	else{
		newNode->info=item;
		newNode->next=top;
		top=newNode;
		return;
	}
}

void display(){
	stack *temp;
	if (top==NULL){
		printf("Stack Empty");
		return;
	}
	temp=top;
	while(temp!=NULL){
		printf("%3d",temp->info);
		temp=temp->next;
	}
	
}

void pop(){
	stack *temp;
	if (top==NULL){
		printf("Stack Empty");
		return;
	}
	temp=top;
	
	top=top->next;
	printf("%d is popped",temp->info);
	free(temp);
	
}
