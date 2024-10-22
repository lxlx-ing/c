
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
    L->elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}
void InputList_Sq(SqList *L, int n)
{
    L->length=n;
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&L->elem[i]);
    }
}
void ListInsert_Sq(SqList *L,int i, ElemType e)
{
    int j;
    i=i-1;
    for(j=L->length;j>i;j--){
        L->elem[j]=L->elem[j-1];
    }
    L->elem[i]=e;
    L->length++;
}
void PrintList_Sq(SqList L)
{
    int i;
    for(i=0;i<L.length;i++){
        printf("%d ",L.elem[i]);
    }
}
int main()
{
    SqList SL;
    int n,i;
    ElemType e;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL,n);
    scanf("%d %d",&i,&e);
    ListInsert_Sq(&SL,i,e);
    PrintList_Sq(SL);
    return 0; 
}

