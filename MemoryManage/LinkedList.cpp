
//링크드 리스트 기능 구현.
#include "Linked_list.h"
#include <algorithm>
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::~LinkedList() {
	Node* curr = head;
	while (curr) {
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}

void LinkedList::Insert(std::string name, int data) {
	Node* newNode = new Node(name, data);
	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

bool LinkedList::Delete(std::string name) {
	Node* curr = head;

	while (curr != nullptr) {
		//해당 이름 발견시.
		if (curr->name == name) {
			//연결 끊기..
			if (curr->prev) {
				curr->prev->next = curr->next;
			}
			else {
				//삭제할 노드가 head
				head = curr->next;
			}

			if (curr->next) {
				curr->next->prev = curr->prev;
			}

			delete curr;
			return true;
		}
		curr = curr->next;
	}

	return false;
}

void LinkedList::Upper() {
	Node* curr = head;

	if (!head) return;

	bool flag = true;
	do {
		flag = false;
		Node* curr = head;

		while (curr->next != nullptr) {
			if (curr->data > curr->next->data) {
				std::swap(curr->data, curr->next->data);
				std::swap(curr->name, curr->next->name);
				flag = true;
			}
			curr = curr->next;
		}

	} while (flag);

	int cnt = 1;
	while (curr != nullptr) {

		std::cout << cnt << " : 프로그램 이름 : " << curr->name << " -> 차지하고 있는 메모리 " << curr->data << "\n";
		curr = curr->next;
		cnt++;
	}

}

void LinkedList::Down() {
	Node* curr = head;

	if (!head) return;

	bool flag = true;
	do {
		flag = false;
		Node *curr = head;

		while (curr->data < curr->next->data) {
			std::swap(curr->data, curr->next->data);
			std::swap(curr->name, curr->next->name);
			flag = true;
		}
		curr = curr->next;

	} while (flag);

	int cnt = 1;
	while (curr != nullptr) {

		std::cout << cnt << " : 프로그램 이름 : " << curr->name << " -> 차지하고 있는 메모리 " << curr->data << "\n";
		curr = curr->next;
		cnt++;
	}

}