// 2042번, 구간 합 구하기
// 자료구조, 세그먼트 트리

/*
각 인덱스마다 가장 왼쪽에 있는 1의 위치를 알면 이를 가지고 트리를 구성할 수 있다.
lsb(1) = 1 => 1
lsb(2) = 2 => 1~2
lsb(3) = 1 => 3
lsb(4) = 4 => 1~4
...
lsb(8) = 8 => 1~8
이때, update(1) 을 수행하면 1을 포함한 구간(idx: 1->2->4->8) 마다 해당 값을 업데이트 해준다.
(1+lsb(1) = 2 -> 2+lsb(2) = 4 -> 4+lsb(4) = 8)
*/

#include <iostream>
#define MAXN 1000001

using namespace std;

long long num_arr[MAXN] = { 0, };
long long binary_idx_tree[MAXN] = { 0, };
int lsb[MAXN];

// 업데이트
void update(int i, const long long dif, const int N) {
	while (i <= N) {
		binary_idx_tree[i] += dif;
		i += lsb[i];
	}
}
// 구간합
long long prefixSum(int i, const int N) {
	long long total = 0;
	while (i > 0) {
		total += binary_idx_tree[i];
		i -= lsb[i];
	}
	return total;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	// 1부터 N까지 인덱스마다 가장 왼쪽에 위치한 1의 비트 위치를 담은 배열
	for (int i = 1; i < N + 1; ++i) {
		lsb[i] = (i & (-i));
	}
	// 숫자를 담은 배열 입력 & 바이너리 인덱스 트리 채우기
	for (int i = 1; i < N + 1; ++i) {
		cin >> num_arr[i];
		update(i, num_arr[i], N);
	}
	// 업데이트 수행 또는 구간합 계산
	for (int i = 0; i < M + K; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		// 업데이트 수행
		if (a == 1) {
			update(b, c - num_arr[b], N);
			num_arr[b] = c;
		}
		// 구간합 계산
		else {
			cout << prefixSum(c, N) - prefixSum(b - 1, N) << endl;
		}
	}
	return 0;
}