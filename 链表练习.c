#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode * next;

}Node,*Linklist;

void InitList(Linklist *L){
    *L=(Linklist)malloc(sizeof(Node));
    (*L)->next=NULL;
}

void input(Linklist L,int n){
    Linklist s,p=L;
    int i;
    for(i=0;i<n;i++){
        s=(Linklist)malloc(sizeof(Node));
        scanf("%d",&s->data);
        s->next=NULL;
        p->next=s;
        p=s;
    }

    
}

void print(Linklist L){
    int i;
    Linklist p=L->next;
    if(!L){
        printf("链表不存在");
    }
    else if(p!=NULL){
        while(p!=NULL){
            printf("%d",p->data);
            p=p->next;
        }
    }
    else{
        printf("链表为空");
    }
}

int main(){
    Linklist L;
    int n;
    InitList(&L);
    scanf("%d",&n);
    input(L,n);
    print(L);
    return 0;
}