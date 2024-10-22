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

void jiaoji(linkList La,linkList Lb){
    LNode*p=La->next;
    int flag=0,cnt=0;
    while(p){
        LNode*q=Lb->next;
        while(q){
            if(p->data==q->data){
                flag=1;
                printf("%d ",p->data);
                cnt++;
            }
            q=q->next;
        }
        p=p->next;
    }
    if(flag==0){
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
        jiaoji(La,Lb);
        return 0; 

}
