#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
} Queue;
void initialise(Queue *q, int size)
{
    q->size = size;
    q->arr = (int *)malloc(q->size * (sizeof(int)));
    q->front = -1;
    q->rear = -1;
}
void enqueue(Queue *q, int data)
{
    if ((q->rear + 1) % q->size == q->front) // isFull() condition
    {
        printf("Queue overflow...\nExiting");
        exit(0);
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
}
int dequeue(Queue *q)
{
    int a = -1;
    if (q->front == q->rear) // isEmpty() condition
    {
        printf("The queue is empty...\nExiting");
        exit(1);
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
        return a;
    }
}
void display(Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
        printf("%d\n", q->arr[i]);
}
int main()
{
    Queue q;
    initialise(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    free(q.arr);

    return 0;
}