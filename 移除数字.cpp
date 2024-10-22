#include <stdio.h>
int removeElement(int *nums, int numsSize, int val) //将移除元素后数组的长度作为函数值。
{ 
	int i,m=0;
	for(i=0;i<numsSize;i++){
		if(nums[i]!=val){
			nums[m++]=nums[i];
		}
	}
	return m;
}
int main()
{
	int nums[20];
	int n,i;
	int val;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	scanf("%d",&val);
	int a;
	a = removeElement(nums, n, val);
	printf("%d\n",a);
	for(i=0;i<a;i++){	
			printf("%d ",nums[i]);
	}
return 0;
}


