#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;
void initialise(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(Queue* q, int data){
    Node* nw = (Node*)malloc(sizeof(Node));
    nw->data = data;
    if(nw == NULL){
        printf("Queue Overflow\nExitting...");
        exit(0);
    }
    else{
        if(q->front == NULL){
            q->front = nw;
            q->rear = nw;
        }
        q->rear->next = nw;
        q->rear = nw;
    }
}
void dequeue(Queue* q){
    if(q->front == NULL)
    {
        printf("The queue is empty\nExitting...");
        exit(1);
    }
    Node* ptr = q->front;
    q->front = q->front->next;
    free(ptr);
}
void display(Queue* q){
    Node* ptr = q->front;
    while(ptr){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    Queue q;
    initialise(&q);
    enqueue(&q, 78);
    enqueue(&q, 98);
    enqueue(&q, 8);
    enqueue(&q, 76);
    enqueue(&q, 54);
    enqueue(&q, 34);
    dequeue(&q);

    display(&q);


    return 0;
}