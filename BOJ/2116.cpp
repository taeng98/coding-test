// 2116번, 주사위 쌓기
// 구현

/*
문법이 매우매우 헷갈렸다.
처음 돌렸을 때 out of bounds 가 나와서 vector size 문제 인줄 알았는데,
알고보니까 주사위를 6까지만 돌려야 하는데 자꾸 N 값을 넣어서 에러가 나오는거였다.
에러가 났을 때 for 문을 알맞게 인덱스를 돌렸는지 확인하는 것을 꼭꼭 명심해야겠다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix(10000, vector<int>(6, 0));
int op[6] = { 5, 3, 4, 1, 2, 0 };

// 주사위 반대 면의 값을 반환
int findOp(const vector<int> row, const int item) {
	return row[op[find(row.begin(), row.end(), item) - row.begin()]];;
}

// 주사위 위쪽, 아래쪽 면을 제외한 값 중에 최댓값 찾기
int findMax(const vector<int> row, const int top, const int down) {
	int max_v = -1;
	for (auto& item : row) {
		if (max_v < item && item != top && item != down) {
			max_v = item;
		}
	}
	return max_v;
}

int main()
{
	int N;
	cin >> N;

	vector<int> first_dice(6, 0);

	for (int i = 0; i < 6; i++) {
		cin >> first_dice[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> matrix[i][j];
		}
	}

	int max_num = 0;

	// 첫번째 주사위에서 면 하나 선택
	for (int i = 0; i < 6; i++) {
		int temp = 0;
		int top = first_dice[i];

		// 첫번째 주사위에서 최댓값 찾아서 더해주기
		temp += findMax(first_dice, top, findOp(first_dice, top));

		// 두번째 주사위부터 윗면 아랫면을 연결해주고 옆면 중에서 최댓값 더해주기
		for (int j = 0; j < N - 1; j++) {
			vector<int> row = matrix[j];
			int down = top;
			top = findOp(row, down);
			temp += findMax(row, top, down);
		}

		// 최종 완성된 주사위 기둥의 합이 최댓값이면 갱신하기
		if (max_num < temp) {
			max_num = temp;
		}
	}
	cout << max_num << endl;

	return 0;
}