// 15684번, 사다리 조작
// 백트래킹, 구현

/*
처음에는, 각 세로선마다 만들 수 있는 가로선을 찾는 느낌으로 진행했는 데 한번에 2개 이상 만들어야 테케를 통과하는 경우가 있어 실패했다.
두번째로는, 계속해서 세로선을 추가하고 이때 모든 세로선이 출발과 도착지점이 같은지 확인했는데 9%에서 시간초과가 떴다.
원인은 이미 판단한 가로선을 계속해서 찾는다는 비효율에서 시간초과가 났다.
이를 해결하기 위해서는 열, 행 번호를 저장해 다음 탐색에 이용하는 것이다.
또한, 가로선을 찾았을 때 다음 열 번호를 +2 만큼 껑충 뛰어서 찾는 것이다.
이러한 두 가지 방법을 이용해 시간 초과 문제를 해결할 수 있었다.
그리고 가로선 연결 정보를 각 두 지점에 모두 표시했는데 이렇게 할 필요 없이 가로선 기준 왼쪽 열 번호에만 저장해도 괜찮을 것 같다.
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int min_link = 4;	// 3번 초과의 연결 지점은 찾지 않음
vector<vector<int>> link;

// 모든 시작 부분이 도착 부분과 열이 일치하는지 확인
bool is_completed() {
	bool completed = true;
	for (int x = 1; x < N + 1; ++x) {
		int initial_x = x;
		int step = 1;
		while (step <= H) {
			if (link[x][step]) {
				x = link[x][step];
			}
			step++;
		}
		if (initial_x != x) {
			return false;
		}
	}
	return true;
}

// 가로선을 계속해서 추가하고 최솟값 갱신
void add_link(const int cnt, const int k, int t) {
	// 가지치기
	if (min_link <= cnt) {
		return;
	}
	// 모든 지점 시작-도착 일치 => 최솟값 갱신
	if (is_completed()) {
		min_link = cnt;
		return;
	}
	// 가로선 추가
	// 중복해서 찾지 않도록 저장된 행 번호, 열 번호 이용 
	for (int j = k; j < H + 1; ++j, t = 1) {
		for (int i = t; i < N; ++i) {
			// 가로선이 없는 경우
			if (!link[i][j] && !link[i + 1][j]) {
				link[i][j] = i + 1;
				link[i + 1][j] = i;
				// 가로선을 연결한 후 2번째 후 열에서 참색
				add_link(cnt + 1, j, i + 2);
				link[i][j] = 0;
				link[i + 1][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;

	link = vector<vector<int>> (N + 1, vector<int>(H + 1, 0));

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		link[b][a] = b + 1;
		link[b + 1][a] = b;
	}
	add_link(0, 1, 1);

	if (min_link > 3) {
		min_link = -1;
	}
	cout << min_link << endl;

	return 0;
}