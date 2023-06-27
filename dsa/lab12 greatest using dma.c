#include <stdio.h>



int main(){
	int n,i,greatest=0;
	int *arr;
	printf("Enter the number of data: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the data:\n");
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	
	for(i=0;i<n;i++){
		if(*(arr+i)>greatest)
			greatest=*(arr+i);
	}
	printf("The greatest is %d",greatest);
	
	return 0;
}
