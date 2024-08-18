// 1244번, 스위치 켜고 끄기
// 구현, 시뮬레이션

/*
입력, 출력 조건을 잘 보라는 교훈을 주는 문제이다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 스위치 정보
	int N;
	cin >> N;

	vector<int> sw_info(N + 1);
	for (int i = 1; i < N + 1; ++i) {
		cin >> sw_info[i];
	}

	// 학생 정보
	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int s, sw_num;
		cin >> s >> sw_num;

		// 남학생인 경우
		if (s == 1) {
			const int num = sw_num;
			while (sw_num < N + 1) {
				sw_info[sw_num] ^= 1;
				sw_num += num;
			}
		}

		// 여학생인 경우
		if (s == 2) {
			sw_info[sw_num] ^= 1;
			int k = 1;
			while (sw_num - k > 0 && sw_num + k < N + 1 && sw_info[sw_num - k] == sw_info[sw_num + k]) {
				sw_info[sw_num - k] ^= 1;
				sw_info[sw_num + k] ^= 1;
				k++;
			}
		}
	}
	for (int i = 1; i < N + 1; ++i) {
		if (i != 1 && (i - 1) % 20 == 0) {
			cout << endl;
		}
		cout << sw_info[i] << " ";
	}
	cout << endl;

	return 0;
}