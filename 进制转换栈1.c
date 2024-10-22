#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 20
typedef int ElemType;
typedef struct 
{
    ElemType *top;
    ElemType *base;
    int size;
}SqStack;

void init(SqStack *S){
    S->base=(ElemType*)malloc(sizeof(ElemType)*INITSIZE);
     if (S->base == NULL) {
        // 处理内存分配失败
        return;
    }
    S->top=S->base;
    S->size=INITSIZE;
}

void push(SqStack *S,ElemType e){
    if (S->top - S->base >= S->size) {
        S->base = realloc(S->base, sizeof(ElemType) * (S->size + INITSIZE));
        if (S->base == NULL) {
            // 处理内存扩展失败
            return;
        }
        S->top = S->base + S->size;
        S->size += INITSIZE;
    }
    *(S->top++)=e;
}

void pop(SqStack *S,ElemType *e){
    *e=*(--S->top);
}


void conversion_B(int n){
    SqStack S;
    init(&S);
    ElemType e;
    if(n==0){
        printf("%d",0);
    }
    while (n)
    {
        push(&S,n%2);
        n=n/2;
    }
    while (S.top!=S.base)
    {
        pop(&S,&e);
        printf("%d",e);
    }
    printf("\n");
}


void conversion_H(int n){
    SqStack S;
    init(&S);
    ElemType e;
    if(n==0){
        printf("%d",0);
    }
    while (n)
    {
        push(&S,n%16);
        n=n/16;
    }
    while(S.top!=S.base)
    {
        pop(&S,&e);
        if(e>=1&&e<=9){
            printf("%d",e);
        }
        else if(e==10){
            printf("%c",'A');
        }
        else if(e==11){
            printf("%c",'B');
        }
        else if(e==12){
            printf("%c",'C');
        }
        else if(e==13){
            printf("%c",'D');
        }
        else if(e==14){
            printf("%c",'E');
        }
        else if(e==15){
            printf("%c",'F');
        }
    }

    printf("\n");
}

void conversion_O(int n){
    SqStack S;
    init(&S);
    ElemType e;
    if(n==0){
        printf("%d",0);
    }
    while (n)
    {
        push(&S,n%8);
        n=n/8;
    }
    while (S.top!=S.base)
    {
        pop(&S,&e);
        printf("%d",e);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    conversion_B(n);
    conversion_O(n);
    conversion_H(n);
    return 0;
}
