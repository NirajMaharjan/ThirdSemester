//program to evluate postfix and prefix

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int isOperator(char ch){
	if (ch=='+' ||ch=='-' || ch=='*' ||ch=='/' || ch=='$'){
		return 1;
	}
	else{
		return 0;
	}
}

int isOperand(char ch){
	if (ch>='A'&&ch<='Z' || ch>='a'&&ch<='z'){
		return 1;
	}
	else{
		return 0;
	}
	
}
int evaluate(char *e){
	int i,tos=-1;
	int n,opndstk[10],opnd1,opnd2;
	
	while(*e!='\0'){

		if (isOperand(*e)){
			printf("Enter the value of %c",*e);
			scanf("%d",&n);
			opndstk[++tos]=n;
		}
		else if(isOperator(*e)){
			opnd2=opndstk[tos--];
			opnd1=opndstk[tos--];
			
			switch(*e){
				
				case '+':
					opndstk[++tos]=opnd1+opnd2;
					break;
				case '-':
					opndstk[++tos]=opnd1-opnd2;
					break;
				case '*':
					opndstk[++tos]=opnd1*opnd2;
					break;
				case '/':
					opndstk[++tos]=opnd1/opnd2;
					break;
				case '$':
					opndstk[++tos]=pow(opnd1,opnd2);
					break;
					
			}
		}
		e++;
		
	}
	return (opndstk[tos]);
}


int main(){
	char exp[50];
	int result;
	printf("Enter the postfix expression: ");
	gets(exp);
	result=evaluate(&exp);
	printf("The required result is %d",result);
	
	return 0;
}
