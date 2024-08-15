// 2564번, 경비원
// 구현

/*
오랜만에 C++로 문제를 풀려니까 문법이 기억이 안나 매우 힘들었다.
라이브러리부터 벡터 사용법까지 오랜만에 하니 익숙하지 않아서
C++로 자유자재로 문제를 풀려면 다시 기초부터 다져놔야겠다.
이번 문제는 최단거리를 구하는 문제였는데,
기준점을 잡아서 거리를 계산하니 굳이 2차원 인덱스로 생각할 필요가 없어 더 쉽게 생각할 수 있었다.
문제에서 제시된 방법 그대로 구현하는 것도 중요한 능력이지만,
문제를 단순화시켜서 생각하는 방법도 꽤 중요한 것 같아 이점을 중요시 해야겠다.
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
    int width, height, N;
    cin >> width >> height;
    cin >> N;
    vector<vector<int>> dis_info(N + 1, vector<int>(2, 0));
    // dis1: (0,0) 부터의 거리 (반시계 방향으로 한 칸 갈때마다 +1)
    // dis2: (width, height) 부터의 거리 (시계 방향으로 한 칸 갈때마다 +1)
    for (int i = 0; i < N + 1; i++) {
        int dir, dis;
        cin >> dir >> dis;
        int dis1, dis2;
        if (dir == 1) {
            dis1 = height + dis;
            dis2 = width - dis;
        }
        else if (dir == 2) {
            dis1 = -dis;
            dis2 = -(width + height - dis);
        }
        else if (dir == 3) {
            dis1 = height - dis;
            dis2 = width + dis;
        }
        else if (dir == 4) {
            dis1 = -(width + height - dis);
            dis2 = -dis;
        }
        dis_info[i][0] = dis1;
        dis_info[i][1] = dis2;
    }
    // 각 경로마다 최단 거리 구하기
    // dis1, dis2 기준으로 두 지점의 거리 중에서 작은 값을 선택
    int total_min_dis = 0;
    for (int i = 0; i < N; i++) {
        total_min_dis += min(abs(dis_info[i][0] - dis_info[N][0]), abs(dis_info[i][1] - dis_info[N][1]));
    }
    cout << total_min_dis << endl;

    return 0;
}