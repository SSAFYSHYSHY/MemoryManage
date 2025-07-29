
//링크드 리스트 기능 구현.
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
	if (num == 1) {
		Node* curr = head;

		std::cout << "Round Robin 형식으로 진행합니다.\n" << "순회하기 위해 시간 별로 처리하는 메모리 양을 입력해주세요.\n";
		int memory_limit_time;
		std::cin >> memory_limit_time;

		//q 를 선언하고 관리.
		std::queue<Node*> q;
		while (curr != nullptr) {
			q.push(curr);
			curr = curr->next;
		}

		while (!q.empty()) {
			Node* first = q.front();
			q.pop();
			std::cout << first->name << " 프로그램 들어옴. 잔여 메모리 : " << first->data << " \n";

			if (first->data > memory_limit_time) {
				first->data -= memory_limit_time;
				q.push(first);
			}
		}

	}
	//SRT 
	else if (num == 2) {
		Node* curr = head;

		std::cout << "SRT 형식으로 진행합니다.\n" << "가장 짧은 메모리를 가진 프로그램이 우선적으로 보여집니다.\n";
		
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
			std::cout << curr->name << " 프로그램 들어옴. 처리 메모리 : " << curr->data << "\n";
			curr = curr->next;
		}

	}
	//MFQ
	else if (num == 3) {
		Node* curr = head;

		std::cout << "MFQ 형식으로 진행합니다.\n" << "FeedBack을 통해 우선순위가 자동으로 조정됩니다.\n";
		std::cout << "메모리를 관리할 총 4개의 Queue가 배정됩니다. 1024의 메모리 까지를 고려합니다.\n";
		std::cout << "Queue 1 : 256, Queue 2 : 512, Queue 3 : 768 , Queue 4 : FIFO 순으로 처리합니다.\n";

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

					//프로세스 완료.
					if (qtime == -1 || mem <= qtime) {
						std::cout << curr->name << " 프로그램 들어옴. 처리 메모리 : " << mem << "\n";
					}
					//미완료시.
					else {
						std::cout << curr->name << " 프로그램 부분실행. Queue(" << i << ", 처리량 : " << qtime << "\n";
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

		std::cout << "FIFO 형식으로 진행됩니다.\n" << "가장 먼저 들어온 프로그램 부터 작동됩니다.\n";

		do {
			Node* curr = head;

			std::cout << curr->name << " 프로그램 들어옴, 처리 메모리 : " << curr->data << "\n";
			curr = curr->next;

		} while (curr != nullptr);

	}
	//우선순위
	else if (num == 5) {
		Node* curr = head;

		std::cout << "우선순위 형식으로 진행됩니다.\n" << "현재 실행중인 프로그램(헤더)와 비교해서 다음 우선순위(메모리)가 높은 프로그램이 작동됩니다..\n";
		std::cout << "해당 시뮬에서는 가장 높은 메모리를 가진 프로그램이 가장 높은 우선순위를 가지고 있다 가정합니다.\n";

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
			std::cout << curr->name << " 프로그램이 실행됩니다. 처리 메모리 : " << curr->data << "\n";
			curr = curr->next;
		}
	}
	//SJF
	else if (num == 6) {
		std::cout << "SJF 형식으로 진행됩니다.\n" << "가장 짧은 작업량을 가진 프로그램이 먼저 실행됩니다.\n";
		std::cout << "도착 시간을 입력하면 해당 입력이 SJF의 도착 시간으로 정해집니다.\n";
		std::cout << "가장 첫 프로그램은 자동으로 도착 시간 0 으로 설정됩니다.\n";

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

		//도착 시간 포함한 벡터.
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

			//가장 짧은 작업 선택.
			for (int i = 0; i < v.size(); i++) {
				if (!visited[i] && v[i].arrive <= curr_time && v[i].memory < mini) {
					mini = v[i].memory;
					shortest = i;
				}
			}

			//도착 없으면 시간 증가.
			if (shortest == -1) {
				curr_time++;
				continue;
			}

			//대기시간, 실행시간.
			int wait = curr_time - v[shortest].arrive;
			int work = wait + v[shortest].memory;

			std::cout << "프로그램 : " << v[shortest].name << " 의 대기시간은 : " << wait << ", 실행시간은 : " << work << " 입니다.\n";
			curr_time += v[shortest].memory;
			visited[shortest] = true;
			finish++;
		}

	}
	//HRN
	else if (num == 7) {
		std::cout << "HRN 형식으로 진행됩니다.\n" << "프로그램 응답순위가 커질 수록 우선순위 실행 속도가 높아집니다.\n";
		std::cout << "해당 시뮬레이션 에서의 대기시간은 +10 초씩 증가한다 가정합니다.\n";

		struct qNode {
			std::string name;
			int memory;
			int wait;
		};

		int time = 0;
		std::vector<qNode> v;
		Node* curr = head;

		//평균 계산 벡터에 누적.
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

			//가장 긴 작업 선택.
			for (int i = 0; i < v.size(); i++) {
				if (visited[i] || v[i].wait > maxi) continue;

				int wait_time = now - v[i].memory;
				double rr = (double)(wait_time + v[i].memory / v[i].memory);

				if (rr > maxi) {
					maxi = rr;
					shortest = i;
				}
			}

			//도착 프로그램 없으면 시간 증가. 
			if (shortest == -1) {
				now++;
				continue;
			}

			int real_wait = now - v[shortest].wait;
			int mean_time = real_wait + v[shortest].memory;

			std::cout << "프로그램 : " << v[shortest].name << " 의 대기시간은 : " << real_wait << " 를 가지고 있고, 반환시간은 " << mean_time << " 를 가지고 있습니다.\n";
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