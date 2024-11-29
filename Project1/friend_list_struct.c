//friend_list_struct.c

#include <stdio.h>

#define MAX_COUNT 5//친구등록가능한 최대수

typedef char NAME_TYPE[100];//13자까지 +NULL문자
typedef unsigned short int US;
typedef struct {
	NAME_TYPE name;
	US age;
	float height;
	float weight;
}Person;

int AddFriend(Person *p_friend, int count) {
	if (count < MAX_COUNT) {//입력한 최대개수확인
		//friends 배열의 count 위치로 이동
		p_friend = p_friend + count;

		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1. 이름: ");
		scanf_s("%s", p_friend->name, sizeof(*(p_friend->name)));
		printf("2. 나이: ");
		scanf_s("%hu", &p_friend->age);// age배열의 count 위치에 나이를 저장함
		printf("3. 키: ");
		scanf_s("%f", &p_friend->height);
		printf("4. 몸무게: ");
		scanf_s("%f", &p_friend->weight);

		printf("입력을 완료하였습니다.\n\n");

		return 1;
	}
	else {//입력한 최대개수 넘었을때 오류출력
		printf("최대 인원을 초과하여 입력을 할수없습니다\n");
		printf("최대 %d명까지만 관리 가능합니다\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriendList(Person *p_friend, int count) {
	if (count > 0) {;
		printf("\n등록된 친구 목록\n");
		printf("=================================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s, %3d, %6.2f, %6.2f\n", p_friend->name, p_friend->age, p_friend->height, p_friend->weight);
			p_friend++; //다음위치에있는 친구로 이동 주소값증가
		}
		printf("=================================\n");
	}
	else {
		printf("\n등록된친구가 없습니다\n");
	}
}
int main() {
	//struct 사용하기 
	Person friends[MAX_COUNT];
	int count = 0, menu_num;

	//무한 루프: 사용자가 3을 누르면 break 문으로 종료
	while (1) {
		//메뉴를 화면에 출력
		printf("\t[Menu]\t\n");
		printf("=================================\n");
		printf("1. Add friend\n");
		printf("2. friend chart\n");
		printf("3. End\n");
		printf("=================================\n");
		printf("choice num\n");
		scanf_s("%d", &menu_num);
		//menu나가기
		if (menu_num == 3)break;

		switch (menu_num) {
		case 1:
			/*
			Add friend 함수가 1을 반환하면 정상적으로 친구정보가 추가된것입니다
			따라서 1을 반환했을 때만 등록된 친구 수를 증가시킵니다.
			*/
			if (AddFriend(friends, count))
				count++;
			break;
		case 2:
			ShowFriendList(friends, count);
			break;
		default:
			//번호가 유효하지않은경우에 오류 메시지를 출력함 
			printf("Enter only num 1 ~ 3!!\n\n");
		}
	}

	return 0;
}