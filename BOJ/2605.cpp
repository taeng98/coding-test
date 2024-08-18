// 2605번, 줄 세우기
// 구현

/*
삽입 메서드 활용 연습에 좋은 문제였다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; ++i) {
		int idx;
		cin >> idx;
		auto it = vec.begin();
		vec.insert(it + vec.size() - idx, i + 1);
	}

	for (auto& v : vec) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}