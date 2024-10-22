#include <stdio.h>
#include <malloc.h>
int Max(int a[], int n)
{
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max=a[0];
	for(i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}
int main()
{
    int n,max,*base;
    scanf("%d",&n);
    base=(int *) malloc(n*sizeof(int));//申请长度为n的数组空间
    max=Max(base, n);//调用函数求最大值
    printf("%d",max);
    free(base);
    return 0;
}

