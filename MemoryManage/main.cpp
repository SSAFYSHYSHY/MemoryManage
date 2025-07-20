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
	cout << "1. ���α׷� �Է�.(�׽�Ʈ �̹Ƿ� �Է½� ���� �޸� ���� �Ҵ� �˴ϴ�. �޸𸮴� �� 1024)\n";
	cout << "2. ���α׷� ����.\n";
	cout << "3. ���� �������� ���� ���α׷� ����.\n";
	cout << "4. ���� �������� ���� ���α׷� ����.\n";
	cout << "5. �޸� ���� ����.\n";
	cout << "6. �����ٸ� ��å ����.\n";
	cout << "7. �ý��� �α� Ȯ��.\n";
	cout << "8. ��ü �ʱ�ȭ.\n";
	cout << "9. ����.\n";
	cout << "\n\n";
	cin >> num;

	return num;
}

//���� �̱���.
void System_DeadLock() {
	
}

//���� �̱���.
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
	LinkedList memoryList;

	System_Start();
	srand(time(NULL));
	
	while (1) {
		cout << "\n\n";
		int ord = System_input();

		if (ord == 9) {
			break;
		}

		//1. ���α׷� �Է�.
		if (ord == 1) {
			cout << "�Է��ϰ��� �ϴ� ���α׷��� �̸��� �Է����ֽʽÿ�.\n";

			string s;
			cin >> s;

			int new_data = rand() % 100 + 1;
			memoryList.Insert(s, new_data);

			cout << "���α׷� " << s << " �� " << new_data << " (MB)��ŭ �߰���.\n";
		}
		//2. ���α׷� ����.
		else if (ord == 2) {
			cout << "�����ϰ��� �ϴ� ���α׷��� �̸��� �Է����ֽʽÿ�.\n";

			string s;
			cin >> s;

			if (memoryList.Delete(s)) {
				cout << "���α׷� " << s << " �� " << "������.\n";
			}
			else {
				cout << "���α׷� " << s << " �� �����ϴ�.\n";
			}

		}
		//3. �������� ����.
		else if (ord == 3) {
			cout << "�޸𸮿� ����� ���α׷����� ������������ ����մϴ�.\n\n";

			memoryList.Upper();
		}

		//4. �������� ����.
		else if (ord == 4) {
			cout << "�޸𸮿� ����� ���α׷����� ������������ ����մϴ�.\n\n";

			memoryList.Down();
		}

		//5. �޸� ���� ���.
		else if (ord == 5) {
			cout << "�޸� ���¸� ����մϴ�.\n\n";

			memoryList.Print();
		}

		//6. �����층 ��å ����.
		else if (ord == 6) {
			cout << "�����ٸ� ��å�� �����մϴ�.\n\n";
			cout << "������ ��å�� ������ �����ϴ�.\n";
			cout << "1.Round Robin, 2.SRT �����ٸ�, 3.MFQ �����ٸ�\n\n";
			cout << "������ ��å�� ������ �����ϴ�.\n";
			cout << "4.FIFO, 5.�켱����, 6.SJF, 7.HRN\n\n";

			cout << "�����ϰ��� �ϴ� �����ٸ��� �Է����ּ���.\n\n";
			int num;
			cin >> num;

			LinkedList temp;
			temp = memoryList;
			temp.Scheduling(num);

			memoryList = temp;

			cout << num << " �� �����ٸ����� ��å�� �����߽��ϴ�!\n\n";
		}

		//7. �ý��� �α� Ȯ��.
		else if (ord == 7) {
			cout << "���ݱ��� ������ ��� ��ɾ ����մϴ�.\n\n";

			memoryList.LOG();
		}

		//8. ��ü �ʱ�ȭ.
		else if (ord == 8) {
			cout << "��ü �ʱ�ȭ�� �����մϴ�.\n\n";

			memoryList.Clear();
		}

		else if (ord == 9) {
			cout << "�ý����� �����մϴ�.\n\n";
			break;
		}
	}

	//�ý��� �����.
	System_DeadLock();
	//�ý��� �ܺ� ��ŷ ���.
	System_Alert();
}