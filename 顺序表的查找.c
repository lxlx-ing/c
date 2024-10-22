#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define LISTSIZE 20
typedef int Elemtype;
typedef int Status;
typedef struct 
{
    Elemtype *elem;
    int size;
    int length;
}List;

Status Init(List *List){
    List->elem=(Elemtype*)malloc(sizeof(Elemtype)*LISTSIZE);
    List->length=0;
    List->size=LISTSIZE;
    return ok;
}

void Input(List *L,int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&L->elem[i]);
        L->length++;
    }
}

int Query(List L,Elemtype e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.elem[i]==e){
            return i+1;
        }
    }
    return -1;
}


int main(){
    int n;
    Elemtype e;
    List list;
    scanf("%d",&n);
    Init(&list);
    Input(&list,n);
    scanf("%d",&e);
    printf("%d",Query(list,e));
    return 0;
}