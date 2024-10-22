#include <stdlib.h>

#include <stdio.h>

#define OK  1

#define TRUE  1

#define FALSE  0

#define ERROR  0

#define OVERFLOW 0

#define STACK_MAX_SIZE  16

#define STACKINCREMENT  10

typedef int Status;

typedef int SElemType;

typedef struct {

        SElemType data[STACK_MAX_SIZE];

        int top0;

        int top1;

}ShStack;



Status Init_Stack(ShStack *S,int m)
{
    S->top0=-1;S->top1=m;
}

Status IsEmpty_Stack(ShStack *S, int i,int m)
{
    if(i==0){
        if(S->top0==-1){
        return ERROR;
    }
    }
    else if(i==1){
        if(S->top1==m){
        return ERROR;
    }
    }
    return OK;
}

Status IsFull_Stack(ShStack *S)
{
    //printf("t0=%d t1=%d",S->top0,S->top1);
    if(S->top0>=S->top1||S->top1-S->top0==1){
        return ERROR;
    }
    return OK;
}

Status Push_Stack(ShStack *S, int i, SElemType e)
{
    if(i==0){
        S->data[++S->top0]=e;
    }
    if(i==1){
        S->data[--S->top1]=e;
    }
}

Status Pop_Stack(ShStack *S, int I, SElemType *e)
{
    if(I==0){
        *e=S->data[S->top0];
        S->top0--;
    }
    if(I==1){
        *e=S->data[S->top1];
        S->top1++;
    }
}

int main()
{

        ShStack S;
        int i,n;
        scanf("%d",&n);
        int e0,e1,d0,d1;
        scanf("%d %d %d %d",&e0,&e1,&d0,&d1);
        Init_Stack(&S,n);
        for(i=0;i<e0;i++){
            int e;
            scanf("%d",&e);
            Push_Stack(&S, 0 , e);
        }
        for(i=0;i<e1;i++){
            int e;
            scanf("%d",&e);
            Push_Stack(&S, 1 , e);
        }
        //printf("t0=%d t1=%d\n",S.top0,S.top1);
        int res1;
        res1=IsFull_Stack(&S);
        if(res1==0){
            printf("%d\n",1);
        }
        else if(res1==1){
            printf("%d\n",0);
        }
        // for(i=0;i<n;i++){
        //     printf("%d  ",S.data[i]);
        // }//printf("\n");
        for(i=0;i<d0;i++){
            int e;
            Pop_Stack(&S, 0, &e);
            printf("%d ",e);
        }
        
        int res2;
        res2=IsEmpty_Stack(&S,0,n);
        if(res2==0){
            printf("%d",0);
        }
        else printf("%d",1);
        printf("\n");
        for(i=0;i<d1;i++){
            int e;
            Pop_Stack(&S, 1, &e);
            printf("%d ",e);
        }
        int res3;
        res3=IsEmpty_Stack(&S,1,n);
        if(res3==0){
            printf("%d\n",0);
        }
        else printf("%d\n",1);
        //printf("t0=%d t1=%d\n",S.top0,S.top1);
        

        return 0; 

}