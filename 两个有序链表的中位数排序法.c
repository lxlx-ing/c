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
 
void sesrch_mid(linkList L1,linkList L2,linkList *L,int n){
    LNode * p=L1->next;
    LNode *q=L2->next;
    LNode *c;
    *L=c=L1;
    int cnt=0;
    while (p&&q)
    {
        if(p->data<=q->data){
            cnt++;
            c->next=p;
            c=p;
            p=p->next;
        }
        else{
            cnt++;
            c->next=q;
            c=q;
            q=q->next;
        }
        if(cnt==n){
        printf("%d",c->data);
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
        int n;
        //输入两个等长的有序链表
        scanf("%d",&n);
        CreateList_R(&L1, n);
        CreateList_R(&L2, n);
        search_mid(L1,L2,&L,n);
        //PrintList (L);
        return 0; 

}
