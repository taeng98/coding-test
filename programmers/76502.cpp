// 76502번, 괄호 회전하기
// 자료구조, 구현

/*
스택을 이용하면 손쉽게 풀 수 있는 문제다.
왼쪽으로 회전하는 부분은 모듈러 연산을 이용하여 구현하고,
스택을 이용하여 알맞은 괄호의 짝을 맞추도록 구현하였다.
*/

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;
	
	const int N = s.size();

	// i: 기준 인덱스 이동
	for (int i = 0; i < N; ++i) {
		stack<char> st;
		bool is_correct = true;
		// j: i번째 부터 이동할 인덱스
		for (int j = 0; j < N; ++j) {
			// 모듈러 연산을 이용하여 회전
			int idx = (i + j) % N;
			// 여는 괄호의 경우 무조건 스택에 push
			if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
				st.push(s[idx]);
			}
			// 닫는 괄호의 경우
			else if (s[idx] == ')') {
				// 스택이 비어있으면 짝이 맞지 않음
				if (st.empty()) {
					is_correct = false;
					break;
				}
				// 올바른 짝을 찾으면 스택에서 pop
				else if (st.top() == '(') {
					st.pop();
					continue;
				}
				// 나머지 경우 모두 짝이 맞지 않음
				else {
					is_correct = false;
					break;
				}
			}
			else if (s[idx] == '}') {
				if (st.empty()) {
					is_correct = false;
					break;
				}
				else if (st.top() == '{') {
					st.pop();
					continue;
				}
				else {
					is_correct = false;
					break;
				}
			}
			else if (s[idx] == ']') {
				if (st.empty()) {
					is_correct = false;
					break;
				}
				else if (st.top() == '[') {
					st.pop();
					continue;
				}
				else {
					is_correct = false;
					break;
				}
			}
		}
		// 최종적으로 스택이 비어있고 짝이 모두 맞는 경우
		if (st.empty() && is_correct) {
			answer++;
		}
	}
	
	return answer;
}