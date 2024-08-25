// 1860번, 진기의 최고급 붕어빵
// 구현

/*
카운트 배열을 이용하는 법, 해당 초까지 만들 수 있는 붕어빵의 총 개수를 간단하게 계산하는 법
이러한 것들을 이용하여 쉽게 문제를 풀 수 있었다.
*/

#include <iostream>
#include <string>
#include <fstream>
#define TIME 11112

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
		int N, M, K;
		cin >> N >> M >> K;

		int customer_cnt[TIME] = { 0, };
		// 카운트 배열을 이용하여 시간 마다 고객 수 카운트
		for (int i = 0; i < N; ++i) {
			int t;
			cin >> t;
			customer_cnt[t]++;
		}

		int total_customer = 0;
		string answer = "Possible";
		for (int t = 0; t < TIME; ++t) {
			// 총 고객을 누적
			total_customer += customer_cnt[t];
			// 누적된 고객에게 붕어빵을 만들 수 없다면
			if ((t / M * K) < total_customer) {
				answer = "Impossible";
				break;
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}