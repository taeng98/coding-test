// 10175번, 자리배정
// 구현

/*
델타 이동을 연습할 수 있는 좋은 문제다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int C, R, K;
	cin >> C >> R ;
	cin >> K;

	if (K > C * R) {
		cout << '0' << endl;
	}
	else {
		vector<vector<int>> matrix(C, vector<int>(R, 0));
		int x = 0;
		int y = 0;
		matrix[x][y] = -1;
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		int k = 0;
		int cnt = 1;
		while (cnt < K) {
			k %= 4;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R && matrix[nx][ny] != -1) {
				// 지나온 길 체크
				matrix[nx][ny] = -1;
				x = nx;
				y = ny;
				cnt++;
			}
			else {
				k++;
			}
		}
		cout << x + 1 << " " << y + 1 << endl;
	}

	return 0;
}