// 42889번, 실패율
// 구현

/*
저번에 자바스크립트로 풀 때 보다 꽤 까다로웠다.
계속 파이썬으로 알고리즘 문제를 풀다보니 타입이랑 연산 과정 등의 세밀함을 놓치는 것 같다.
또한, compare를 직접 구현하는 법, pair의 활용 등 능숙하게 사용할 수 있도록 열심히 연습해야겠다.
*/

#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, int>& a, pair<float, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // 각 스테이지마다 도달한 사용자의 수 계산
    vector<int> count_stages(N + 2, 0);
    for (int i = 0; i < stages.size(); ++i) {
        count_stages[stages[i]]++;
    }

    // 각 스테이지마다 실패율 계산
    vector<pair<float, int>> fail_rate_stages(N);
    int users = stages.size();
    for (int i = 0; i < N; ++i) {
        if (users == 0) {
            fail_rate_stages[i].first = 0.0;
        }
        else {
            fail_rate_stages[i].first = float(count_stages[i + 1]) / float(users);
        }
        fail_rate_stages[i].second = i + 1;
        users -= count_stages[i + 1];
    }

    sort(fail_rate_stages.begin(), fail_rate_stages.end(), compare);

    for (int i = 0; i < N; ++i) {
        answer.push_back(fail_rate_stages[i].second);
    }

    return answer;
}
