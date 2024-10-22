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

void fenjie(linkList L,linkList* La,linkList *Lb){
    *La=(linkList)malloc(sizeof(LNode));
    (*La)->next=NULL;
    *Lb=(linkList)malloc(sizeof(LNode));
    (*Lb)->next=NULL;
    LNode*p=L->next;
    LNode*ta=(*La);
    LNode*tb=(*Lb);
    while (p)
    {
        LNode *next=p->next;
        if(p->data<0){
            
            ta->next=p;
            p->next=NULL;
            ta=p;
        }
        else if(p->data>0){
            
            tb->next=p;
            p->next=NULL;
            tb=p;
        }
        p=next;
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
        linkList La,Lb,L;
        int n;
        scanf("%d",&n);
        CreateList_R(&L, n);
        fenjie(L,&La,&Lb);
        PrintList(La);
        printf("\n");
        PrintList(Lb);
        return 0; 

}
