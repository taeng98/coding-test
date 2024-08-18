// 13300번, 방 배정
// 수학

/*
자료형 신경쓰고, math.h 잘 활용하기
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int girl[7] = { 0, };
	int boy[7] = { 0, };

	for (int i = 0; i < N; ++i) {
		int S, Y;
		cin >> S >> Y;
		if (S == 0) girl[Y]++;
		else boy[Y]++;
	}

	int room = 0;
	for (int i = 1; i < 7; ++i) {
		room += ceil(girl[i] / float(K)) + ceil(boy[i] / float(K));
	}

	cout << room << endl;

	return 0;
}