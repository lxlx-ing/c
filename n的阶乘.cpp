#include <stdio.h>
long fac(int x);
int main()
{
	int n;
	scanf("%d",&n); 
	long k;
	k=fac(n); //µÝ¹éµ÷ÓÃº¯Êý
	printf("%d",k);
	return 0;
}

long fac(int x){
	if(x==1){
		return 1;
	}
	else{
		return x*fac(x-1) ;
	}
	
}

