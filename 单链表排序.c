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
 
void sort(linkList *L){
    LNode*p=(*L)->next;
    LNode*q=p->next;
    p->next=NULL;
    while(q){
        LNode*r=q->next;
        p=*L;
        while(p->next&&q->data>p->next->data){
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
        q=r;
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
        linkList L1;
        int n;
        scanf("%d",&n);
        CreateList_R(&L1, n);
        sort(&L1);
        PrintList (L1);
        return 0; 

}
 