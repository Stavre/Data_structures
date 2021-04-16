#include <stdio.h>
#include <stdlib.h>

typedef struct Nod 
{
    int data;
    struct Nod  *next;
} Nod;

Nod *init()
{
    Nod *A = (Nod*)malloc(sizeof(Nod)); //allocate memory
    A->next = (Nod*)malloc(sizeof(Nod));
    A->next = NULL;
    A = NULL;
    return A;
}

void append(Nod **K, int d)
{
    Nod *new = (Nod*)malloc(sizeof(Nod)); //allocate memory
    new->next = (Nod*)malloc(sizeof(Nod));

    new->data = d;                     //set data

    new->next = *(K);                  //make new nod the head 
    *(K) = new;                       //move the head to point to the new node
}
int peek(Nod *K)
{
    return K->data;
}
int pop(Nod **K)
{
    if ((*K) != NULL)
    {
        Nod *D = (Nod*)malloc(sizeof(Nod)); 
        int i;
        D = (*K);
        (*K) = D->next;
        i = D->data;
        free(D);
        return i;
    }
    return NULL;
    
}
void printList(Nod *K)
{
    
    while(K!= NULL)
    {
        printf("%i\n", K->data);
        K = K->next;
    }
}

void main()
{
    Nod *H;
    
    H = init();
    for (int l = 0; l < 4;l++)
    {
        int i;
        scanf("%i", &i);
        append(&H, i);
    }

    printf("\n");
    printList(H);
    printf("peek: %i", peek(H));
    pop(&H);

    printf("\n");
    printList(H);


}

