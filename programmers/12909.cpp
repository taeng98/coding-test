// 12909번, 올바른 괄호
// 자료구조, 스택

/*
스택의 개념을 익히는 데 좋은 문제였다.
*/

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> my_stack;

    for (auto& ch : s) {

        if (ch == '(') {
            my_stack.push(ch);
        }
        else {
            if (my_stack.empty() || my_stack.top() == ')') {
                return false;
            }
            else {
                my_stack.pop();
            }
        }
    }

    return my_stack.empty();
}