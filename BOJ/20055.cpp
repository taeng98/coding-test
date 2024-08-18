// 20055번, 컨베이어 벨트 위의 로봇
// 구현, 시뮬레이션

/*
우선, 정확한 문제 이해가 어려웠던 문제였다. (문제 이해력을 늘리자.)
그 다음으로, `=` 을 써야하는데 그 자리에 '==` 를 써놔서 계속 디버깅에 실패했다. (코드를 천천히 꼼꼼하게 다시 보자.)
꽤 시간을 많이 들여서 풀었는 데, 다음부터는 시간 제한을 두고 (1시간 정도?) 풀어야겠다.
C++에서 덱을 연습하기 좋은 문제였다.
*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	deque<int> conveyor_status;
	deque<bool> conveyor_used;

	// 컨베이터벨트 내구도 채우기
	for (int i = 0; i < 2 * N; i++) {
		int temp;
		cin >> temp;
		conveyor_status.push_back(temp);
		conveyor_used.push_back(false);
	}

	int cnt = 0;
	while (true) {
		cnt++;

		// 1번 단계 수행
		conveyor_status.push_front(conveyor_status.back());
		conveyor_status.pop_back();
		conveyor_used.push_front(conveyor_used.back());
		conveyor_used.pop_back();
		conveyor_used[N - 1] = false;

		//2번 단계 수행
		for (int i = N - 2; i >= 0; i--) {
			if (conveyor_used[i] && (!conveyor_used[i + 1]) && (conveyor_status[i + 1] > 0)) {
				conveyor_used[i] = false;
				conveyor_used[i + 1] = true;
				conveyor_status[i + 1]--;
			}
		}
		conveyor_used[N - 1] = false;

		// 3번 단계 수행
		if ((!conveyor_used[0]) && (conveyor_status[0] > 0)) {
			conveyor_used[0] = true;
			conveyor_status[0]--;
		}

		// 4번 단계 수행
		int zero_cnt = 0;
		for (int i = 0; i < 2 * N; i++) {
			if (conveyor_status[i] == 0) {
				zero_cnt++;
			}
		}

		if (zero_cnt >= K) {
			break;
		}
	}

	cout << cnt << endl;

	return 0;
}