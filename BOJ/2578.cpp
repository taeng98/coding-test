// 2578번, 빙고
// 구현

/*
2차원 배열 인덱스를 다루는데 좋은 문제다.
*/

#include <iostream>

using namespace std;

int matrix[5][5];

int bingoCheck() {
	int bingo_cnt = 0;
	// 행, 열 검사
	for (int i = 0; i < 5; ++i) {
		int row_check = 0;
		int col_check = 0;
		for (int j = 0; j < 5; ++j) {
			if (matrix[i][j] == -1) {
				row_check++;
			}
			if (matrix[j][i] == -1) {
				col_check++;
			}
		}
		if (row_check == 5) bingo_cnt++;
		if (col_check == 5) bingo_cnt++;
	}
	// 대각선 검사
	int down_check = 0;
	int up_check = 0;
	for (int i = 0; i < 5; ++i) {
		if (matrix[i][i] == -1) {
			down_check++;
		}
		if (matrix[5 - 1 - i][i] == -1) {
			up_check++;
		}
	}
	if (down_check == 5) bingo_cnt++;
	if (up_check == 5) bingo_cnt++;

	return bingo_cnt;
}

int main()
{
	// 빙고 판 입력
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> matrix[i][j];
		}
	}

	// 빙고 판 채우고 빙고 개수 체크하기
	for (int i = 0; i < 25; ++i) {
		int num;
		cin >> num;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (num == matrix[i][j]) {
					matrix[i][j] = -1;
				}
			}
		}

		if (bingoCheck() >= 3) {
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}