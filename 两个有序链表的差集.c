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

void chaji(linkList La,linkList Lb){
    LNode*p=La->next;
    int cnt=0,f;
    while(p){
        LNode*q=Lb->next;
        int flag=0;
        while(q){
            if(p->data==q->data){
                flag=1;    
            }
            
            q=q->next;
        }
        f=flag;
        if(f==0){
                printf("%d ",p->data);
                cnt++;
            }
        p=p->next;
    }
   
    if(f==1){
        printf("%d",0);
    }
    else{
        printf("\n%d",cnt);
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
        linkList La,Lb;
        int n1,n2;
        scanf("%d",&n1);
        CreateList_R(&La, n1);
        scanf("%d",&n2);
        CreateList_R(&Lb,n2);
        chaji(La,Lb);
        return 0; 

}
