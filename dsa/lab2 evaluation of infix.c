/*Evaluation of infix expression*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

int isoperand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')
        return 1;
    else
        return 0;
}
int operate(int opnd1, int opnd2, char ch)
{
    switch (ch)
    {
    case '+':
        return (opnd1 + opnd2);
        break;
    case '-':
        return (opnd1 - opnd2);
        break;
    case '*':
        return (opnd1 * opnd2);
        break;
    case '/':
        return (opnd1 / opnd2);
        break;
    case '$':
        return (pow(opnd1, opnd2));
        break;
    }
}
int prcd(char ch)
{
    if (ch == '$')
        return (3);
    else if (ch == '*' || ch == '/')
        return (2);
    else if (ch == '+' || ch == '-')
        return (1);
    else
        return (0);
}

int evaluate_infix(char infix[])
{
    int i, optos = -1, opndtos = -1;
    int n, opndstk[10], opnd1, opnd2;
    char opstk[10], op;
    i = 0;
    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            printf("Enter value of %c = ", infix[i]);
            scanf("%d", &n);
            opndstk[++opndtos] = n;
        }
        else if (isoperator(infix[i]))
        {
            if (optos == -1)
                opstk[++optos] = infix[i];
            else
            {
                if (prcd(infix[i]) > prcd(opstk[optos]))
                    opstk[++optos] = infix[i];
                else
                {
                    while (prcd(opstk[optos]) >= prcd(infix[i]))
                    {
                        opnd2 = opndstk[opndtos--];
                        opnd1 = opndstk[opndtos--];
                        op = opstk[optos--];
                        n = operate(opnd1, opnd2, op);
                        opndstk[++opndtos] = n;
                    }
                    opstk[++optos] = infix[i];
                }
            }
        }
        else if (infix[i] == '(')
            opstk[++optos] = infix[i];
        else if (infix[i] == ')')
        {
            while (opstk[optos] != '(')
            {
                opnd2 = opndstk[opndtos--];
                opnd1 = opndstk[opndtos--];
                op = opstk[optos--];
                n = operate(opnd1, opnd2, op);
                opndstk[++opndtos] = n;
            }
            optos--;
        }

        i++;
    }
    while (optos != -1)
    {
        opnd2 = opndstk[opndtos--];
        opnd1 = opndstk[opndtos--];
        op = opstk[optos--];
        n = operate(opnd1, opnd2, op);
        opndstk[++opndtos] = n;
    }
    return (opndstk[opndtos]);
}


int main()
{
    char infix[30];
    int result;
    printf("Enter infix expression: ");
    gets(infix);
    result = evaluate_infix(infix);
    printf("The required result is %d\n", result);
    getch();
    return 0;
}

