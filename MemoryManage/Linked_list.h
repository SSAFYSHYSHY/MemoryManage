#pragma once

//링크드 리스트 인터페이스 정의.
#include <unordered_map>
#include <string>

struct Node {
	std::string name;
	int data;
	Node* prev, * next;
	Node(std::string name, int data) 
		: name(name), data(data), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList();
	~LinkedList();

	LinkedList(const LinkedList& other) {
		head = nullptr;
		Node* curr = other.head;

		while (curr != nullptr) {
			Insert(curr->name, curr->data);
			curr = curr->next;
		}
	}

	LinkedList copy() const {
		LinkedList newList;
		Node* curr = head;

		while (curr != nullptr) {
			newList.Insert(curr->name, curr->data);
			curr = curr->next;
		}

		return newList;
	}

	void Insert(std::string name, int data);
	bool Delete(std::string name);
	void Upper();
	void Down();
	void Print();
	void Scheduling(int num);
	void Clear();
};