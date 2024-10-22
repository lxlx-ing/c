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
Status MergListe_Sq(SqList *La, SqList *Lb, SqList *Lc)
{
    int i=0,j=0,k=0;
    Lc->elem=(ElemType*)malloc(sizeof(ElemType)*(La->length+Lb->length));
    while ((i<La->length)&&(j<Lb->length))
    {
        if(La->elem[i]<Lb->elem[j]){
            Lc->elem[k++]=La->elem[i++];
        }
        else{
            Lc->elem[k++]=Lb->elem[j++];
        }
    }
    while (i<La->length)
    {
        Lc->elem[k++]=La->elem[i++];
    }
    
    while (j<Lb->length)
    {
        Lc->elem[k++]=Lb->elem[j++];
    }
    Lc->length=k;
}
void PrintList_Sq(SqList L)
{
    for(int i=0;i<L.length;i++){
        printf("%d ",L.elem[i]);
    }
}
int main()
{
        SqList La,Lb,Lc;
        int len1,len2;
        scanf("%d",&len1);
        InitList_Sq(&La);
        InputList_Sq(&La,len1);
        scanf("%d",&len2);
        InitList_Sq(&Lb);
        InputList_Sq(&Lb,len2);
        MergListe_Sq (&La, &Lb, &Lc);
        PrintList_Sq(Lc);
        return 0; 
}