// 1226번, [S/W 문제해결 기본] 7일차 - 미로1
// 구현, 시뮬레이션

/*
간단한 완전탐색 문제이다.
쉽지만 기초적인 델타 이동 사용법, 재귀 사용법 등을 익힐 수 있었다.
그리고 배열을 입력받을 때 공백없이 주어지는 경우 char 를 이용하면 된다는 것을 알 수 있었다.
*/

#include <iostream>
#include <fstream>

using namespace std;

int board[16][16];
const int N = 16;
bool is_find = false;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int search(const int x, const int y) {
	// 도착 지점에 도달
	if (board[x][y] == 3) {
		is_find = true;
		return 1;
	}
	// 델타 이동
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		// 해당 칸에 이동할 수 있다면
		if (board[nx][ny] != 1) {
			// 현재 칸에 다시 방문하지 않도록 처리
			board[x][y] = 1;
			// 해당 칸에서 다시 탐색
			search(nx, ny);
		}
	}
	// 찾은 경우
	if (is_find) {
		return 1;
	}
	// 찾지 못한 경우
	else {
		return 0;
	}
}

int main()
{
	int test_case;
	const int T = 10;

	ifstream cin;
	cin.open("input.txt");

	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc;
		int answer = 0;
		cin >> tc;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				char ch;
				cin >> ch;
				board[i][j] = ch - '0';
			}
		}

		board[1][1] = 1;
		// 매 테스트케이스마다 초기화
		is_find = false;
		answer = search(1, 1);

		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}