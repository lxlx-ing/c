#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 20
typedef char ElemType;
typedef struct 
{
    ElemType *top;
    ElemType *base;
    int size;
}SqStack;

void init(SqStack *S){
    S->base=(ElemType*)malloc(sizeof(ElemType)*INITSIZE);
     if (S->base == NULL) {
        return;
    }
    S->top=S->base;
    S->size=INITSIZE;
}

void push(SqStack *S,ElemType e){
    if (S->top - S->base >= S->size) {
        S->base = realloc(S->base, sizeof(ElemType) * (S->size + INITSIZE));
        if (S->base == NULL) {
            return;
        }
        S->top = S->base + S->size;
        S->size += INITSIZE;
    }
    *(S->top++)=e;
}

void pop(SqStack *S){
    --S->top;
}

void top(SqStack *S,ElemType *e){
    *e=*(S->top-1);
}

int match(SqStack *S,char a[]){
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i]=='{'||a[i]=='['||a[i]=='('){
            push(S,a[i]);
        }
        else{
            if(S->top==S->base){
                return 0;
            }
            ElemType e;
            top(S,&e);
            if((a[i]=='}'&&e=='{')||(a[i]==']'&&e=='[')||
            (a[i]==')'&&e=='(')){
                pop(S);
            }
            else return 0;
        }
    }
    return S->top == S->base ? 1 : 0;  
}

int main(){
    SqStack S;
    init(&S);
    char a[20]="";
    scanf("%s",a);
    printf("%d",match(&S,a));
    return 0;
}
