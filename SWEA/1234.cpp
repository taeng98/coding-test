// 1234번, [S/W 문제해결 기본] 10일차 - 비밀번호
// 자료구조, 스택

/*
스택의 개념을 연습할 수 있는 좋은 문제다.
마지막 출력 때문에 벡터를 이용해 스택을 구현하여 사용하였다.
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int test_case;
	const int T = 10;

	ifstream cin;
	cin.open("input.txt");

	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		vector<int> num_vec;

		for (int i = 0; i < N; ++i) {
			char ch;
			cin >> ch;
			int num = ch - '0';
			if (num_vec.empty() || num_vec.back() != num) {
				num_vec.push_back(num);
			}
			else {
				num_vec.pop_back();
			}
		}

		cout << "#" << test_case << " ";
		for (auto& num : num_vec) {
			cout << num;
		}
		cout << endl;
	}
	return 0;
}