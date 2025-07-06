#pragma once
#include <unordered_map>

struct Node {
	int data;
	Node* prev, * next;
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

unordered_map<int, Node*> nodes;

//삽입. 1 을 입력시 작동되는 함수.
void Insert_Front(Node *u, Node *new_u) {
	new_u->prev = u->prev;
	new_u->next = u;

	if (new_u->prev != nullptr) {
		new_u->prev->next = new_u;
	}
	if (new_u->next != nullptr) {
		new_u->next->prev = new_u;
	}

	if (u->prev == nullptr) {
		nodes[0] = new_u;
	}
}