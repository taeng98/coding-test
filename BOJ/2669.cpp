// 2669번, 직사각형 네개의 합집합의 면적 구하기
// 구현

/*
2차원 배열을 다룰줄 알면 매우 쉬운 문제이다.
*/

#include <iostream>

using namespace std;

int matrix[101][101];

int main() {

	for (int i = 0; i < 4; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		// 해당 직사각형 부분 색칠하기
		for (int x = x1; x < x2; ++x) {
			for (int y = y1; y < y2; ++y) {
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