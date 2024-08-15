// 2304번, 창고다각형
// 정렬

/*
기둥의 최대 위치가 정해져 있기 때문에 정적 배열로 미리 만들어 둘 수 있었다.
또한, 카운트 배열 개념을 이용하여 입력을 받으면서 바로바로 정렬을 할 수 있었고
이때, 최댓값과 최댓값의 인덱스를 저장할 수 있었다.
코드를 바로 작성하기 전에 종이에 적어보며 로직을 생각하고 이를 통해서 빠르게 어떻게 풀 지 생각할 수 있었다.
최댓값을 구하는 방법, 카운트 배열을 이용하여 정렬하는 방법을 통해서 생각보다 쉽게 문제를 해결할 수 있었다.
*/

#include <iostream>

using namespace std;

int main() {
	int storage[1001] = { 0, };

	int N;
	cin >> N;
	
	int max_H = 0;
	int max_H_idx = 0;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		storage[L] = H;
		// 최댓값과 최댓값의 인덱스 저장
		if (max_H < H) {
			max_H = H;
			max_H_idx = L;
		}
	}

	// 최댓값 기둥 먼저 합산
	int result = max_H;
	// 왼쪽에서 최댓값 기둥을 만날 때까지
	int idx = 0;
	int left_max = 0;
	while (idx < max_H_idx) {
		// 더 큰 기둥을 만날 때까지 현재 최대 높이 합산
		if (left_max < storage[idx]) {
			left_max = storage[idx];
		}
		result += left_max;
		idx++;
	}
	// 오른쪽에서 최댓값 기둥을 만날 때까지
	idx = 1000;
	int right_max = 0;
	while (idx > max_H_idx) {
		// 더 큰 기둥을 만날 때까지 현재 최대 높이 합산
		if (right_max < storage[idx]) {
			right_max = storage[idx];
		}
		result += right_max;
		idx--;
	}
	cout << result << endl;

	return 0;
}