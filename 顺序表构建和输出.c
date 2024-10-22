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
    for (int i = 0; i < L->length; i++)
    {
        scanf("%d",&L->elem[i]);
    }
    
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
    int n;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL, n);
    PrintList_Sq(SL);
    return 0; 
}

