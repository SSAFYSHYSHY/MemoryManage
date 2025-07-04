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
	cout << "메모리 관리 프로그램을 시작합니다.\n";
	cout << "Ver0.0.1\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";

	this_thread::sleep_for(chrono::seconds(5));
}

int System_input() {
	int num;
	
	cout << "명령어를 입력해주세요.\n";
	//해당 프로젝트에서는 랜덤 값으로 메모리가 할당됨.
	cout << "1. 프로그램 입력.(테스트 이므로 입력시 랜덤 메모리 양이 할당 됩니다.)\n";
	cout << "2. 프로그램 삭제.\n";
	cout << "3. 가장 점유율이 높은 프로그램 정렬.\n";
	cin >> num;

	return num;
}

void System_DeadLock() {
	cout << "데드락 발생!! 최적의 솔루션으로 데드락을 벗어납니다!";


}

pair<int, string > System_Find_Hack() {

}

void System_Alert() {
	cout << "[경고] 외부 패킷의 접근 시도.\n";
	cout << "\a";
	cout << "[경고] 외부 패킷의 접근 시도.\n";
	cout << "\a";
	cout << "[경고] 외부 패킷의 접근 시도.\n";
	cout << "\a";

	cout << "해당 외부 패킷이 가고자 하는 곳을 탐색합니다.\n";
	//접근되고 있는 프로그램 탐색.
	pair<int, string> look = System_Find_Hack();
	cout << "색출 성공! 해당 프로그램의 인덱스와 이름값을 호출합니다.\n";

}

int main() {
	System_Start();

	int ord = System_input();

	//시스템 데드락.
	System_DeadLock();
	//시스템 외부 해킹 경고.
	System_Alert();

}