// 68644번, 두 개 뽑아서 더하기
// 정렬

/*
중복 제거: erase(), unique() -> 정렬: sort() 를 할 수도 있지만,
셋을 이용하여 중복제거와 정렬(내림차순)을 같이 할 수 있다. 
상황에 따라서 (기존 배열을 활용 vs. 새로운 배열을 생성) 적절하게 활용해보자.
*/

#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum;
    // 두 수를 합해서 sum 셋에 삽입
    // 셋은 기본적으로 오름차순 정렬 유지
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            sum.insert(numbers[i] + numbers[j]);
        }
    } 
    // 반환 타입을 맞추기 위해 벡터로 변환
    vector<int> answer(sum.begin(), sum.end());

    return answer;
}