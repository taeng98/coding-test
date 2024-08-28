// 10580번, 전봇대
// 정렬

/*
vector<pair> 의 형태를 다루는 게 아직 익숙하지 않은데 이를 연습할 수 있었다.
또한, vector<pair>의 경우 정렬할 때 compare 함수를 따로 만들어줘야 하는데
이를 자유재자로 사용할 수 있도록 계속 연습해야겠다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair 첫번째 요소를 기준으로 오름차순
bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> arr(N);
		for (int i = 0; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			arr[i] = make_pair(a, b);
		}

		sort(arr.begin(), arr.end(), compare);

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (arr[i].second > arr[j].second) {
					cnt++;
				}
			}
		}
		cout << '#' << test_case << " " << cnt << endl;
	}
	return 0;
}