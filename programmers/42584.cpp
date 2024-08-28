// 42584번, 주식 가격
// 자료구조, 스택

/*
스택의 개념에 대해 한층 더 깊이 이해할 수 있었던 문제였다.
인덱스와 값을 같이 스택에 저장하고 싶을 때는 인덱스를 스택에 넣자.
또한, 스택이 비어있는지 아닌지를 꼭꼭 판단하자.
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    // 주식 가격의 길이
    const int N = prices.size();

    vector<int> answer(N);
    stack<int> my_stack;

    for (int i = 0; i < N; ++i) {
        // 스택이 비어있는 경우 push
        if (my_stack.empty()) {
            my_stack.push(i);
            continue;
        }
        // 현재 가격이 스택의 맨 윗 가격보다 크거나 같은 경우 push
        if (prices[my_stack.top()] <= prices[i]) {
            my_stack.push(i);
            continue;
        }
        // 현재 가격이 스택의 맨 윗 가격보다 작은 경우 pop 하며 기간 결정하기
        while (!my_stack.empty() && prices[my_stack.top()] > prices[i]) {
            answer[my_stack.top()] = i - my_stack.top();
            my_stack.pop();
        }
        my_stack.push(i);
    }
    // 마지막 스택에 남은 주식 가격의 기간 결정하기
    while (!my_stack.empty()) {
        answer[my_stack.top()] = N - 1 - my_stack.top();
        my_stack.pop();
    }
    
    return answer;
}