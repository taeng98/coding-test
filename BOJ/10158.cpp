// 10158번, 개미
// 수학

/*
차원을 낮춰서 생각하는 법을 알려준 좋은 문제다.
2차원 이동을 x, y로 나눠서 풀면 매우 쉽게 풀린다는 점을 알 수 있었다.
*/

#include <iostream>

using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;

	int x, y;
	cin >> x >> y;

	int t;
	cin >> t;

	// 제자리로 돌아오는 부분 고려 X
	// x, y 나눠서 이동하기
	int x1 = t % (2 * w);
	int y1 = t % (2 * h);

	int dx = 1;
	for (int i = 0; i < x1; ++i) {
		if (x + dx > w) {
			dx = -1;
		}
		else if (x + dx < 0) {
			dx = 1;
		}
		x += dx;
	}

	int dy = 1;
	for (int i = 0; i < y1; ++i) {
		if (y + dy > h) {
			dy = -1;
		}
		else if (y + dy < 0) {
			dy = 1;
		}
		y += dy;
	}

	cout << x << " " << y << endl;

	return 0;
}