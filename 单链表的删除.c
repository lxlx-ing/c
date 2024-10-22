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

int delete(linkList L,int i){
    
    int j=0;
    LNode *p=L;
    while(p->next&&(j<i-1)){
        j++;
        p=p->next;
    }
    if((j>i-1)||!(p->next)){
        return -1;
    }
    else{
        LNode* q=p->next;
        p->next=q->next;
        free(q);
    }
   
    return 0;
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
        scanf("%d",&x);
        int res=delete(L,x);
        if(res==-1){
            printf("%d",-1);
        }
        else{
            PrintList (L);
        }
        
        return 0; 

}
