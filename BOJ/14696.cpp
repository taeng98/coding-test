// 14696번, 딱지놀이
// 정렬

/*
예전에는 정렬을 이용했는데, 카운트 배열을 만들어서 풀면 더욱 쉽게 풀린다.
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int A, B;
		int A_cards[5] = { 0, };
		int B_cards[5] = { 0, };
		
		cin >> A;
		for (int i = 0; i < A; ++i) {
			int temp;
			cin >> temp;
			A_cards[temp]++;
		}

		cin >> B;
		for (int i = 0; i < B; ++i) {
			int temp;
			cin >> temp;
			B_cards[temp]++;
		}

		for (int i = 4; i >= 0; --i) {
			if (A_cards[i] > B_cards[i]) {
				cout << 'A' << endl;
				break;
			}
			else if (A_cards[i] < B_cards[i]) {
				cout << 'B' << endl;
				break;
			}
			else if (i == 0) {
				cout << 'D' << endl;
				break;
			}
		}
	}

	return 0;
}