#include <stdio.h>
void swap(int *p1,int *p2);
int main()
{
    int a, b;
    scanf("%d %d",&a,&b); 
    swap(&a,&b);// 调用函数实现两数互换
    printf("%d %d",a,b);
    return 0;
}
void swap(int *p1, int *p2)// 函数定义，指针变量作为形参
{
	int t;
	t=*p1;
	*p1=*p2;
	*p2=t;
}


