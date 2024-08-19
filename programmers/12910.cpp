// 12910번, 나누어 떨어지는 숫자 배열
// 구현

/*
정렬 및 각 메서드를 연습할 수 있었던 문제였다.
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (auto& num : arr) {
        if (num % divisor == 0) {
            answer.push_back(num);
        }
    }
    
    if (answer.empty()) return { -1 };
    else {
        sort(answer.begin(), answer.end());
        return answer;
    }
}