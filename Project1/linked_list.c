//linked_list.c

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct Node* p_next;
}Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node));//����带 �Ҵ�
		*pp_tail = (*pp_tail)->p_next;// p_tail(*pp_tail)�� �� ����� �ּҰ��� ����
	}
	else {
		//*p_head���� NULL�̶� ù ��尡 �߰�����. p_head ���� ���� ������
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;//�� ����� �ּ� ���� p_tail(*pp_tail)�� ����
	}
	(*pp_tail)->number = data;//�� ����� number�� data ���� ����
	(*pp_tail)->p_next = NULL;//������尡 ������ ���
}

int main() {
	//����� ���۰� ���� ����� ������
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	//���ѷ���
	while (1) {
		printf("���ڸ� �Է��Ͻÿ�.(9999�� ������ ����): ");
		scanf_s("%d", &temp);
		if (9999 == temp) break;

		//����� ���۰� ���� ����ϴ� �������� �ּ� ���� �Էµ� ���ڸ� ����
		AddNumber(&p_head, &p_tail, temp);
	}

	//�Էµ� ���ڸ� ����ϱ� ���ؼ� ��带 Ž���� �����Ϳ� 
	//���� ����� �ּҰ��� ����
	p = p_head;
	while (NULL != p) {
		if (p != p_head)printf(" + ");
		printf(" %d ", p->number);
		sum = sum + p->number;
		p = p->p_next;//������� �̵�
	}
	printf(" = %d\n", sum);

	while (NULL != p_head) {//p_head�� NULL�̵ɶ�����
		p = p_head;//�����带 �����ϱ����� p ������ ��� �ּҰ��� ����
		p_head = p_head->p_next;//������ġ�� �������� �ű�
		free(p);// ����߶� �ּҸ� ����Ͽ� ��带 ����
	}
	p_tail = p_head;//�ݺ����� ������ p_head���� NULL. p_tail���� NULL�� ������

	return 0;
}