// 2309번, 일곱 난쟁이
// 백트래킹

/*
완전탐색으로도 풀 수 있는 문제지만, 연습삼아서 백트래킹으로 풀었다.
아직 백트래킹을 능숙하게 다루지는 못하지만, 계속 연습해서 백트래킹의 고수가 되어야겠다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dwarf(9);
vector<int> dwarf_height;
bool visited[9] = { false, };
int height_total = 0;
bool find_dwarfs = false;

void printV() {
	for (auto& height : dwarf_height) {
		cout << height << endl;
	}
}

void backtracking(const int k, const int N) {
	if (find_dwarfs) {
		return;
	}

	if (height_total > 100) {
		return;
	}
	
	if (k == N && height_total == 100) {
		find_dwarfs = true;
		printV();
	}

	for (int i = 0; i < 9; ++i) {
		if (visited[i]) continue;
		height_total += dwarf[i];
		dwarf_height.push_back(dwarf[i]);
		visited[i] = true;
		backtracking(k + 1, 7);
		height_total -= dwarf[i];
		dwarf_height.pop_back();
		visited[i] = false;
	}
}

int main() {
	for (int i = 0; i < 9; ++i) {
		cin >> dwarf[i];
	}
	sort(dwarf.begin(), dwarf.end());

	backtracking(0, 7);

	return 0;
}