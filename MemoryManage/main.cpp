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
	cout << "메모리 관리 프로그램을 시작합니다.\n";
	cout << "Ver1.0.0\n";
	cout << "----------------------------------\n";
	cout << "----------------------------------\n";
	cout << "\n\n\n";
}

int System_input() {

	int num;
	
	cout << "명령어를 입력해주세요.\n";
	cout << "1. 프로그램 입력.(테스트 이므로 입력시 랜덤 메모리 양이 할당 됩니다. 메모리는 총 1024)\n";
	cout << "2. 프로그램 삭제.\n";
	cout << "3. 가장 점유율이 높은 프로그램 정렬.\n";
	cout << "4. 가장 점유율이 낮은 프로그램 정렬.\n";
	cout << "5. 메모리 상태 보기.\n";
	cout << "6. 스케줄링 정책으로 시뮬.\n";
	cout << "7. 시스템 로그 확인.\n";
	cout << "8. 전체 초기화.\n";
	cout << "9. 종료.\n";
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

		//1. 프로그램 입력.
		if (ord == 1) {
			cout << "입력하고자 하는 프로그램의 이름을 입력해주십시오.\n";

			string s;
			cin >> s;

			int new_data = rand() % 100 + 1;
			memoryList.Insert(s, new_data);

			cout << "프로그램 " << s << " 가 " << new_data << " (MB)만큼 추가됨.\n";
		}
		//2. 프로그램 삭제.
		else if (ord == 2) {
			cout << "삭제하고자 하는 프로그램의 이름을 입력해주십시오.\n";

			string s;
			cin >> s;

			if (memoryList.Delete(s)) {
				cout << "프로그램 " << s << " 가 " << "삭제됨.\n";
			}
			else {
				cout << "프로그램 " << s << " 가 없습니다.\n";
			}

		}
		//3. 오름차순 정렬.
		else if (ord == 3) {
			cout << "메모리에 저장된 프로그램들을 오름차순으로 출력합니다.\n\n";

			memoryList.Upper();
		}

		//4. 내림차순 정렬.
		else if (ord == 4) {
			cout << "메모리에 저장된 프로그램들을 내림차순으로 출력합니다.\n\n";

			memoryList.Down();
		}

		//5. 메모리 상태 출력.
		else if (ord == 5) {
			cout << "메모리 상태를 출력합니다.\n\n";

			memoryList.Print();
		}

		//6. 스케쥴링 정책 변경.
		else if (ord == 6) {
			cout << "스케줄링 정책을 시뮬레이션 합니다.\n\n";
			cout << "선점형 정책은 다음과 같습니다.\n";
			cout << "1.Round Robin, 2.SRT 스케줄링, 3.MFQ 스케줄링\n\n";
			cout << "비선점형 정책은 다음과 같습니다.\n";
			cout << "4.FIFO, 5.우선순위, 6.SJF, 7.HRN\n\n";

			cout << "시뮬레이션 하고자 하는 스케줄링을 입력해주세요.\n\n";
			int num;
			cin >> num;

			LinkedList temp = memoryList.copy();
			temp.Scheduling(num);
		}

		//7. 시스템 로그 확인.
		else if (ord == 7) {
			cout << "지금까지 수행한 모든 명령어를 출력합니다.\n\n";

			for (int i = 0; i < v.size(); i++) {
				if (v[i] == 1) {
					cout << i + 1 << "번 , 프로그램 입력 \n";
				}
				else if (v[i] == 2) {
					cout << i + 1 << "번 , 프로그램 삭제 \n";
				}
				else if (v[i] == 3) {
					cout << i + 1 << "번 , 점유율이 높은 프로그램 우선순위. \n";
				}
				else if (v[i] == 4) {
					cout << i + 1 << "번 , 점유율이 낮은 프로그램 우선순위. \n";
				}
				else if (v[i] == 5) {
					cout << i + 1 << "번 , 메모리 상태 확인. \n";
				}
				else if (v[i] == 6) {
					cout << i + 1 << "번 , 스케쥴링 정책 시뮬. \n";
				}
				else if (v[i] == 7) {
					cout << i + 1 << "번 , 로그 확인. \n";
				}
				else if (v[i] == 8) {
					cout << i + 1 << "번 , 전체 초기화. \n";
				}
			}
		}

		//8. 전체 초기화.
		else if (ord == 8) {
			cout << "전체 초기화를 수행합니다.\n\n";

			memoryList.Clear();
		}

		else if (ord == 9) {
			cout << "시스템을 종료합니다.\n\n";
			break;
		}
	}
}