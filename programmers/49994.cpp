// 49994번, 방문 길이
// 구현, 시뮬레이션

/*
델타 이동을 할 줄 알면 쉽게 풀 수 있는 문제다.
여기서 핵심은 각 방향을 델타 인덱스로 변환해주는 건데 이때, 맵을 활용했다.
*/

#include <string>
#include <vector>
#include <map>
#define SIZE 21

using namespace std;

int solution(string dirs) {
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0));

    const int dx[] = { -1, 1, 0, 0 };
    const int dy[] = { 0, 0, -1, 1 };

    // 각 방향마다 델타 인덱스 변환 해주기
    map<char, int> delta_idx = {
        {'U', 0},
        {'D', 1},
        {'R', 2},
        {'L', 3},
    };

    int x = 10;
    int y = 10;
    int cnt = 0;

    for (auto& dir : dirs) {
        const int k = delta_idx[dir];
        const int nx = x + dx[k];
        const int ny = y + dy[k];

        if ((nx + dx[k] >= 0) && (nx + dx[k] < 21) && (ny + dy[k] >= 0) && (ny + dy[k] <= 21)) {
            x = nx + dx[k];
            y = ny + dy[k];
            // 처음 걸어본 길이면 카운트 해주기
            if (visited[nx][ny] == 0) {
                cnt++;
            }
            // 지나간 길 방문 처리
            visited[nx][ny] = 1;
        }
    }

    return cnt;
}