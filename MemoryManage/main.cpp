#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <ctime>
#include <vector>

#include "Linked_list.h"

using namespace std;

vector<int> v;

void System_Start() {
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "�޸� ���� ���α׷��� �����մϴ�.\n";
	cout << "Ver1.0.0\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";
}

int System_input() {

	int num;
	
	cout << "��ɾ �Է����ּ���.\n";
	cout << "1. ���α׷� �Է�.(�׽�Ʈ �̹Ƿ� �Է½� ���� �޸� ���� �Ҵ� �˴ϴ�. �޸𸮴� �� 1024)\n";
	cout << "2. ���α׷� ����.\n";
	cout << "3. ���� �������� ���� ���α׷� ����.\n";
	cout << "4. ���� �������� ���� ���α׷� ����.\n";
	cout << "5. �޸� ���� ����.\n";
	cout << "6. �����ٸ� ��å���� �ù�.\n";
	cout << "7. �ý��� �α� Ȯ��.\n";
	cout << "8. ��ü �ʱ�ȭ.\n";
	cout << "9. ����.\n";
	cout << "\n\n";
	cin >> num;

	v.push_back(num);

	return num;
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
			cout << "�����ٸ� ��å�� �ùķ��̼� �մϴ�.\n\n";
			cout << "������ ��å�� ������ �����ϴ�.\n";
			cout << "1.Round Robin, 2.SRT �����ٸ�, 3.MFQ �����ٸ�\n\n";
			cout << "������ ��å�� ������ �����ϴ�.\n";
			cout << "4.FIFO, 5.�켱����, 6.SJF, 7.HRN\n\n";

			cout << "�ùķ��̼� �ϰ��� �ϴ� �����ٸ��� �Է����ּ���.\n\n";
			int num;
			cin >> num;

			LinkedList temp = memoryList.copy();
			temp.Scheduling(num);
		}

		//7. �ý��� �α� Ȯ��.
		else if (ord == 7) {
			cout << "���ݱ��� ������ ��� ��ɾ ����մϴ�.\n\n";

			for (int i = 0; i < v.size(); i++) {
				if (v[i] == 1) {
					cout << i + 1 << "�� , ���α׷� �Է� \n";
				}
				else if (v[i] == 2) {
					cout << i + 1 << "�� , ���α׷� ���� \n";
				}
				else if (v[i] == 3) {
					cout << i + 1 << "�� , �������� ���� ���α׷� �켱����. \n";
				}
				else if (v[i] == 4) {
					cout << i + 1 << "�� , �������� ���� ���α׷� �켱����. \n";
				}
				else if (v[i] == 5) {
					cout << i + 1 << "�� , �޸� ���� Ȯ��. \n";
				}
				else if (v[i] == 6) {
					cout << i + 1 << "�� , �����층 ��å �ù�. \n";
				}
				else if (v[i] == 7) {
					cout << i + 1 << "�� , �α� Ȯ��. \n";
				}
				else if (v[i] == 8) {
					cout << i + 1 << "�� , ��ü �ʱ�ȭ. \n";
				}
			}
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
}