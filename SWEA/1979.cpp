// 1979번, 어디에 단어가 들어갈 수 있을까
// 구현

/*
값이나 크기가 변하지 않는 보드이기 때문에 정적 배열로 선언했다.
*/

#include <iostream>
#include <fstream>

using namespace std;

int board[15][15] = { -1, };

int main()
{
	int test_case;
	int T;

	ifstream cin;
	cin.open("input.txt");

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N >> K;
		
		// 배열 입력
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		int result = 0;
		int streak = 0;

		// 행마다 체크
		for (int i = 0; i < N; i++)
		{
			streak = 0;
			for (int j = 0; j < N; j++)
			{
				// 검은색 부분일 때
				if (board[i][j] == 0)
				{
					// 연속된 부분이 K 만큼이면
					if (streak == K)
					{
						result++;
					}
					streak = 0;
				}
				// 흰색 부분일 때
				else
				{
					streak++;
				}
				// 마지막 열에 도착했을 때
				if (j == (N - 1))
				{
					if (streak == K)
					{
						result++;
					}
				}
			}
		}
		// 열마다 체크
		for (int i = 0; i < N; i++)
		{
			streak = 0;
			for (int j = 0; j < N; j++)
			{
				// 검은색 부분일 때
				if (board[j][i] == 0)
				{
					// 연속된 부분이 K 만큼이면
					if (streak == K)
					{
						result++;
					}
					streak = 0;
				}
				// 흰색 부분일 때
				else
				{
					streak++;
				}
				// 마지막 행에 도착했을 때
				if (j == (N - 1))
				{
					// 연속된 부분이 K 만큼이면
					if (streak == K)
					{
						result++;
					}
				}
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}