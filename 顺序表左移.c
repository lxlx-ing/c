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

void reserve(SqList *L,int l,int r){
    int i=l,j=r;
    ElemType t;
    while (i<j)
    {
        t=L->elem[i];
        L->elem[i]=L->elem[j];
        L->elem[j]=t;
        i++;j--;
    }
}

void shiftLeft(SqList *L,int n,int k)
{
   reserve(L,0,n-1);
   reserve(L,0,n-k-1);
   reserve(L,n-k,n-1);
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
        int len;
        scanf("%d",&len);
        InitList_Sq(&L);
        InputList_Sq(&L,len);
        int k;
        scanf("%d",&k);
        shiftLeft(&L,len,k);
        PrintList_Sq(L);
        return 0; 
}