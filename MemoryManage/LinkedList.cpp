
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

void LinkedList::Print() {
	Node* curr = head;

	int cnt = 1;
	double mem = 1024;
	std::cout.precision(2);

	while (curr != nullptr) {
		std::cout << cnt << " : 프로그램 이름 : " << curr->name << " -> 차지하고 있는 메모리 " << curr->data << " -> 메모리 점유율 " << (double)((curr->data) / mem) << "%\n";
		cnt++;
		curr = curr->next;
	}

}
// 1.Round Robin, 2.SRT 스케줄링, 3.MFQ 스케줄링 4.FIFO, 5.우선순위, 6.SJF, 7.HRN";
void LinkedList::Scheduling(int num) {
	//Round Robin
	Node* curr = head;
	int cnt = 1;

	if (num == 1) {
		std::cout << "Round Robin 형식으로 진행합니다.\n" << "순회하기 위해 시간 별로 처리하는 메모리 양을 입력해주세요.\n";
		int ctime;
		std::cin >> ctime;

		while (curr != nullptr) {

		}



	}
	//SRT 
	else if (num == 2) {

	}
	//MFQ
	else if (num == 3) {

	}
	//FIFO
	else if (num == 4) {

	}
	//우선순위
	else if (num == 5) {

	}
	//SJF
	else if (num == 6) {

	}
	//HRN
	else if (num == 7) {

	}

}