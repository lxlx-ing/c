#include <stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[10][10];
    int i,j,t;
    for(j=0;j<m;j++){
    	for(i=0;i<n;i++){
    		scanf("%d",&t);
    		a[i][j]=t;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n"); 
	}
    return 0;
}
