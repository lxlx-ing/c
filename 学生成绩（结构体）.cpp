#include <stdio.h>
struct Student
{  
	char name[10];
	int num,comps,engs;
	float totalScore;	
};
int main()
{
	struct Student stu[10];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d %d %d",&stu[i].name,&stu[i].num,&stu[i].comps,&stu[i].engs);
		stu[i].totalScore=stu[i].comps+stu[i].engs; //×Ü·Ö
	}
	for(i=0;i<n;i++){
		printf("%s %d %.2f\n",stu[i].name,stu[i].num,stu[i].totalScore);
	}
	return 0;
}
