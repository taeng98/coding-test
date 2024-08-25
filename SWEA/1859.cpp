// 1859번, 백만 장자 프로젝트
// 구현

/*
뒤에서부터 풀면 매우 쉬워지는 문제다.
*/

#include <iostream>
#include <vector>
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
		int N;
		long long int result = 0;

		cin >> N;

		vector<int> vec(N);
		for (int i = 0; i < N; ++i) {
			cin >> vec[i];
		}

		int max_price = 0;
		for (int i = N - 1; i >= 0; --i) {
			if (max_price < vec[i])
			{
				max_price = vec[i];
			}
			else
			{
				result += (max_price - vec[i]);
			}
		}
		cout << '#' << test_case << " " << result << endl;
	}
	return 0;
}