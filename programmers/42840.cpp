// 42840번, 모의고사
// 구현

/*
- 최댓값을 구할 때 max_element 이용하기
- 모듈러 연산을 이용해서 패턴 반복하기
두 부분을 꼭 기억해서 나중에도 활용하자.
교재의 답안 코드처럼 답안마다 한번에 세 명의 학생을 체점하는 방법도 있음을 생각하자.
*/

// 교재 답안 코드
/*
for(int i=0; i<answers.size(); i++) {
        if(answers[i] == firstPattern[i % firstPattern.size()]) matchCnt[0]++;
        if(answers[i] == secondPattern[i % secondPattern.size()]) matchCnt[1]++;
        if(answers[i] == thirdPattern[i % thirdPattern.size()]) matchCnt[2]++;
    }
*/

#include <vector>
#include <algorithm>

using namespace std;

// 각 수포자들의 패턴
vector<int> first_pattern = { 1, 2, 3, 4, 5 };
vector<int> second_pattern = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> third_pattern = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    // 각 수포자들의 점수
    vector<int> scores = { 0, 0, 0 };

    // 각 수포자들마다 검사
    for (int i = 0; i < 3; ++i) {
        vector<int> pattern;
        if (i == 0) pattern = first_pattern;
        else if (i == 1) pattern = second_pattern;
        else pattern = third_pattern;

        // 답안 검사하기
        for (int j = 0; j < answers.size(); ++j) {
            if (answers[j] == pattern[j % pattern.size()]) {
                scores[i]++;
            }
        }
    }

    // 최대 점수와 동일한 학생들을 찾기
    vector<int> max_students;
    for (int i = 0; i < 3; ++i) {
        if (*max_element(scores.begin(), scores.end()) == scores[i]) {
            max_students.push_back(i + 1);
        }
    }

    return max_students;
}