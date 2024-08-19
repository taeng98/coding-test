// 12906번, 같은 숫자는 싫어
// 구현

/*
벡터의 각 메서드를 활용할 수 있었다.
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (auto& num : arr) {
        if (answer.empty() || answer.back() != num) {
            answer.push_back(num);
        }
        else {
            continue;
        }
    }
    return answer;
}