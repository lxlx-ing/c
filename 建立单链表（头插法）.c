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
    int i;
    LNode* s;
    for(i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&s->data);
        s->next=(*L)->next;
        (*L)->next=s;
    }
}

void PrintList (linkList L)

{
    LNode* s=L->next;
    while(s){
        printf("%d ",s->data);
        s=s->next;
    }
}

int main()

{

        linkList L;

        int n;
        scanf("%d",&n);

        CreateList_H(&L, n);

        PrintList (L);

        return 0; 

}