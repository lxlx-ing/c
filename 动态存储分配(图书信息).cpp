#include <stdio.h>
#include <stdlib.h>
typedef struct  //����ṹ������
{
        char title[20]; //ͼ������
        char author[15]; //����
        int pages; //ҳ��
        float price; //�۸�
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
        p=( Book *)malloc(sizeof(Book)); //����һ���ṹ��������õĿռ�
        input(p); 
        output(p);
		free(p); //�ͷ��ڴ�
       return 0;
}


