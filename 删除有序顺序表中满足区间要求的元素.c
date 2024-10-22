#include <stdlib.h>
#include <stdio.h>
#define LIST_INIT_SIZE    20
#define LISTINCREMENT   10
#define OK                1
#define ERROR        -1
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
Status  DeleteListe_Sq(SqList *L,int min ,int max)
{
    int i,k=0,flag=-1;
    for(i=0;i<L->length;i++){
        if((L->elem[i]>=min)&&(L->elem[i]<=max)){
            flag=0;
        }
    }
    if(flag==-1){
        return ERROR;
    }
    for(i=0;i<L->length;i++){
        if(L->elem[i]<min||L->elem[i]>max){
            L->elem[k++]=L->elem[i];
        }
    }
    L->length=k;
    return OK;
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
    int n,min,max;
    scanf("%d",&n);
    InitList_Sq(&SL);
    InputList_Sq(&SL,n);
    scanf("%d %d",&min,&max);
    if(DeleteListe_Sq(&SL,min,max)==-1){
        printf("%d",DeleteListe_Sq(&SL,min,max));
    }
    else PrintList_Sq(SL);
    return 0; 
}