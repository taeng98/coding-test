// 17070번, 파이프 옮기기 1
// 백트래킹

/*
N이 작고 시간 제한이 넉넉해 백트래킹으로도 쉽게 풀 수 있었다.
C++는 각 파이프별로 구분해서 배열을 만들어놔야 하는게 조금 귀찮긴하다.
*/

#include <iostream>

using namespace std;

int pipe_0[2][3] = { {0, 1, 0}, {1, 1, 2} };
int pipe_1[2][3] = { {1, 0, 1}, {1, 1, 2} };
int pipe_2[3][3] = { {0, 1, 0}, {1, 0, 1}, {1, 1, 2} };
int answer = 0;
int wall[16][16];

void pipe_search(const int x, const int y, const int pipe_num, const int N) {
	if (x == N - 1 && y == N - 1) {
		answer++;
		return;
	}

	if (pipe_num == 0) {
		for (auto& pipe : pipe_0) {
			int nx, ny;
			nx = x + pipe[0];
			ny = y + pipe[1];
			if (nx < N && ny < N && !wall[nx][ny]) {
				if (pipe[2] == 2 && (wall[nx][ny - 1] || wall[nx - 1][ny])) {
					continue;
				}
				pipe_search(nx, ny, pipe[2], N);
				nx = x - pipe[0];
				ny = y - pipe[1];
			}
		}
	}
	else if (pipe_num == 1) {
		for (auto& pipe : pipe_1) {
			int nx, ny;
			nx = x + pipe[0];
			ny = y + pipe[1];
			if (nx < N && ny < N && !wall[nx][ny]) {
				if (pipe[2] == 2 && (wall[nx][ny - 1] || wall[nx - 1][ny])) {
					continue;
				}
				pipe_search(nx, ny, pipe[2], N);
				nx = x - pipe[0];
				ny = y - pipe[1];
			}
		}
	}
	else if (pipe_num == 2) {
		for (auto& pipe : pipe_2) {
			int nx, ny;
			nx = x + pipe[0];
			ny = y + pipe[1];
			if (nx < N && ny < N && !wall[nx][ny]) {
				if (pipe[2] == 2 && (wall[nx][ny - 1] || wall[nx - 1][ny])) {
					continue;
				}
				pipe_search(nx, ny, pipe[2], N);
				nx = x - pipe[0];
				ny = y - pipe[1];
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> wall[i][j];
		}
	}

	pipe_search(0, 1, 0, N);

	cout << answer << endl;

	return 0;
}