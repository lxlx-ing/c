#include <stdlib.h>

#include <stdio.h>

#define OK  1

#define TRUE  1

#define FALSE  0

#define ERROR  0

#define OVERFLOW 0

#define STACK_INIT_SIZE  100

#define STACKINCREMENT  10

typedef int Status;

typedef int SElemType;

typedef struct{
        SElemType *base;
        SElemType *top;
        int stacksize;
}SqStack;

Status Init_Stack(SqStack *S)
{
    S->base=(SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push_Stack(SqStack *S, SElemType e)
{
    *(S->top++)=e;
    return OK;
}

Status Pop_Stack(SqStack *S, SElemType *e)
{
    if(S->top==S->base){
        return ERROR;
    };   
    *e=*(--S->top);
    return OK;
}

int main()
{

        SqStack S;
        Init_Stack(&S);
        int n,i,e;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&e);
           if(e!=-1){
                Push_Stack(&S,e);
           } 
           else{
            int x,res;
            res=Pop_Stack(&S,&x);
            if(res==0) printf("%s","出栈失败");
            else printf("%d\n",x);
           }
        }
        return 0; 

}