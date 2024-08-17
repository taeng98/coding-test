// 12949번, 행렬의 곱셈
// 구현

/*
행렬의 곱셈 원리를 알면 쉽게 풀리는 문제였다.
*/


#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    // 각 행렬의 길이 저장
    const int r1 = arr1.size();
    const int c1 = arr1[0].size();
    const int c2 = arr2[0].size();

    // arr1 각 행마다 순회
    for (int i = 0; i < r1; ++i) {
        vector<int> temp;
        // arr2 각 열마다 순회
        for (int j = 0; j < c2; ++j) {
            int total = 0;
            // arr1은 열을, arr2는 행을 바꿔가며 연산
            for (int k = 0; k < c1; ++k) {
                total += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(total);
        }
        answer.push_back(temp);
    }

    return answer;
}