#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef struct _Node {
	int data;
	struct _Node* next;
}Node;
typedef struct {
	Node* tail;
	int len;
}CircularList;

void InsertInitdata(CircularList* list, int dat);
void InsertLast(CircularList* list, int dat);
void RemoveInitdata(CircularList* list);
int RemoveMiddle(CircularList* list, int pos);

int main() {
	int n = -1;
	int k = -1;
	CircularList list;
	list.len = 0;
	scanf("%d %d", &n, &k);

	if ((n == -1) || (k == -1)) {
		printf("잘못된 입력입니다.");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		InsertLast(&list, i+1);
	}

	while (list.len != 1) {
		printf("%d", RemoveMiddle(&list, (k - 1)));
		if (list.len != 1)
			printf(",");
	}
	printf("\n%d", list.tail->data);
	RemoveInitdata(&list);
}

void InsertInitdata(CircularList* list, int dat) {
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = dat;
	newnode->next = newnode;

	list->tail = newnode;
	list->len++;
}

void InsertLast(CircularList* list, int dat) {
	if (list->len == 0)
		InsertInitdata(list, dat);
	else {
		Node* newnode = (Node*)malloc(sizeof(Node));

		newnode->data = dat;
		newnode->next = list->tail->next;

		list->tail->next = newnode;
		list->tail = newnode;
		list->len++;
	}
}
void RemoveInitdata(CircularList* list) {
	if (list->len == 0) {
		printf("리스트가 비어있습니다");
		exit(1);
	}
	if (list->len == 1) {
		free(list->tail);
		list->len--;
		list->tail = NULL;
	}
}
int RemoveMiddle(CircularList* list,int pos) {
	if (list->len == 1) {
		RemoveInitdata(list);
	}
	else {
		Node* cur, * temp;
		int a;
		cur = list->tail;
		for (int i = 0; i < pos; i++)
			cur = cur->next;
		temp = cur->next;
		a = temp->data;
		cur->next = temp->next;
		list->tail = cur;
		free(temp);
		list->len--;

		return a;
	}
}