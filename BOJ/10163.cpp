// 10163번, 색종이
// 구현

/*
2차원 배열을 연습하는 문제다.
*/

#include <iostream>

using namespace std;

int matrix[1001][1001];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i < N + 1; ++i) {
		int x1, y1, dx, dy;
		cin >> x1 >> y1 >> dx >> dy;
		for (int x = x1; x < x1 + dx; ++x) {
			for (int y = y1; y < y1 + dy; ++y) {
				matrix[x][y] = i;

			}
		}
	}

	for (int i = 1; i < N + 1; ++i) {
		int cnt = 0;
		for (int x = 0; x < 1001; ++x) {
			for (int y = 0; y < 1001; ++y) {
				if (matrix[x][y] == i) cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}