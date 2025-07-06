#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

#include <ctime>

#include "Linked_list.h"

using namespace std;

void System_Start() {
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "�޸� ���� ���α׷��� �����մϴ�.\n";
	cout << "Ver0.0.5\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";

	this_thread::sleep_for(chrono::seconds(5));
}

int System_input() {
	int num;
	
	cout << "��ɾ �Է����ּ���.\n";
	//�ش� ������Ʈ������ ���� ������ �޸𸮰� �Ҵ��.
	cout << "1. ���α׷� �Է�.(�׽�Ʈ �̹Ƿ� �Է½� ���� �޸� ���� �Ҵ� �˴ϴ�. �޸𸮴� �� 1024)\n";
	cout << "2. ���α׷� ����.\n";
	cout << "3. ���� �������� ���� ���α׷� ����.\n";
	cout << "4. �޸� ���� ����.\n";
	cout << "5. �����ٸ� ��å ����.\n";
	cout << "6. �ý��� �α� Ȯ��.\n";
	cout << "7. ��ü �ʱ�ȭ.\n";
	cin >> num;

	return num;
}

void System_DeadLock() {
	cout << "����� �߻�!! ������ �ַ������ ������� ����ϴ�!";


}

pair<int, string > System_Find_Hack() {
	return make_pair(0,"null");
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
	srand(time(NULL));

	//�ʱ� ��� ����.(ù �����.)
	nodes[0] = new Node(-1);
	
	int ord = System_input();

	//���α׷� �Է�.
	if (ord == 1) {
		//���α׷� �̸�.
		string s;
		cin >> s;

		//������ �޸�.
		int new_data = rand() % 100 + 1;
		Node* memory = new Node(new_data);

		Insert_Front(nodes[0], memory);
	}
	//

	//�ý��� �����.
	System_DeadLock();
	//�ý��� �ܺ� ��ŷ ���.
	System_Alert();

}