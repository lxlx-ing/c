#include <stdio.h>
#include <stdlib.h>
typedef struct  //定义结构体类型
{
        char title[20]; //图书名称
        char author[15]; //作者
        int pages; //页数
        float price; //价格
}Book;

void input(Book* b){
	scanf("%s %s %d %f",b->title,b->author,&b->pages,&b->price);
}

void output(Book* b){
	printf("Title Author Pages Price\n");
	printf("%s %s %d %.2f",b->title,b->author,b->pages,b->price);
}
int main()
{
        Book *p;
        p=( Book *)malloc(sizeof(Book)); //分配一个结构体变量所用的空间
        input(p); 
        output(p);
		free(p); //释放内存
       return 0;
}


