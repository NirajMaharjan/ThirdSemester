#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5


struct List{
	int arr[max];
	int size;
};
typedef struct List list;

int isEmpty(list*);
int isFull(list *);
void insert(list *);
void Remove(list*);
void traverse(list*);
void search(list*);
void modify(list*);



int main(){
	list l;
	int option;
	l.size=0;

	
	do{
		system("cls");
		printf("1.Insert \n2.Remove \n3.Traverse \n4.Search \n5.Modify \n6.Exit");
		printf("\nEnter your choice: ");
		scanf ("%d",&option);
		switch(option){
			case 1:
				insert(&l);
				break;
			case 2:
				Remove(&l);
				break;
			case 3:
				traverse(&l);
				break;
			case 4:
				search(&l);
				break;
			case 5:
				modify(&l);
				break;
			case 6:
				printf("Quitting...");
				break;
		}
		getch();
	}while(option!=6);
	return 0;
}

int isFull(list *l){
	if (l->size==max){
		return 1;
	}
	return 0;
}

int isEmpty(list *l){
	if (l->size==0){
		return 1;
	}
	return 0;
}
void insert(list *l){
	int n,pos,i;
	if (isFull(l)){
		printf("List is Full");
		return;
	}
	printf("Enter the item to push: ");
	scanf("%d",&n);
	printf("Enter the index to push item: ");
	scanf("%d",&pos);
	if(pos>l->size+1 || pos<1){
		printf("Wrong Index");
		return;
	}
	if (pos==(l->size)+1){
		l->size++;
		l->arr[l->size-1]=n;
	}
	else{
		for (i=l->size-1;i>=pos-1;i--){
			l->arr[i+1]=l->arr[i];
		}
		++l->size;
		l->arr[pos-1]=n;
	}

}



void traverse(list *l){
	int i;
	if(isEmpty(l)){
		printf("list is empty");
		return;
	}
	for (i=0;i<=l->size-1;i++){
		printf("\na[%d]=%d",i+1,l->arr[i]);
	}
}

void modify(list *l){
	int i,pos,item;
	if(isEmpty(l)){
		printf("list is empty");
		return;
	}
	printf("Enter the position to modify: ");
	scanf("%d",&pos);
	if(pos<1 || pos>l->size){
		printf("Invalid Index");
		return;
	}
	else{
		printf("Enter the new element: ");
		scanf("%d",&item);
	}
	l->arr[pos-1]=item;
}


void Remove(list *l){
	int i,pos,item;
	if(isEmpty(l)){
		printf("list is empty");
		return;
	}
	printf("Enter the position to remove: ");
	scanf("%d",&pos);
	if(pos<1 || pos>l->size){
		printf("Invalid Index");
		return;
	}
	if (pos==l->size){
		printf("%d is removed",l->arr[l->size-1]);
		l->size--;
	}
	else{
		printf("%d is removed",l->arr[pos-1]);
		for(i=pos-1;i<=l->size-1;i++){
			l->arr[i]=l->arr[i+1];
		}
		l->size--;
	}
}

void search(list *l){
	int item,i;
	printf("Enter the item to search: ");
	scanf("%d",&item);
	for(i=0;i<=l->size-1;i++){
		if(l->arr[i]==item){
			printf("%d found at %d index",item,i+1);
			return;
		}

	}
	printf("%d not found",item);
}

//void sum(list *l){
//	int sum=0,i;
//	for (i=0;i<=l->size-1;i++){
//		sum+=l->arr[i];
//	}
//	printf("Sum of elements in list is %d",sum);
//}
