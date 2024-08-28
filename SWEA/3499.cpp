// 3499번, 퍼펙트 셔플
// 구현

/*
vector에 string을 다루는 연습하는 데 좋은 문제였다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		vector<string> vec(N + 1);
		for (int i = 0; i < N; ++i) {
			cin >> vec[i];
		}
		// 더미데이터 추가 (인덱스 에러 방지)
		vec[N] = " ";
		
		const int MID = int((N + 1) / 2);

		cout << '#' << test_case << " ";
		for (int i = 0; i < MID; ++i) {
			cout << vec[i] << " " << vec[MID + i] << " ";
		}
		cout << endl;
	}
	return 0;
}