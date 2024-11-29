//linked_list.c

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct Node* p_next;
}Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node));//새노드를 할당
		*pp_tail = (*pp_tail)->p_next;// p_tail(*pp_tail)에 새 노드의 주소값을 저장
	}
	else {
		//*p_head값이 NULL이라서 첫 노드가 추가도미. p_head 값에 직접 대입함
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;//새 노드의 주소 값을 p_tail(*pp_tail)에 저장
	}
	(*pp_tail)->number = data;//새 노드의 number에 data 값을 저장
	(*pp_tail)->p_next = NULL;//다음노드가 없음을 명시
}

int main() {
	//노드의 시작과 끝을 기억할 포인터
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	//무한루프
	while (1) {
		printf("숫자를 입력하시오.(9999를 누르면 종료): ");
		scanf_s("%d", &temp);
		if (9999 == temp) break;

		//노드의 시작과 끝을 기억하는 포인터의 주소 값과 입력된 숫자를 전달
		AddNumber(&p_head, &p_tail, temp);
	}

	//입력된 숫자를 출력하기 위해서 노드를 탐색할 포인터에 
	//시작 노드의 주소값을 대입
	p = p_head;
	while (NULL != p) {
		if (p != p_head)printf(" + ");
		printf(" %d ", p->number);
		sum = sum + p->number;
		p = p->p_next;//다음노드 이동
	}
	printf(" = %d\n", sum);

	while (NULL != p_head) {//p_head가 NULL이될때까지
		p = p_head;//현재노드를 삭제하기위해 p 변수에 노드 주소값을 저장
		p_head = p_head->p_next;//시작위치를 다음노드로 옮김
		free(p);// 기억했떤 주소를 사용하여 노드를 삭제
	}
	p_tail = p_head;//반복문이 나오면 p_head값은 NULL. p_tail값도 NULL로 변경함

	return 0;
}