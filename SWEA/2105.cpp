// 2105번, [모의 SW 역량테스트] 디저트 카페
// 백트래킹

/*
종료 조건을 무지성으로 설정해서 해결하기
때로는, 머리가 아플 때는 이렇게 하는 것도 방법인 것 같다.
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int max_num = -1;
int board[20][20];
int di[] = { 1, 1, -1, -1 };
int dj[] = { 1, -1, -1, 1 };

void search(const int i, const int j, const int k, const int cnt, const int st_i, const int st_j, vector<int>& dir, vector<int>& visited, const int N) {
	//cout << i << " " << j << endl;
	if (k > 3) {
		return;
	}

	if (i == (st_i + 1) && j == (st_j - 1) && dir[0] == dir[2] && dir[1] == (dir[3] + 1) && cnt > 2) {
		if (max_num < cnt) {
			max_num = cnt;
			return;
		}
	}
	int ni = i + di[k];
	int nj = j + dj[k];
	if (ni >= 0 && ni < N && nj >= 0 && nj < N && !visited[board[ni][nj]]) {
		visited[board[ni][nj]] = 1;
		dir[k]++;
		search(ni, nj, k, cnt + 1, st_i, st_j, dir, visited, N);
		dir[k]--;
		visited[board[ni][nj]] = 0;	
	}
	search(i, j, k + 1, cnt, st_i, st_j, dir, visited, N);
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
		int N;
		cin >> N;

		max_num = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> board[i][j];
			}
		}

		// 해당 위치를 시작으로 탐색
		for (int i = 0; i < N - 2; ++i) {
			for (int j = 1; j < N - 1; ++j) {
				vector<int> dir(4, 0);
				vector<int> visited(101, 0);
				visited[board[i][j]] = 1;
				search(i, j, 0, 1, i, j, dir, visited, N);
				visited[board[i][j]] = 0;
			}
		}

		cout << '#' << test_case << " " << max_num << endl;
	}
	return 0;
}