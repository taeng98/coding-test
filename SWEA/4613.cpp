// 4613번, 러시아 국기 같은 깃발
// 완전탐색

/*
처음 문제를 봤을 때는 꽤 까다로워 보였지만,
N 값이 크지 않아 O(N^3) 으로 풀 수 있었다.
시간복잡도를 보고 일단 쉬운 방법으로 풀 수 있는지 체크하는 것이 중요한 것 같다.
*/

#include <iostream>
#include <fstream>

using namespace std;

char matrix[50][50];

int total_cnt(const int white_idx, const int blue_idx, int white_cnt[], int blue_cnt[], int red_cnt[], const int N) {
	int total = 0;
	for (int i = 0; i <= white_idx; ++i) {
		total += white_cnt[i];
	}
	for (int i = white_idx + 1; i <= blue_idx; ++i) {
		total += blue_cnt[i];
	}
	for (int i = blue_idx + 1; i < N; ++i) {
		total += red_cnt[i];
	}

	return total;
}

int main()
{
	int test_case;
	int T;

	ifstream cin;
	cin.open("input.txt");

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;

		int white_cnt[50] = { 0, };
		int blue_cnt[50] = { 0, };
		int red_cnt[50] = { 0, };

		// 문자 행렬 입력 받으면서 색상마다 바꿔야할 개수 체크
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> matrix[i][j];

				if (matrix[i][j] == 'W') {
					blue_cnt[i]++;
					red_cnt[i]++;
				}
				else if (matrix[i][j] == 'B') {
					white_cnt[i]++;
					red_cnt[i]++;
				}
				else if (matrix[i][j] == 'R') {
					white_cnt[i]++;
					blue_cnt[i]++;
				}
			}
		}
		// 흰색, 파란색 칸의 최고 인덱스 범위 지정
		int min_cnt = 5000;
		for (int i = 0; i < N - 2; ++i) {
			for (int j = i + 1; j < N - 1; ++j) {
				// 최고 인덱스를 이용하여 바꿔야 할 칸의 개수 카운트
				int temp = total_cnt(i, j, white_cnt, blue_cnt, red_cnt, N);
				// 최소값 갱신
				if (min_cnt > temp) {
					min_cnt = temp;
				}
			}
		}
		cout << "#" << test_case << " " << min_cnt << endl;
	}
	return 0;
}