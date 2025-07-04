#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

#include "Linked_list.h"

using namespace std;

struct Node {
	int data;
	Node* prev, * next;
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void System_Start() {
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "�޸� ���� ���α׷��� �����մϴ�.\n";
	cout << "Ver0.0.1\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";

	this_thread::sleep_for(chrono::seconds(5));
}

int System_input() {
	int num;
	
	cout << "��ɾ �Է����ּ���.\n";
	//�ش� ������Ʈ������ ���� ������ �޸𸮰� �Ҵ��.
	cout << "1. ���α׷� �Է�.(�׽�Ʈ �̹Ƿ� �Է½� ���� �޸� ���� �Ҵ� �˴ϴ�.)\n";
	cout << "2. ���α׷� ����.\n";
	cout << "3. ���� �������� ���� ���α׷� ����.\n";
	cin >> num;

	return num;
}

void System_DeadLock() {
	cout << "����� �߻�!! ������ �ַ������ ������� ����ϴ�!";


}

pair<int, string > System_Find_Hack() {

}

void System_Alert() {
	cout << "[���] �ܺ� ��Ŷ�� ���� �õ�.\n";
	cout << "\a";
	cout << "[���] �ܺ� ��Ŷ�� ���� �õ�.\n";
	cout << "\a";
	cout << "[���] �ܺ� ��Ŷ�� ���� �õ�.\n";
	cout << "\a";

	cout << "�ش� �ܺ� ��Ŷ�� ������ �ϴ� ���� Ž���մϴ�.\n";
	//���ٵǰ� �ִ� ���α׷� Ž��.
	pair<int, string> look = System_Find_Hack();
	cout << "���� ����! �ش� ���α׷��� �ε����� �̸����� ȣ���մϴ�.\n";

}

int main() {
	System_Start();

	int ord = System_input();

	//�ý��� �����.
	System_DeadLock();
	//�ý��� �ܺ� ��ŷ ���.
	System_Alert();

}