
//��ũ�� ����Ʈ ��� ����.
#include "Linked_list.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

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

		while (curr->next != nullptr) {
			if (curr->data < curr->next->data) {
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
	if (num == 1) {
		Node* curr = head;

		std::cout << "Round Robin �������� �����մϴ�.\n" << "��ȸ�ϱ� ���� �ð� ���� ó���ϴ� �޸� ���� �Է����ּ���.\n";
		int memory_limit_time;
		std::cin >> memory_limit_time;

		//q �� �����ϰ� ����.
		std::queue<Node*> q;
		while (curr != nullptr) {
			q.push(curr);
			curr = curr->next;
		}

		while (!q.empty()) {
			Node* first = q.front();
			q.pop();
			std::cout << first->name << " ���α׷� ����. �ܿ� �޸� : " << first->data << " \n";

			if (first->data > memory_limit_time) {
				first->data -= memory_limit_time;
				q.push(first);
			}
		}

	}
	//SRT 
	else if (num == 2) {
		Node* curr = head;

		std::cout << "SRT �������� �����մϴ�.\n" << "���� ª�� �޸𸮸� ���� ���α׷��� �켱������ �������ϴ�.\n";
		
		if (!head) return;
		
		bool flag = true;
		do {
			flag = false;
			Node* curr = head;

			while (curr->next != nullptr) {
				if (curr->data < curr->next->data) {
					std::swap(curr->data, curr->next->data);
					std::swap(curr->name, curr->next->name);
					flag = true;
				}

				curr = curr->next;
			}
		} while (flag);

		while (curr!=nullptr) {
			std::cout << curr->name << " ���α׷� ����. ó�� �޸� : " << curr->data << "\n";
			curr = curr->next;
		}

	}
	//MFQ
	else if (num == 3) {
		Node* curr = head;

		std::cout << "MFQ �������� �����մϴ�.\n" << "FeedBack�� ���� �켱������ �ڵ����� �����˴ϴ�.\n";
		std::cout << "�޸𸮸� ������ �� 4���� Queue�� �����˴ϴ�. 1024�� �޸� ������ ����մϴ�.\n";
		std::cout << "Queue 1 : 256, Queue 2 : 512, Queue 3 : 768 , Queue 4 : FIFO ������ ó���մϴ�.\n";

		std::queue<Node*> queue[4];
		queue[0].push(curr);
		int memory_feedback[] = { 256, 512, 768, -1 };

		do {
			queue[0].push(curr);
			curr = curr->next;
		} while (curr != nullptr);

		while (1) {
			for (int i = 0; i < 4; i++) {
				if (!queue[i].empty()) {

					Node* curr = queue[i].front();
					queue[i].pop();

					int& mem = curr->data;
					int qtime = memory_feedback[i];

					//���μ��� �Ϸ�.
					if (qtime == -1 || mem <= qtime) {
						std::cout << curr->name << " ���α׷� ����. ó�� �޸� : " << mem << "\n";
					}
					//�̿Ϸ��.
					else {
						std::cout << curr->name << " ���α׷� �κн���. Queue(" << i << ", ó���� : " << qtime << "\n";
						mem -= qtime;

						if (i + 1 < 4) {
							queue[i + 1].push(curr);
						}
						else {
							queue[i].push(curr);
						}
					}

					break;
				}

			}
		}
	}
	//FIFO
	else if (num == 4) {
		Node* curr = head;

		std::cout << "FIFO �������� ����˴ϴ�.\n" << "���� ���� ���� ���α׷� ���� �۵��˴ϴ�.\n";

		do {
			Node* curr = head;

			std::cout << curr->name << " ���α׷� ����, ó�� �޸� : " << curr->data << "\n";
			curr = curr->next;

		} while (curr != nullptr);

	}
	//�켱����
	else if (num == 5) {
		Node* curr = head;

		std::cout << "�켱���� �������� ����˴ϴ�.\n" << "���� �������� ���α׷�(���)�� ���ؼ� ���� �켱����(�޸�)�� ���� ���α׷��� �۵��˴ϴ�..\n";
		std::cout << "�ش� �ùĿ����� ���� ���� �޸𸮸� ���� ���α׷��� ���� ���� �켱������ ������ �ִ� �����մϴ�.\n";

		bool flag = true;
		do {
			flag = false;
			Node* curr = head;

			while (curr->data > curr->next->data) {
				std::swap(curr->data, curr->next->data);
				std::swap(curr->name, curr->next->name);
				flag = true;
			}

			curr = curr->next;
		} while (curr != nullptr);

		while (curr != nullptr) {
			std::cout << curr->name << " ���α׷��� ����˴ϴ�. ó�� �޸� : " << curr->data << "\n";
			curr = curr->next;
		}
	}
	//SJF
	else if (num == 6) {
		std::cout << "SJF �������� ����˴ϴ�.\n" << "���� ª�� �۾����� ���� ���α׷��� ���� ����˴ϴ�.\n";
		std::cout << "���� �ð��� �Է��ϸ� �ش� �Է��� SJF�� ���� �ð����� �������ϴ�.\n";
		std::cout << "���� ù ���α׷��� �ڵ����� ���� �ð� 0 ���� �����˴ϴ�.\n";

		int arrive_time;
		std::cin >> arrive_time;

		struct qNode {
			std::string name;
			int arrive;
			int memory;
		};

		std::vector<qNode> v;
		Node* curr = head;

		int time = 0, idx = 0;

		//���� �ð� ������ ����.
		while (curr != nullptr) {
			v.push_back({ curr->name, (idx == 0 ? 0 : arrive_time * idx), curr->data });
			curr = curr->next;
			idx++;
		}

		int curr_time = 0, finish = 0;
		std::vector<bool> visited(v.size(), false);

		while (finish < v.size()) {
			int shortest = -1;
			int mini = INT_MAX;

			//���� ª�� �۾� ����.
			for (int i = 0; i < v.size(); i++) {
				if (!visited[i] && v[i].arrive <= curr_time && v[i].memory < mini) {
					mini = v[i].memory;
					shortest = i;
				}
			}

			//���� ������ �ð� ����.
			if (shortest == -1) {
				curr_time++;
				continue;
			}

			//���ð�, ����ð�.
			int wait = curr_time - v[shortest].arrive;
			int work = wait + v[shortest].memory;

			std::cout << "���α׷� : " << v[shortest].name << " �� ���ð��� : " << wait << ", ����ð��� : " << work << " �Դϴ�.\n";
			curr_time += v[shortest].memory;
			visited[shortest] = true;
			finish++;
		}

	}
	//HRN
	else if (num == 7) {
		std::cout << "HRN �������� ����˴ϴ�.\n" << "���α׷� ��������� Ŀ�� ���� �켱���� ���� �ӵ��� �������ϴ�.\n";
		std::cout << "�ش� �ùķ��̼� ������ ���ð��� +10 �ʾ� �����Ѵ� �����մϴ�.\n";

		struct qNode {
			std::string name;
			int memory;
			int wait;
		};

		int time = 0;
		std::vector<qNode> v;
		Node* curr = head;

		//��� ��� ���Ϳ� ����.
		while (curr != nullptr) {
			v.push_back({ curr->name , curr->data , time});
			time += 10;
			curr = curr->next;
		}

		int now = 0 , finish = 0;
		std::vector<bool> visited(v.size(), false);
		
		while (finish < v.size()) {
			int shortest = -1;
			double maxi = -1.0;

			//���� �� �۾� ����.
			for (int i = 0; i < v.size(); i++) {
				if (visited[i] || v[i].wait > maxi) continue;

				int wait_time = now - v[i].memory;
				double rr = (double)(wait_time + v[i].memory / v[i].memory);

				if (rr > maxi) {
					maxi = rr;
					shortest = i;
				}
			}

			//���� ���α׷� ������ �ð� ����. 
			if (shortest == -1) {
				now++;
				continue;
			}

			int real_wait = now - v[shortest].wait;
			int mean_time = real_wait + v[shortest].memory;

			std::cout << "���α׷� : " << v[shortest].name << " �� ���ð��� : " << real_wait << " �� ������ �ְ�, ��ȯ�ð��� " << mean_time << " �� ������ �ֽ��ϴ�.\n";
			now += v[shortest].memory;
			visited[shortest] = true;
			finish++;
		}
	}
}

void LinkedList::Clear() {
	Node* curr = head;

	delete curr;
}