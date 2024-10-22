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
typedef struct LNode
{
 Book data; //结点的数据域
 struct LNode *next; //结点的指针域
} LNode,*LinkList; //LinkList 为指向结构体 LNode 的指针类型

void init(LinkList* L){
    (*L)=(LNode*)malloc(sizeof(LNode));
    (*L)->next=NULL;
    
}

void input(LinkList L){
    int k=0;
    while(1){
        char no[20];char name[50];float price;
        LNode *s;
        scanf("%s %s %f",no,name,&price);
        if(strcmp(no,"0")==0&&strcmp(name,"0")==0&&price==0.0){
            break;
        }
        s=(LNode*)malloc(sizeof(LNode));
        strcpy(s->data.no,no);
        strcpy(s->data.name,name);
        s->data.price=price;
        s->next=NULL;
        L->next=s;
        L=s;
        k++;
    }
    printf("%d\n",k);
}

void print(LinkList L){
    LNode*s=L->next;
    while(s){
        printf("%s %s %.2f\n",s->data.no,s->data.name,s->data.price);
        s=s->next;
    }
}

int main(){
    LinkList L;
    init(&L);
    input(L);
    print(L);
    return 0;
}