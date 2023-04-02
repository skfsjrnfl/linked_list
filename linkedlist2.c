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
void RemoveFirst(CircularList* list);

int main() {
	int n=0;
	int count = 0;
	CircularList list;
	list.len = 0;
	scanf("%d", &n);
	if (n == 0) {
		printf("wrong input\n");
		printf("please type: N = n\n");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		InsertLast(&list, i + 1);
	}
	while (list.len != 1) {
		RemoveFirst(&list);
		list.tail = list.tail->next;
	}
	printf("%d", (list.tail->data));
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

void RemoveFirst(CircularList* list) {
	if (list->len == 1)
		RemoveInitdata(list);
	else {
		Node* temp = list->tail->next;
		list->tail->next = temp->next;

		free(temp);
		list->len--;
	}
}