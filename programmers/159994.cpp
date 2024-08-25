// 159994번, 카드 뭉치
// 자료구조, 큐

/*
큐를 연습해볼 수 있는 문제다.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> q1;
    queue<string> q2;
    
    for (auto& str: cards1) {
        q1.push(str);
    }
    
    for (auto& str: cards2) {
        q2.push(str);
    }
    
    bool is_check = true;
    for (auto& str: goal) {
        if (str == q1.front()) {
            q1.pop();
            continue;
        }
        else if (str == q2.front()) {
            q2.pop();
            continue;
        }
        else {
            is_check = false;
            break;
        }
    }
    
    string answer = "";
    if (is_check) {
        answer = "Yes";
    }
    else {
        answer = "No";
    }
    
    return answer;
}