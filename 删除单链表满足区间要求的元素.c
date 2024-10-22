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

int  delete(linkList L,int min,int max){
    if((max<min)||(L==NULL)){
        printf("%d",-1);
        return -1;
    }
    int flag=0;
    LNode *p=L;
    while (p->next)
    {
        LNode*s=p->next;
        if(s->data>=min&&s->data<=max){
            p->next=s->next;
            flag=1;
        }
        else p=p->next;
    }
    if(flag==0){
        printf("%d",-1);
        return -1;
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
        int min,max;
        scanf("%d %d",&min,&max);
        int res=delete(L,min,max);
        if(res!=-1)PrintList(L);
        return 0; 

}
