#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10000 //图书表可能达到的最大长度
typedef struct //图书信息定义
{
 char no[20]; //图书 ISBN
 char name [50]; //图书名字
 float price; //图书价格
}Book;

typedef struct
{
Book *elem; //存储空间的基地址
int length; //图书表中当前图书个数
}SqList; //图书表的顺序存储结构类型为 SqLis

void init(SqList *L){
    L->elem=(Book*)malloc(sizeof(Book)*MAXSIZE);
    L->length=0;
} 

void input(SqList *L){
    int k=0;
    while(1){
        
        char no[20];char name[50];float price;
        scanf("%s %s %f",no,name,&price);
        if(strcmp(no,"0")==0&&strcmp(name,"0")==0&&price==0.0){
            break;
        }
        strcpy(L->elem[k].no,no);
        strcpy(L->elem[k].name,name);
        L->elem[k].price=price;
        L->length++;
        k++;
    }
}

void print(SqList L){
    int i;
    //printf("%d\n",L.length);
    for(i=0;i<L.length;i++){
        printf("%s %s %.2f\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
    }
}

void price_modify(SqList *L){
    float sum;
    int i;
    for(i=0;i<L->length;i++){
        sum+=L->elem[i].price;
    }
    float avg=sum/L->length*1.0;
    printf("%.2f\n",avg);
    for(i=0;i<L->length;i++){
        if(L->elem[i].price>=avg){
            L->elem[i].price+=L->elem[i].price*0.1;
        }
        else{
            L->elem[i].price+=L->elem[i].price*0.2;
        }
    }
}

int main(){
    SqList L;
    init(&L);
    input(&L);
    price_modify(&L);
    print(L);
    return 0;
}