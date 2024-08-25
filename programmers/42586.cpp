// 42586번, 기능개발
// 자료구조, 큐

/*
큐를 연습해볼 수 있는 문제다.
*/

#include <vector>
#include <math.h>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    int N = progresses.size();
    
    for (int i = 0; i < N; ++i) {
        q.push(int(ceil(double(100 - progresses[i]) / speeds[i])));
    }
    
    int max = q.front();
    q.pop();
    int cnt = 1;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (max < num) {
            answer.push_back(cnt);
            cnt = 1;
            max = num;
        }
        else {
            cnt++;
        }
    }
    if (cnt) {
        answer.push_back(cnt);
    }
    
    return answer;
}