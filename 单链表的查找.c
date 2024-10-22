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

int getelem (linkList L,int x)

{
    LNode *p=L->next;
    int n=1;
    while(p){
        if(p->data==x){
            printf("%d",n);
            return 1;
        }
        n++;
        p=p->next;
    }
    return 0;
}

int main()

{

        linkList L;

        int n,x;
        scanf("%d",&n);

        CreateList_H(&L, n);

        scanf("%d",&x);
       
        int result = getelem(L, x); // 调用查找函数
        if (result == 0) { // 判断结果
            printf("-1\n"); // 元素未找到，输出 -1
        }
        
        return 0; 

}