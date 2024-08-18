// 2628번, 종이자르기
// 정렬

/*
예전에 풀었을 때는 2차원 배열로 나타내고 각 구역을 정수값으로 구분해서 나타냈는데,
이번에는 자르고 나서 최댓값을 곱하는 형태로 풀었다.
정렬, 최댓값 요소 구하기 등을 연습할 수 있는 좋은 문제였다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> row(1, 0);
	vector<int> col(1, 0);

	int r, c;
	cin >> c >> r;
	row.push_back(r);
	col.push_back(c);

	int N;
	cin >> N;
	// 자르기 정보 입력
	for (int i = 0; i < N; ++i) {
		int direction, num;
		cin >> direction >> num;
		if (direction == 0) {
			row.push_back(num);
		}
		else {
			col.push_back(num);
		}
	}

	// row, col 정렬
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());

	vector<int> row_length;
	vector<int> col_length;
	// row, col 내 길이 정보 추출
	for (int i = 1; i < row.size(); ++i) {
		row_length.push_back(row[i] - row[i - 1]);
	}
	for (int i = 1; i < col.size(); ++i) {
		col_length.push_back(col[i] - col[i - 1]);
	}

	// row_length, col_length 내 최댓값 뽑아서 곱하기
	cout << (*max_element(row_length.begin(), row_length.end())) * (*max_element(col_length.begin(), col_length.end())) << endl;

	return 0;
}