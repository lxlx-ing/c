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
    L->elem=(ElemType*)malloc(sizeof(ElemType));
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
Status nizhi(SqList *L)
{
   int i,j,t;
   for(i=0,j=L->length-1;i<=j;i++,j--){
        t=L->elem[i];
        L->elem[i]=L->elem[j];
        L->elem[j]=t;
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
        SqList L;
        int len;
        scanf("%d",&len);
        InitList_Sq(&L);
        InputList_Sq(&L,len);
        nizhi(&L);
        PrintList_Sq(L);
        return 0; 
}