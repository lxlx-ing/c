#include <stdio.h>
void lineMax(int m, int n, int a[10][10], int *b);
int main()
{
	int a[10][10];
	int b[10]; //��ž���ÿ�е����ֵ
	int m,n,i,j; // m,n�ֱ�Ϊ��ά���������������
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	lineMax(m,n,a,b);
	for(i=0;i<m;i++){
		printf("%d\n",b[i]);
	}
	return 0;
}
void lineMax(int m, int n, int a[10][10], int *b)
{
	int i,j,q;
	for(q=0;q<m;q++){
		int max=0;
		for(j=0;j<n;j++){
			if(a[q][j]>=max){
					max=a[q][j];
				}		
		}
		b[q]=max;
	}
	
}

