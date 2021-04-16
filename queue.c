#include<stdio.h>
#include<stdlib.h>


typedef struct Nod
{
    int data;
    struct Nod *next;
} Nod;

typedef struct Queue
{
    Nod *front;
    Nod *rear;
} Queue;

Nod* init_nod()
{
    Nod *A = (Nod*)malloc(sizeof(Nod));
    A->next = (Nod*)malloc(sizeof(Nod));
    A->next = NULL;
    A->data = -1;
    return A;
}
Queue* init_queue()
{
    Queue *K = (Queue*)malloc(sizeof(Queue));
    K->front = init_nod();
    K->rear = init_nod();
    K->rear = K->front;
}

void append(Queue **K, int d)
{
    Nod *new = init_nod();
    new->data = d;
    (*K)->front->next = new;
    (*K)->front = new;
}
int peek(Queue *K)
{
    return K->rear->data;
}

void pop(Queue **K)
{
    if ((*K)->rear->next != NULL)
    {
        Nod *R = init_nod();
        R = (*K)->rear;
        (*K)->rear = (*K)->rear->next;
        free(R);
    }
    
}

void printqueue(Queue *K)
{
    Nod *P = init_nod();
    P = K->rear;
    while(P->next != NULL)
    {
        P = P->next;
        printf("%i\n", P->data);
    }
}

int main()
{
    Queue *K = init_queue();
    for(int i = 0; i < 5; i++)
        append(&K, i);
    printqueue(K);
    printf("\n");
    pop(&K);
    pop(&K);
    append(&K, 5);
    printf("\n");
    printqueue(K);
    return 0;

}