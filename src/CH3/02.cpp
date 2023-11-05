#include <stdio.h>
#include <iostream>

enum Status{
    ERR = -1,
    OK = 1,
};
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}node_t;
typedef struct Node *LinkList;


//init
DataType InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L))
        return ERR;
    else
        return OK;
}

//header insert
void createListHeader(LinkList *L, int n)
{
    *L = (LinkList) malloc(sizeof (Node));
    (*L)->next = NULL;
    for(int i = 0; i < n; i++){
        LinkList p = (LinkList) malloc(sizeof(Node));
        p->data = i;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
//tail insert
void createListTail(LinkList *L, int n)
{
    *L = (LinkList ) malloc(sizeof(Node));
    (*L) -> next = NULL;
    LinkList r;
    r = *L;
    for(int i = 0; i < n; i++){
        LinkList p = (LinkList) malloc(sizeof(Node));
        p->data = 2*i;
        r->next = p;
        r = r->next;
    }
    r->next = NULL;
}


int main()
{
    LinkList L;
    InitList(&L);
    createListHeader(&L, 5);
    for(LinkList p = L->next; p!= NULL; p = p->next){
        printf("%d\n", p->data);
    }

    LinkList P;
    InitList(&P);
    createListTail(&P,10);
    for(LinkList p = P->next; p!= NULL; p = p->next){
        printf("%d\n", p->data);
    }

}