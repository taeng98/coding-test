// 1240번, [S / W 문제해결 응용] 1일차 - 단순 2진 암호코드
// 구현

/*
c++에서 문자열 처리하는 것이 파이썬보다 빡세지만,
c++로도 자유자재로 할 수 있을 만큼 열심히 연습해야겠다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

// 암호 코드를 숫자로 변환하는 규칙
unordered_map<string, int> password = {
		{"1011000", 0},
		{"1001100", 1},
		{"1100100", 2},
		{"1011110", 3},
		{"1100010", 4},
		{"1000110", 5},
		{"1111010", 6},
		{"1101110", 7},
		{"1110110", 8},
		{"1101000", 9}
};

// 암호문을 읽고 숫자 추출하기
vector<int> findPassword(const vector<vector<char>>& codes, const int N, const int M) {
	vector<int> nums;

	for (int i = 0; i < N; ++i) {
		for (int j = M - 1; j >= 0; --j) {
			// 열 끝에서 부터 찾아서 '1' 을 발견하면
			if (codes[i][j] == '1') {
				string temp = "";
				for (int k = 1; k <= 56; ++k) {
					temp += codes[i][j - k + 1];
					// 7번 돌때마다 숫자 추출
					if (k % 7 == 0) {
						nums.push_back(password[temp]);
						// 새로운 숫자를 추출하기 위해 리셋
						temp = "";
					}
				}
				return nums;
			}
		}
	}
}

int main()
{
	int test_case;
	int T;

	ifstream cin;
	cin.open("input.txt");

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;

		vector<vector<char>> codes(N, vector<char>(M));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> codes[i][j];
			}
		}

		vector<int> nums = findPassword(codes, N, M);

		int answer = 0;
		int temp = (nums[7] + nums[5] + nums[3] + nums[1]) * 3 + (nums[6] + nums[4] + nums[2] + nums[0]);
		// 올바른 암호코드 인지 확인
		if (temp % 10 == 0) {
			for (auto& num : nums) {
				answer += num;
			}
		}
		
		cout << '#' << test_case << " " << answer << endl;
	}
	return 0;
}