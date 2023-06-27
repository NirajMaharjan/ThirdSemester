//implementation of linear queue shifting

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5

struct LinearQueue{
	int q[max];
	int front;
	int rear;
};
typedef struct LinearQueue lqueue;

void enqueue(lqueue *lq){
	int item;
	if (lq->rear==(max-1)){
		printf("Queue is Full");
		return;
	}
	printf("\nEnter the item to enqueue");
	scanf("%d",&item);
	lq->q[++lq->rear]=item;
	return;
}

void dequeue(lqueue *lq){
	int i;
	if(lq->rear<lq->front){
		printf("Queue is Empty");
		return;
	}
	printf("The deleted element is %d\n", lq->q[lq->front]);
	for (i=lq->front+1;i<=lq->rear;i++){
		lq->q[i-1]=lq->q[i];
	}
	lq->rear--;
	return;
}

void display(lqueue lq){
	int i;
	if(lq.rear<lq.front){
		printf("Queue is Empty");
		return;
	}
	for (i=lq.front;i<=lq.rear;i++){
		printf("%3d",lq.q[i]);
	}
	
}
int main(){
	lqueue lq;
	int choice;
	lq.rear=-1;
	lq.front=0;
	
	
	do{
		system("cls");
		printf("1.enqueue \n2.dequeue \n3.display \n4.Exit");
		printf("\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue(&lq);
				getch();
				break;
			case 2:
				dequeue(&lq);
				getch();
				break;
			case 3:
				display(lq);
				getch();
				break;
			case 4:
				printf("Quitting...");
				getch();
				break;
				
		}
	
	}while(choice!=4);
	return 0;
}
