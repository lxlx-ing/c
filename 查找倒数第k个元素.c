#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct LNode

{
        ElemType data;

        struct LNode *next;

} LNode ,*linkList;


void CreateList_H(linkList *L, int n)
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

int getelem (linkList L,int k)

{
    LNode*p=L->next;LNode*q=L->next;
    for(int i=0;i<k;i++){
        p=p->next;
    }
    while (p)
    {
        p=p->next;
        q=q->next;
    }
    if(q){
        printf("%d",q->data);
        return 1;
    }
    return 0;
}

int main()

{

        linkList L;

        int n,k;
        scanf("%d",&n);

        CreateList_H(&L, n);

        scanf("%d",&k);
       
        int result = getelem(L, k); 
        if (result == 0) { 
            printf("-1\n"); 
        }
        return 0; 

}