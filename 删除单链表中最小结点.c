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

void delete_min(linkList L){
    int i,min=L->next->data;
    LNode *s=L->next;
    while (s)
    {
        if(s->data<min){
            min=s->data;
        }
        s=s->next;
    }
    LNode *p=L;
    while(p->next){
        if(p->next->data==min){
            p->next=p->next->next;
        }
        p=p->next;
    }
    
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
        int n,x;
        scanf("%d",&n);
        CreateList_R(&L, n);
        delete_min(L);
        PrintList (L);
        return 0; 

}
