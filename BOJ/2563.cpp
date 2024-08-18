// 2563번, 색종이
// 구현

/*
2차원 배열을 사용하면 쉽게 해결되는 문제였다.
*/

#include <iostream>

using namespace std;

int matrix[101][101] = {};

int main() {
	int N;
	cin >> N;

	// 해당 색종이 부분 1로 색칠
	for (int i = 0; i < N; ++i) {
		int x1, y1;
		cin >> x1 >> y1;

		for (int x = x1; x < x1 + 10; ++x) {
			for (int y = y1; y < y1 + 10; ++y) {
				matrix[x][y] = 1;
			}
		}
	}

	// 1로 색칠된 부분 카운트하기
	int cnt = 0;
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			if (matrix[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}