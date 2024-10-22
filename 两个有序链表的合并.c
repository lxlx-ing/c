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
 
void merage(linkList L1,linkList L2,linkList *L){
    LNode * p=L1->next;
    LNode *q=L2->next;
    LNode *c;
    *L=c=L1;
    while (p&&q)
    {
        if(p->data<=q->data){
            c->next=p;
            c=p;
            p=p->next;
        }
        else{
            c->next=q;
            c=q;
            q=q->next;
        }
    }
    c->next=p? p:q;
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
        linkList L1,L2,L;
        int n1,n2;
        scanf("%d",&n1);
        CreateList_R(&L1, n1);
        scanf("%d",&n2);
        CreateList_R(&L2, n2);
        merage(L1,L2,&L);
        PrintList (L);
        return 0; 

}
