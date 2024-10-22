#include <stdlib.h>
#include <stdio.h>
typedef char ElemType;
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
    for (int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));
        if (s == NULL) {
            exit(EXIT_FAILURE);
        }
        char c;
        do {
            c = getchar();
        } while (c == '\n' || c == '\r');
        s->data = c; 
        s->next = NULL;
        t->next = s;
        t = s;
    }
}

LNode* find_the_starting_node_of_the_common_suffix(linkList L1,linkList L2){
    LNode *p1=L1->next;
    LNode*p2=L2->next;
    int m=0,n=0;
    while(p1){
        m++;
        p1=p1->next;
    } 
    p1=L1->next;
    while(p2){
        n++;
        p2=p2->next;
    }
    p2=L2->next;
    printf("%d %d ",m,n);
    int k;
    if(m>n){
        k=m-n;
        while(k){
            p1=p1->next;
            k--;
        }
        while(p1->data!=p2->data){
            return p1;
            p1=p1->next;p2=p2->next;
        }
    }
    return NULL;
    
}

int main()

{
        linkList L1,L2;
        int n1,n2;
        //输入两个单词
        scanf("%d",&n1);
        CreateList_R(&L1, n1);
        scanf("%d",&n2);
        CreateList_R(&L2, n2);
        LNode*s=find_the_starting_node_of_the_common_suffix(L1,L2);
        if(s!=NULL)printf("%c",s->data);
        else printf("%d",-1);
        return 0; 

}
