
//��ũ�� ����Ʈ ��� ����.
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
		//�ش� �̸� �߽߰�.
		if (curr->name == name) {
			//���� ����..
			if (curr->prev) {
				curr->prev->next = curr->next;
			}
			else {
				//������ ��尡 head
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

		std::cout << cnt << " : ���α׷� �̸� : " << curr->name << " -> �����ϰ� �ִ� �޸� " << curr->data << "\n";
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

		std::cout << cnt << " : ���α׷� �̸� : " << curr->name << " -> �����ϰ� �ִ� �޸� " << curr->data << "\n";
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
		std::cout << cnt << " : ���α׷� �̸� : " << curr->name << " -> �����ϰ� �ִ� �޸� " << curr->data << " -> �޸� ������ " << (double)((curr->data) / mem) << "%\n";
		cnt++;
		curr = curr->next;
	}

}
// 1.Round Robin, 2.SRT �����ٸ�, 3.MFQ �����ٸ� 4.FIFO, 5.�켱����, 6.SJF, 7.HRN";
void LinkedList::Scheduling(int num) {
	//Round Robin
	Node* curr = head;
	int cnt = 1;

	if (num == 1) {
		std::cout << "Round Robin �������� �����մϴ�.\n" << "��ȸ�ϱ� ���� �ð� ���� ó���ϴ� �޸� ���� �Է����ּ���.\n";
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
	//�켱����
	else if (num == 5) {

	}
	//SJF
	else if (num == 6) {

	}
	//HRN
	else if (num == 7) {

	}

}