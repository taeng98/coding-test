// 12100번, 2048 (Easy)
// 구현, 백트래킹

/*
빡구현 문제라 역시 쉽지 않았다.
모든 경우의 수를 구할 때 첫번째 숫자를 고정하는 실수를 했다.
이를 염두해서 항상 첫번째 숫자가 고정되어있는지 아니면 고정하지 않고 도는지 잘 생각해야겠다.
또한, 내가 풀때는 스택과 큐를 이용해서 이동 정보를 업데이트 헀는데 이렇게 비효율적으로 하지말고
최대한 효율적으로 짤 수 없을 지 고민하는 것이 중요한 것 같다.
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int max_v = 0;

// 이동했을 때 결과 업데이트하기
void move_update(const int dir, vector<vector<int>>& board) {
    if (dir == 0) { // 위로 이동
        // 각 열마다 이동시키기
        for (int col = 0; col < N; ++col) {
            // 위쪽부터 숫자를 채울 임시 배열
            vector<int> temp(N, 0);
            // index: temp의 인덱스, last: 마지막 숫자 저장
            int index = 0, last = 0;
            for (int row = 0; row < N; ++row) {
                // 칸이 비어있는 경우
                if (board[row][col] == 0) continue;
                // 마지막 숫자가 비어있는 경우
                if (last == 0) {
                    last = board[row][col];
                }
                // 마지막 숫자와 현재 숫자가 같은 경우
                else if (last == board[row][col]) {
                    // 임시 배열에 채우고 마지막 숫자 정보 비우기
                    temp[index++] = last * 2;
                    last = 0;
                }
                // 마지막 숫자와 현재 숫자가 다른 경우
                else {
                    // 마지막 숫자를 임시 배열에 넣고 마지막 숫자 다시 업데이트
                    temp[index++] = last;
                    last = board[row][col];
                }
            }
            // 마지막 남은 숫자까지 임시 배열에 넣기
            if (last != 0) temp[index] = last;
            // 임시 배열에 있는 숫자를 위쪽부터 넣어주기
            for (int row = 0; row < N; ++row) {
                board[row][col] = temp[row];
                // 최댓값 업데이트
                max_v = max(max_v, board[row][col]);
            }
        }
    }
    else if (dir == 1) { // 아래로 이동
        for (int col = 0; col < N; ++col) {
            vector<int> temp(N, 0);
            int index = N - 1, last = 0;
            for (int row = N - 1; row >= 0; --row) {
                if (board[row][col] == 0) continue;
                if (last == 0) {
                    last = board[row][col];
                }
                else if (last == board[row][col]) {
                    temp[index--] = last * 2;
                    last = 0;
                }
                else {
                    temp[index--] = last;
                    last = board[row][col];
                }
            }
            if (last != 0) temp[index] = last;
            for (int row = N - 1; row >= 0; --row) {
                board[row][col] = temp[row];
                max_v = max(max_v, board[row][col]);
            }
        }
    }
    else if (dir == 2) { // 오른쪽으로 이동
        for (int row = 0; row < N; ++row) {
            vector<int> temp(N, 0);
            int index = N - 1, last = 0;
            for (int col = N - 1; col >= 0; --col) {
                if (board[row][col] == 0) continue;
                if (last == 0) {
                    last = board[row][col];
                }
                else if (last == board[row][col]) {
                    temp[index--] = last * 2;
                    last = 0;
                }
                else {
                    temp[index--] = last;
                    last = board[row][col];
                }
            }
            if (last != 0) temp[index] = last;
            for (int col = N - 1; col >= 0; --col) {
                board[row][col] = temp[col];
                max_v = max(max_v, board[row][col]);
            }
        }
    }
    else if (dir == 3) { // 왼쪽으로 이동
        for (int row = 0; row < N; ++row) {
            vector<int> temp(N, 0);
            int index = 0, last = 0;
            for (int col = 0; col < N; ++col) {
                if (board[row][col] == 0) continue;
                if (last == 0) {
                    last = board[row][col];
                }
                else if (last == board[row][col]) {
                    temp[index++] = last * 2;
                    last = 0;
                }
                else {
                    temp[index++] = last;
                    last = board[row][col];
                }
            }
            if (last != 0) temp[index] = last;
            for (int col = 0; col < N; ++col) {
                board[row][col] = temp[col];
                max_v = max(max_v, board[row][col]);
            }
        }
    }
}

void move(const int cnt, vector<vector<int>> board) {
    if (cnt == 5) { // 최대 5번 이동한 후 종료
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        vector<vector<int>> new_board = board;
        move_update(dir, new_board);
        move(cnt + 1, new_board);
    }
}

int main() {
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    // 보드 초기 상태 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 방향으로 시도해 보기
    // 처음 숫자를 0~3 까지 탐색하기
    for (int dir = 0; dir < 4; ++dir) {
        vector<vector<int>> new_board = board;
        move_update(dir, new_board);
        move(1, new_board);
    }

    cout << max_v << endl;

    return 0;
}
