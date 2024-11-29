//2d_ppl_malloc.c
#include <stdio.h>
#include <malloc.h>

int main(void) {
	//변수
	int age, member, temp, sum;
	//20대 4명,30대 2명,40대 3명
	unsigned char limit_table[3];
	//윗몸이르키기 횟수 저장할 배열
	unsigned char *p[3];

	for (age = 0; age < 3; age++) {
		//각연력의 윗몸일으키기 횟수라고 출력함
		printf("\n%d0대 연령의 윗몸일으키기 회수\n", age + 2);
		printf("이 연령대는 몇 명입니까? ");

		scanf_s("%d", &temp);
		limit_table[age] = (unsigned char)temp;

		// 입력받은 인원수만큼 메모리를 할당
		p[age] = (unsigned char*)malloc(limit_table[age]);

		for (member = 0; member < limit_table[age]; member++) {
			printf("#%d: ", member + 1);

			//윗몸이르키기 횟수를 정수로 입력하기
			scanf_s("%d", &temp);
			*(p[age] + member) = (unsigned char)temp;
		}
	}

	printf("\n\n연령별 평균 윗몸이르키기 횟수\n");
	for (age = 0; age < 3; age++) {
		sum = 0;

		printf("%d0대", age + 2);

		for (member = 0; member < limit_table[age]; member++) {
			sum = sum + *(p[age] + member);
		}

		printf("%5.2f\n", (double)sum / limit_table[age]);
		free(p[age]);
	}
}