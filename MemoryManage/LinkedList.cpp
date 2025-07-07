
//��ũ�� ����Ʈ ��� ����.
#include "Linked_list.h"

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

void LinkedList::Delete(std::string name, int data) {
	
	if (u->prev != nullptr) {
		u->prev->next = u->next;
	}
	if (u->next != nullptr) {
		u->next->prev = u->prev;
	}

	delete u;
}