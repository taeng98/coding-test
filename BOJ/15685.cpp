// 15685번, 드래곤 커브
// 구현, 시뮬레이션

/*
구현, 시뮬레이션 문제를 풀 때 핵심은 설명을 보고 그대로 규칙을 찾아보는 것이다.
이번 문제도 세대가 올라갈 때 연결 시키는 방법을 방향을 바꾸면서 이동하는 것처럼 생각해서 쉽게 풀 수 있었다.
*/

#include <iostream>
#include <vector>


int matrix[201][201] = { 0, };
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int n = 0; n < N; ++n) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		x += 100;
		y += 100;

		vector<int> dir;

		// 0세대 세팅
		matrix[x][y] = 1;
		dir.push_back(d);
		if (d == 0) {
			x++;
		}
		else if (d == 1) {
			y--;
		}
		else if (d == 2) {
			x--;
		}
		else if (d == 3) {
			y++;
		}
		matrix[x][y] = 1;

		int i = 0;
		while (i < g) {
			// 방향을 벡터에 저장하고 맨 끝에서 부터 앞까지 추출하며 반시계 방향으로 돌려 전진
			for (int k = dir.size() - 1; k >= 0; --k) {
				d = dir[k];
				x += dx[d];
				y += dy[d];
				matrix[x][y] = 1;
				int temp = (d + 1) % 4;
				dir.push_back(temp);
			}
			i++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 200; ++i) {
		for (int j = 0; j < 200; ++j) {
			if (matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1] && matrix[i + 1][j + 1]) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}