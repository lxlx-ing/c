#include <stdio.h>
#include <stdlib.h>
struct BookLib   //����ͼ��ṹ��
{
    char name[12]; //����
    int num; //��������
    float price; //��ĵ���
    float SumMoney; //ÿ������ܽ��
};
void InputInfo(struct BookLib Book[],float *T) //�������뺯��������Ϊ�ṹ������
{
	int i;
	for(i=0;i<4;i++){
		*T+=Book[i].num*Book[i].price;
	}
}
void OutputInfo(struct BookLib Book[]) //�����������������Ϊ�ṹ������
{
	printf("�����嵥��\n���� ���� ���� �ϼ�\n");
	int i;
	for(i=0;i<4;i++){
		printf("%s %d %.2f %.2f\n",Book[i].name,Book[i].num,Book[i].price,Book[i].num*Book[i].price);
	}
}
int main()
{
    struct BookLib Book[4]; //�ṹ������
	float Total=0; //�����ܽ��
	int i;
	for(i=0;i<4;i++){
		scanf("%s %d %f",Book[i].name,&Book[i].num,&Book[i].price);
	}
    InputInfo(Book,&Total);
	OutputInfo(Book);
	printf("�������ܼƣ�%.2f",Total);
return 0;
}
