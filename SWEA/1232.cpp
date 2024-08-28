// 1232번, [S/W 문제해결 기본] 9일차 - 사칙연산
// 트리

/*
확실히 C++ 로 풀이할 때는 자료형을 신경써서 해야하다보니 매우 까다로운것 같다.
to_string이나 stoi 같은 것을 잘 활용하는 것이 중요한 것 같다.
*/

#include <iostream>
#include <string>
#include <stack>
#define MAXN 1001

using namespace std;

struct Tree {
	string value;
	int children[2];
} tree[MAXN];

stack<string> my_stack;

string cal(string sign, const int a, const int b) {
	if (sign == "+") {
		string temp = to_string(a + b);
		return temp;
	}
	else if (sign == "-") {
		string temp = to_string(a - b);
		return temp;
	}
	else if (sign == "*") {
		string temp = to_string(a * b);
		return temp;
	}
	else if (sign == "/") {
		string temp = to_string(int(a / b));
		return temp;
	}
}

void stack_cal(string value) {
	if (value == "+" || value == "-" || value == "*" || value == "/") {
		int b = stoi(my_stack.top());
		my_stack.pop();
		int a = stoi(my_stack.top());
		my_stack.pop();
		my_stack.push(cal(value, a, b));
	}
	else {
		my_stack.push(value);
	}
}

void postorder(const int node, const int N) {
	if (node == 0) {
		return;
	}
	postorder(tree[node].children[0], N);
	postorder(tree[node].children[1], N);
	stack_cal(tree[node].value);
}

int main()
{
	int test_case;
	const int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) {
			int node;
			string value;
			cin >> node >> value;

			int children[2] = { 0, 0 };
			if (cin.get() != '\n') {
				cin >> children[0] >> children[1];
			}

			tree[node].value = value;
			tree[node].children[0] = children[0];
			tree[node].children[1] = children[1];
		}

		postorder(1, N);
		string answer = my_stack.top();

		cout << '#' << test_case << " " << answer << endl;
	}
	return 0;
}