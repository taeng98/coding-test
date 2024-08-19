// 12973번, 짝지어 제거하기
// 자료구조, 구현

/*
스택의 개념 이해에 도움이 되는 문제이다.
*/

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> my_stack;

    for (auto& ch : s) {
        // 스택이 비어있으면 무조건 push
        if (my_stack.empty()) {
            my_stack.push(ch);
        }
        else {
            // 스택 맨 위 문자와 현재 문자가 같다면 pop
            if (my_stack.top() == ch) {
                my_stack.pop();
            }
            else {
                my_stack.push(ch);
            }
        }
    }

    return my_stack.empty();
}