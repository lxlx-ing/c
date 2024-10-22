#include <stdlib.h>
#include <stdio.h>
#define LIST_INIT_SIZE    20
#define LISTINCREMENT   10
#define OK                1
#define OVERFLOW        -2
typedef int ElemType;
typedef int Status;
typedef struct {
        ElemType *elem;
        int length;
        int listsize;
}SqList;
Status InitList_Sq(SqList *L)
{
    L->elem=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L->listsize=LIST_INIT_SIZE;
    L->length=0;
}
void InputList_Sq(SqList *L, int n)
{
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&L->elem[i]);
        L->length++;
    }
}

void insert_x(SqList *L,int n,int x){
    int i;
    if(L->length==n){
        L->elem[n]=x;
        L->length++;
    }
    else{
        for(i=L->length;i>n;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[n]=x;
    L->length++;
    }
    
}

void insert(SqList *L,int x){
    int i;
    for(i=0;i<L->length;i++){
        if(x<=L->elem[i]){
            insert_x(L,i,x);
            return;
        }
        
    }
    insert_x(L,L->length,x);
        
}


void PrintList_Sq(SqList L)
{
    for(int i=0;i<L.length;i++){
        printf("%d ",L.elem[i]);
    }
}
int main()
{
        SqList L;
        int len,x;
        scanf("%d",&len);
        InitList_Sq(&L);
        InputList_Sq(&L,len);
        scanf("%d",&x);
        insert(&L,x);
        PrintList_Sq(L);
        return 0; 
}