// 5688번, 세제곱근을 찾아라
// 완전탐색

/*
파이썬과 다르게 자료형의 범위를 고려해야해서 나름 쉽지 않았다.
그렇지만 시간이 여유롭게 주어져 완전 탐색으로도 쉽게 풀 수 있었다.
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int test_case;
	int T;

	ifstream cin;
	cin.open("input.txt");

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		unsigned long long N;
		long long answer = -1;
		cin >> N;

		for (unsigned long long i = 0; i * i * i <= N; ++i) {
			if (i * i * i == N) {
				answer = i;
				break;
			}
		}

		cout << '#' << test_case << " " << answer << endl;
	}
	return 0;
}