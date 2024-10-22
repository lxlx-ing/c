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
Status DeleteListe_Sq(SqList *L, int n)
{
    int i;
    n=n-1;
    for(i=n;i<L->length-1;i++){
        L->elem[i]=L->elem[i+1];
    }
    L->length--;
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
    int n,i;
    ElemType e;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL,n);
    scanf("%d",&i);
    DeleteListe_Sq(&SL, i);
    if(i<=0||i>n){
        printf("%d",-1);
    }
    else{
        PrintList_Sq(SL);
    }
    return 0; 
}