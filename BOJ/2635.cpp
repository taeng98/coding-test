// 2635번, 수 이어가기
// 완전탐색

/*
반복문 연습에 좋은 문제 같다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> result;
	int max_len = 0;

	for (int i = N / 2; i <= N; ++i) {
		vector<int> temp;
		
		// 2번째 수까지 채워 놓기
		temp.push_back(N);
		temp.push_back(i);
		
		int next_num = N - i;
		int idx = 2;

		// 규칙에 따라 숫자 만들기
		while (next_num >= 0) {
			temp.push_back(next_num);
			next_num = temp[idx - 1] - temp[idx];
			idx++;
		}

		// 최대 길이면 결과값에 갱신하기
		if (max_len < temp.size()) {
			max_len = temp.size();
			result = temp;
		}
	}

	cout << max_len << endl;
	for (auto& num : result) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}