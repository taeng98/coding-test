// 2491번, 수열
// 구현

/*
연속된 수의 개수를 체크, 최댓값 저장하기만 구현하면 되는 문제라 쉬웠다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}

	int ascending_count = 1;
	int descending_count = 1;
	int max_count = 1;
	// 오름차순, 내림차순 검사
	for (int i = 1; i < N; ++i) {
		if (vec[i] >= vec[i - 1]) {
			ascending_count++;
		}
		else {
			ascending_count = 1;
		}

		if (vec[i] <= vec[i - 1]) {
			descending_count++;
		}
		else {
			descending_count = 1;
		}

		if (max_count < ascending_count) {
			max_count = ascending_count;
		}

		if (max_count < descending_count) {
			max_count = descending_count;
		}
	}

	cout << max_count << endl;

	return 0;
}