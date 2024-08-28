// 81303번, 표 편집
// 자료구조, 스택, 구현

/*
인덱스 만을 이용하여 이동을 구현하고 삭제한다는 것이 흥미로운 아이디어였다.
처음 풀었을 때는 표를 한꺼번에 생성하고 직접 이동하는 것을 구현하려 했는 데
이렇게 하는 것이 아니라 인덱스를 이용하면 좀 더 효율적으로 문제를 접근할 수 있었다.
문제를 풀면서 느끼는 것은 인덱스를 이용하면 보다 효율적인 경우가 많아서,
문제를 처음 봤을 때 인덱스를 활용할 수 없을 지 고민하는 것이 중요한 것 같다.
교재의 답을 참고하였으므로 무조건 무조건 문제를 다시한번 더 보자!!
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	// 삭제한 행을 담을 스택
	stack<int> deleted;

	// 위 아래 이동 인덱스를 담은 두 벡터
	vector<int> up(n + 2);
	vector<int> down(n + 2);
	for (int i = 0; i < n + 2; ++i) {
		up[i] = i - 1;
		down[i] = i + 1;
	}
	// k 값 보정 (+1)
	k++;

	// cmd를 앞에서 부터 순회
	for (auto& str : cmd) {
		// 삭제 연산 수행
		if (str[0] == 'C') {
			// 해당 k 삭제
			up[down[k]] = up[k];
			down[up[k]] = down[k];
			deleted.push(k);
			// 삭제 후 이동하기
			// 더 이상 내려갈 수 없는 경우
			if (down[k] == n + 1) {
				// 위로 올라가기
				k = up[k];
			}
			else {
				k = down[k];
			}
		}
		// 복구 연산 수행
		else if (str[0] == 'Z') {
			// 복구된 인덱스
			int r = deleted.top();
			deleted.pop();
			// 인덱스 복구하기
			down[up[r]] = r;
			up[down[r]] = r;
		}
		// 이동 연산 수행
		else {
			int moves = stoi(str.substr(2));
			// 위로 이동
			if (str[0] == 'U') {
				for (int i = 0; i < moves; ++i) {
					k = up[k];
				}
			}
			// 아래로 이동
			if (str[0] == 'D') {
				for (int i = 0; i < moves; ++i) {
					k = down[k];
				}
			}
		}
	}
	// 최종적으로 삭제된 행 표시하기
	string answer;
	answer.append(n, 'O');
	for (int i = 0; i < n; ++i) {
		while (!deleted.empty()) {
			int k = deleted.top();
			deleted.pop();
			k--;
			answer[k] = 'X';
		}
	}

	return answer;
}