//2d_ppl_age_step.c //week13-slide5

#include <stdio.h>
#include <malloc.h>

int main(void) {
	//변수
	int age_step, age, member, temp, sum;
	//연령별 인원수를 저장할 포인터 - 사용자에게 입력받음
	unsigned char *p_limit_table;
	//연령별 윗몸이르키기 횟수 저장할 이차원 포인터
	unsigned char **p;

	printf("20대부터(?까지) 시작해서 연령층이 몇 개인가요: ");
	scanf_s("%d", &age_step);

	//연령별 인원수를 저장할 메모리를 만듦
	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);

	for (age = 0; age < age_step; age++) {
		//각연령의 윗몸일으키기 횟수라고 출력함
		printf("\n%d0대 연령의 윗몸일으키기 회수\n", age + 2);
		printf("이 연령대는 몇 명입니까? ");

		scanf_s("%d", &temp);
		*(p_limit_table + age) = (unsigned char)temp;

		// 입력받은 인원수만큼 메모리를 할당
		*(p+age) = (unsigned char*)malloc(*(p_limit_table + age));

		for (member = 0; member < *(p_limit_table + age); member++) {
			printf("#%d: ", member + 1);

			//윗몸이르키기 횟수를 정수로 입력하기
			scanf_s("%d", &temp);
			*(*(p + age) + member) = (unsigned char)temp;
		}
	}

	printf("\n\n연령별 평균 윗몸이르키기 횟수\n");
	for (age = 0; age < age_step; age++) {
		sum = 0;
		//int limit = p[age][0];

		printf("%d0대", age + 2);
		
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