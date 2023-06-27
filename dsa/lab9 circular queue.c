#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5

struct queue
{
    int item[max];
    int front;
    int rear;
};

typedef struct queue cq;
void enqueue(cq *);
void dequeue(cq *);
void display(cq );

int main()
{
    cq q;
    q.front = max - 1;
    q.rear = max - 1;
    int option;

    do
    {
        system("cls");
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display Elements\n 4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue(&q);
            
            break;
        case 2:
            dequeue(&q);
            
            break;
        case 3:
            display(q);
            
            break;
        case 4:
            printf("Exiting...\n");
            break;
        }
        getch();
    } while (option != 4);
    return 0;
}

void enqueue(cq *q)
{
    int value;
    if ((q->rear + 1) % max == q->front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        q->rear = (q->rear + 1) % max;
        q->item[q->rear] = value;
        
    }
}

void dequeue(cq *q)
{
    if (q->front == q->rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % max;
        printf("The deleted element is %d\n", q->item[q->front]);
    }
}

void display(cq q)
{
    if (q.front == q.rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The elements of the queue are: ");
        int i = (q.front + 1) % max;
        while (i != (q.rear + 1) % max)
        {
            printf("%3d", q.item[i]);
            i = (i + 1) % max;
        }
        printf("\n");
    }
}
