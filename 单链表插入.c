#include <stdlib.h>

#include <stdio.h>

typedef int ElemType;

typedef int Status;

typedef struct LNode

{

        ElemType data;

        struct LNode *next;

} LNode ,*linkList;

void CreateList_R(linkList *L, int n)

{
    *L=(linkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
    LNode* t;
    t=(*L);
    int i;
    LNode* s;
    for(i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&s->data);
        s->next=NULL;
        t->next=s;
        t=s;
    }
}

void insert(linkList L,int i,int x){
    int j=0;
    LNode *p=L;
    while(p&&(j<i-1)){
        j++;
        p=p->next;
    }
    LNode* s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}

void PrintList (linkList L)

{
    linkList s=L->next;
    while(s){
        printf("%d ",s->data);
        s=s->next;
    }
}

int main()

{
        linkList L;
        int n,i,x;
        scanf("%d",&n);
        CreateList_R(&L, n);
        scanf("%d %d",&i,&x);
        insert(L,i,x);
        PrintList (L);
        return 0; 

}