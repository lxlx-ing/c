#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

void Create_L(DLinkList *L,int n){
    (*L)=(DLinkList)malloc(sizeof(DNode));
    (*L)->next=*L;(*L)->prior=*L;                             
    int i;
    DNode*t=*L;
    for(i=0;i<n;i++){
        DNode*s=(DNode*)malloc(sizeof(DNode));
        scanf("%d",&s->data);
        s->next=t->next;
        s->prior=t;
        t->next->prior=s;
        t->next=s;
        t=s;
    }
    t->next=*L;
    (*L)->prior=t;
}

int judge_reserve(DLinkList L){
    DNode *p=L->next;
    DNode*t=L->prior;
    while (p!=t)
    {
        if(p->data!=t->data){
            return -1;
        }
        p=p->next;t=t->prior;
    }
    return 1;
}

void print(DLinkList L){
    DNode *s=L->next;
    while (s!=L){
        printf("%d ",s->data);
        s=s->next;
    }
    
}

int main(){
    DLinkList L;
    int n;
    scanf("%d",&n);
    Create_L(&L,n);
    print(L);
    int res=judge_reserve(L);
    printf("\n%d",res);
    return 0;
}
