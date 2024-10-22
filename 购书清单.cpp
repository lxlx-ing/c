#include <stdio.h>
#include <stdlib.h>
struct BookLib   //定义图书结构体
{
    char name[12]; //书名
    int num; //购买数量
    float price; //书的单价
    float SumMoney; //每种书的总金额
};
void InputInfo(struct BookLib Book[],float *T) //定义输入函数，参数为结构体数组
{
	int i;
	for(i=0;i<4;i++){
		*T+=Book[i].num*Book[i].price;
	}
}
void OutputInfo(struct BookLib Book[]) //定义输出函数，参数为结构体数组
{
	printf("购书清单：\n书名 数量 单价 合计\n");
	int i;
	for(i=0;i<4;i++){
		printf("%s %d %.2f %.2f\n",Book[i].name,Book[i].num,Book[i].price,Book[i].num*Book[i].price);
	}
}
int main()
{
    struct BookLib Book[4]; //结构体数组
	float Total=0; //购书总金额
	int i;
	for(i=0;i<4;i++){
		scanf("%s %d %f",Book[i].name,&Book[i].num,&Book[i].price);
	}
    InputInfo(Book,&Total);
	OutputInfo(Book);
	printf("购书金额总计：%.2f",Total);
return 0;
}
