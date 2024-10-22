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
 
void merge(linkList La,linkList Lb){
    LNode *q=Lb->next;
    LNode *pa = La; 
    while (pa->next) {
        pa = pa->next; 
    }
    while (q)
    {
        LNode*s=La->next;
        int flag=0;
        while(s)
        {
            if(q->data==s->data){
                flag=1;
                break;
            }
            s=s->next;
        }
        
        if(flag==0){
            pa->next=q;
            pa=pa->next;   
        }
        LNode *t=q;
        q=q->next;
        t->next=NULL;
    }
    pa->next=NULL;
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
        CreateList_R(&Lb, n2);
        merge(La,Lb);
        PrintList (La);
        return 0; 

}
