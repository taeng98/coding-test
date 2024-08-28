// 64061번, 크레인 인형뽑기 게임
// 자료구조, 스택

/*
스택과 2차원 배열을 연습할 수 있는 좋은 문제였다.
*/

#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> toy_stack;
    
    // c: 열 선택
    for (int c : moves) {
        int toy = 0;
        // r: 행 선택
        for (int r = 0; r < board.size(); ++r) {
            // 해당 위치에 인형이 있다면
            if (board[r][c - 1] != 0) {
                toy = board[r][c - 1];
                board[r][c - 1] = 0;
                break;
            }
        }
        // 인형을 터트릴 수 있는 경우
        if (toy && !toy_stack.empty() && toy_stack.top() == toy) {
            answer += 2;
            toy_stack.pop();
        }
        else if (toy) {
            toy_stack.push(toy);
        }
    }

    return answer;
}