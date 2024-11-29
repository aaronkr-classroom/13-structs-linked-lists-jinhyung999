//2d_ppl_age_step.c //week13-slide5

#include <stdio.h>
#include <malloc.h>

int main(void) {
	//����
	int age_step, age, member, temp, sum;
	//���ɺ� �ο����� ������ ������ - ����ڿ��� �Է¹���
	unsigned char *p_limit_table;
	//���ɺ� �����̸�Ű�� Ƚ�� ������ ������ ������
	unsigned char **p;

	printf("20�����(?����) �����ؼ� �������� �� ���ΰ���: ");
	scanf_s("%d", &age_step);

	//���ɺ� �ο����� ������ �޸𸮸� ����
	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);

	for (age = 0; age < age_step; age++) {
		//�������� ��������Ű�� Ƚ����� �����
		printf("\n%d0�� ������ ��������Ű�� ȸ��\n", age + 2);
		printf("�� ���ɴ�� �� ���Դϱ�? ");

		scanf_s("%d", &temp);
		*(p_limit_table + age) = (unsigned char)temp;

		// �Է¹��� �ο�����ŭ �޸𸮸� �Ҵ�
		*(p+age) = (unsigned char*)malloc(*(p_limit_table + age));

		for (member = 0; member < *(p_limit_table + age); member++) {
			printf("#%d: ", member + 1);

			//�����̸�Ű�� Ƚ���� ������ �Է��ϱ�
			scanf_s("%d", &temp);
			*(*(p + age) + member) = (unsigned char)temp;
		}
	}

	printf("\n\n���ɺ� ��� �����̸�Ű�� Ƚ��\n");
	for (age = 0; age < age_step; age++) {
		sum = 0;
		//int limit = p[age][0];

		printf("%d0��", age + 2);
		
		for (member = 0; member < *(p_limit_table + age); member++) {
			sum = sum + *(*(p+age) + member);
		}

		printf("%5.2f\n", (double)sum / *(p_limit_table + age));
		free(*(p + age));
	}
	free(p);

	free(p_limit_table);
	return 0;
}