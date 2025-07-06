#pragma once
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

	void Insert(std::string name, int data);
};