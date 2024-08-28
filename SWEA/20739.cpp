// 20739번, 고대 유적 2
// 구현

/*
2차원 행렬 연습 문제다.
*/

#include <iostream>

using namespace std;

int matrix[101][101];

int main() {
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;

		// N*M 행렬 입력
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> matrix[i][j];
			}
		}
		int max_len = 0;
		// 행에 따라 순회
		for (int i = 0; i < N; ++i) {
			int temp = 0;
			for (int j = 0; j < M; ++j) {
				// 구조물이 있다면
				if (matrix[i][j]) {
					temp++;
				}
				// 구조물이 없거나 마지막 열에 왔으면
				if (!matrix[i][j] || j == M - 1) {
					// 최댓값 갱신
					if (max_len < temp) {
						max_len = temp;
					}
					temp = 0;
				}
			}
		}
		// 열에 따라 순회
		for (int i = 0; i < M; ++i) {
			int temp = 0;
			for (int j = 0; j < N; ++j) {
				// 구조물이 있다면
				if (matrix[j][i]) {
					temp++;
				}
				// 구조물이 없거나 마지막 열에 왔으면
				if (!matrix[j][i] || j == N - 1) {
					// 최댓값 갱신
					if (max_len < temp) {
						max_len = temp;
					}
					temp = 0;
				}
			}
		}
		if (max_len < 2) {
			max_len = 0;
		}
		cout << '#' << test_case << " " << max_len << endl;
	}
	return 0;
}