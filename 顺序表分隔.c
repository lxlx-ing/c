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
Status sort(SqList *L)
{
    int i,j,t;
    for(i=0;i<L->length;i++){
        for(j=0;j<L->length-i-1;j++){
            if(L->elem[j]>=L->elem[j+1]){
                t=L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=t;
            }
        }
    }
}
void PrintList_Sq(SqList L)
{
    for(int i=0;i<L.length;i++){
        printf("%d ",L.elem[i]);
    }
}
int main()
{
    SqList SL;
    int n,k;
    ElemType e;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL,n);
    sort(&SL);
    PrintList_Sq(SL);
    return 0; 
}