//Person.c

#include <stdio.h>

typedef unsigned short int us;
typedef struct {
	char name[12];
	us age;
	float height;
	float weight;
}Person;

int main() {
	Person data;//Person�ڷ������� data ������ ����
	printf("������� ������ �Է��ϼ���.\n");
	printf("�̸�\n");
	scanf_s("%s", data.name, sizeof(data.name));
	printf("����\n");
	scanf_s("%hu", &data.age);//%hu�� unsigned short int ����
	printf("Ű\n");
	scanf_s("%f", &data.height);
	printf("������\n");
	scanf_s("%f", &data.weight);

	printf("\n�Է��������� ������ �����ϴ�\n");

	//Ű�� �����Դ� ù° �ڸ������� �����ֱ����� %.1f�������� �����
	printf("%s : %d�� : %.1fcm : %.1fkg\n",data.name, data.age, data.height, data.weight);

	return 0;
}