//implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5


typedef struct{
	int arr[max];
	int top;
}stack;

void createStack(stack *s){
	s->top=-1;
}

int isFull(stack *s){
	if((s->top)==max-1){
		return 1;
	}
	return 0;
}

int isEmpty(stack *s){
	if((s->top)==-1){
		return 1;
	}
	return 0;
}

void push(stack *s,int item){
	if(isFull(s)){
		printf("Stack Full");
		return;
	}
	s->arr[++(s->top)]=item;
}

void pop(stack *s){
	if (isEmpty(s)){
		printf("Stack Empty");
		return;
	}
	printf("%d is popped",s->arr[(s->top)--]);
}

void displayStack(stack *s){
	int i;
	if (isEmpty(s)){
		printf("stack empty");
		return;
	}
	for(i=s->top;i>=0;i--){
		printf("%3d",s->arr[i]);
	}
}

void peek(stack *s){
	if (isEmpty(s)){
		printf("stack empty");
		return;
	}
	printf("%d",s->arr[s->top]);
}
int main(){
	stack s;
	int choice,item;
	createStack(&s);
	do{
		system("cls");
		printf("\nEnter your choice:\n");
		printf("1.push \n2.pop \n3.display \n4.peek \n5.Exit\n");
		scanf("%d",&choice);
		if (choice==1){
			printf("\nEnter the item to be pushed: ");
			scanf("%d",&item);
			push(&s,item);
		}
		else if(choice==2){
			pop(&s);
		
		}
		
		else if(choice==3){
			displayStack(&s);
		
		}
		else if(choice==4){
			peek(&s);
		
		}
		else if(choice==5){
			printf("Quitting...Press any key to continue");
		}
		getch();
	}while(choice!=5);
	return 0;
}
