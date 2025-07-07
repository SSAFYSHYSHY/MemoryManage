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
	cout << "메모리 관리 프로그램을 시작합니다.\n";
	cout << "Ver0.0.5\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";

	this_thread::sleep_for(chrono::seconds(5));
}

int System_input() {
	int num;
	
	cout << "명령어를 입력해주세요.\n";
	//해당 프로젝트에서는 랜덤 값으로 메모리가 할당됨.
	cout << "1. 프로그램 입력.(테스트 이므로 입력시 랜덤 메모리 양이 할당 됩니다. 메모리는 총 1024)\n";
	cout << "2. 프로그램 삭제.\n";
	cout << "3. 가장 점유율이 높은 프로그램 정렬.\n";
	cout << "4. 메모리 상태 보기.\n";
	cout << "5. 스케줄링 정책 변경.\n";
	cout << "6. 시스템 로그 확인.\n";
	cout << "7. 전체 초기화.\n";
	cout << "8. 종료.\n";
	cin >> num;

	return num;
}

//아직 미구현.
void System_DeadLock() {
	
}

//아직 미구현.
pair<int, string > System_Find_Hack() {
	return make_pair(0,"null");
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
	LinkedList memoryList;

	System_Start();
	srand(time(NULL));
	
	while (1) {
		int ord = System_input();

		if (ord == 8) {
			break;
		}

		//1. 프로그램 입력.
		if (ord == 1) {
			//프로그램 이름.
			string s;
			cin >> s;

			//랜덤한 메모리.
			int new_data = rand() % 100 + 1;
			memoryList.Insert(s, new_data);

			cout << "프로그램 " << s << " 가 " << new_data << " (MB)만큼 추가됨.\n";
		}
		//2. 프로그램 삭제.
		else if (ord == 2) {
			string s;
			cin >> s;

			memoryList.Delete(s);

			cout << "프로그램 " << s << " 가 " << "삭제됨.\n";
		}

		//시스템 데드락.
		System_DeadLock();
		//시스템 외부 해킹 경고.
		System_Alert();
	}
}