#include <stdio.h>
void swap(int *p1,int *p2);
int main()
{
    int a, b;
    scanf("%d %d",&a,&b); 
    swap(&a,&b);// ���ú���ʵ����������
    printf("%d %d",a,b);
    return 0;
}
void swap(int *p1, int *p2)// �������壬ָ�������Ϊ�β�
{
	int t;
	t=*p1;
	*p1=*p2;
	*p2=t;
}


