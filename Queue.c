#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size;
    int front;
    int rear;
    int* arr;
}Queue;
int isfull(Queue* q){
    if(q->rear == q->size - 1)
        return 1;
    return 0;
}
void initialise(Queue* q, int size){
    q->size = size;
    q->arr = (int*) malloc(q->size *(sizeof(int)));
    q->front = -1;
    q->rear = -1;
}
void enqueue(Queue* q, int data){
    if(isfull(q)){
        printf("Queue overflow...\nExiting");
        exit(0);
    }
    q->arr[++q->rear] = data;

}
int dequeue(Queue* q){
    if(q->front == q->rear) //is empty() condition
        return -1;
    return q->arr[++q->front];
}
void display(Queue* q){
    for(int i=q->front + 1; i<=q->rear; i++)
        printf("%d\n",q->arr[i]);
}
int main(){
    Queue q;
    initialise(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);
    printf("%d\n",dequeue(&q));
    display(&q);

    free(q.arr);

    return 0;
}