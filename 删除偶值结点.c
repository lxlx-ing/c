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

void delete_even(linkList L) {
    LNode *p = L; 
    while (p->next) { 
        if (p->next->data % 2 == 0) { 
            LNode *q = p->next; 
            p->next = q->next; 
            free(q); 
        } else { 
            p = p->next;
        }
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
        delete_even(L);
        PrintList (L);
        return 0; 

}
