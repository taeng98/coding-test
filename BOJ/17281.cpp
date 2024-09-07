// 17281번, ⚾
// 구현, 완전탐색, 순열

/*
<연습한 것>
1. 순열을 재귀로 구현
2. 시간복잡도 계산 (8!*50 -> 1초안에 가능)
<리뷰>
야구 규칙을 차근차근 꼼꼼하게 구현하는 게 중요한 것 같다.
이 문제 말고도 다른 구현 문제에 있어 문제의 조건을 꼼꼼하게 파악하고 코드를 작성해야겠다.
*/

#include <iostream>

using namespace std;

// N: 이닝 수
// batting_order: 배팅 순서
// player_batting: 이닝별 플레이어 배팅 기댓값
// max_score: 최종 점수 최댓값
int N;
int batting_order[9];
int player_batting[50][9];
int max_score = 0;
bool visited[9];

int calScore() {
	// score: 점수
	// inning: 현재 이닝
	// num: 타자 번호
	// base[4]: 베이스 상태
	// out: 아웃 상태
	int score = 0;
	int inning = 0;
	int num = 0;
	int base[4] = { 0 };
	int out = 0;
	while (inning < N) {
		// 모듈러 연산을 이용해 타자 번호 반복
		num %= 9;
		// hit: 현재 타자의 기댓값 (아웃, 1루타, 2루타, 3루타, 홈런)
		int hit = player_batting[inning][batting_order[num]];
		// 아웃인 경우
		if (hit == 0) {
			out++;
			// 3 아웃의 경우
			if (out == 3) {
				out = 0;
				// 베이스 리셋
				for (int i = 0; i < 4; ++i) {
					base[i] = 0;
				}
				inning++;
			}
		}
		else {
			bool is_find_hitter_pos = false;
			// 안타로 인한 진루
			for (int i = 0; i < 4; ++i) {
				// 타자의 위치 정해주기
				if (base[i] == 0 && !is_find_hitter_pos) {
					base[i] = hit;
					is_find_hitter_pos = true;
				}
				// 베이스에 차있는 곳 진루 시키기
				else if (base[i] > 0) {
					base[i] += hit;
				}
				// 점수 계산
				if (base[i] > 3) {
					base[i] = 0;
					score++;
				}
			}
		}
		num++;
	}
	return score;
}


void permutation(const int k) {
	// 4번 타자는 고정
	// 인덱스 3을 건너뛰고 재귀 호출
	if (k == 3) {
		permutation(k + 1);
		return;
	}

	// 점수 계산 및 최대 점수 업데이트 
	if (k == 9) {
		// 점수 수행
		int score = calScore();
		if (max_score < score) {
			max_score = score;
		}
		return;
	}

	for (int i = 1; i < 9; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			batting_order[k] = i;
			permutation(k + 1);
			visited[i] = false;
		}
	}
}


int main() {
	cin >> N;

	// 이닝 별 선수 기대 배팅 입력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> player_batting[i][j];
		}
	}

	// 순열을 통해 타선 결정
	// 1번 선수 -> 4번 타자로 고정
	visited[0] = true;
	batting_order[3] = 0;
	permutation(0);

	cout << max_score << endl;
	
	return 0;
}