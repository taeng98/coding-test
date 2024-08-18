// 2559번, 수열
// 누적 합

/*
문제 자체는 쉽지만, 데이터가 매우 크기 때문에 O(N^2) 알고리즘을 지양해야 하는 문제다.
따라서, 순회를 한번만 돌면서 최댓값을 구해야한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}

	int max_v = 0;
	for (int i = 0; i < K; ++i) {
		max_v += vec[i];
	}
	
	int temp = max_v;
	for (int i = K; i < N; ++i) {
		temp = temp + vec[i] - vec[i - K];
		if (max_v < temp) {
			max_v = temp;
		}
	}

	cout << max_v << endl;

	return 0;
}