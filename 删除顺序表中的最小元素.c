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
int  DeleteListe_Sq(SqList *L)
{
    int min=L->elem[0],i,n;
    for (int i = 1; i < L->length; i++)
    {
        if(L->elem[i]<min){
            min=L->elem[i];
        }
    }
    for(i=0;i<L->length;i++){
        if(L->elem[i]==min){
            n=i;
        }
    }
    L->elem[n]=L->elem[L->length-1];
    L->length--;
    return min;
    
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
    int n;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL,n);
    printf("%d\n",DeleteListe_Sq(&SL));
    PrintList_Sq(SL);
    return 0; 
}