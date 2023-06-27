#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




struct student{
	int roll;
	char name[50];
	int marks;
};
typedef struct student Student;
int isPass(Student*);
void display(Student*);
void input(Student*);

int main(){
	Student *s;
	int n,i;
	printf("Enter the number of records: ");
	scanf("%d",&n);	
	s=(Student*)malloc(n*sizeof(Student));
	
	for(i=0;i<n;i++){
		system("cls");
		input((s+i));
	}
	
	for(i=0;i<n;i++){
		display(s+i);
	}
	return 0;
}

void input(Student *s){
	printf("Enter the roll number: ");
	scanf("%d",&s->roll);
	fflush(stdin);
	printf("Enter the name of a student: ");
	gets(s->name);
	printf("Enter the marks in DSA: ");
	scanf("%d",&s->marks);
}

int isPass(Student *s){
	if(s->marks>=40){
		return 1;
	}
	return 0;
}

void display(Student *s){
	if (isPass(s)){
		printf("\n%d. %s \t %d ",s->roll,s->name,s->marks);
	}
}
