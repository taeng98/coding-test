// 1231번, [S/W 문제해결 기본] 9일차 - 중위순회
// 트리

/*
기억할 것: 구조체 사용법, cin.get() 이해
알고리즘 구현 자체는 쉬웠지만,
입력을 적절하게 받는 법, 트리를 담을 적절한 자료구조를 선택하는 법이 쉽지 않았다.
다른 사람의 풀이를 찾아보면서 가장 효율적으로 입력 받는 법을 찾아보았는데
이렇게 다른 사람의 풀이를 찾아보는 것도 매우 도움이 되는 것 같다.
*/

#include <iostream>

using namespace std;

struct Tree {
	char alpha;
	int children[2];
} tree[101];

void Inorder(const int node) {
	if (node == 0) {
		return;
	}
	Inorder(tree[node].children[0]);
	cout << tree[node].alpha;
	Inorder(tree[node].children[1]);
}

int main() {
	for (int tc = 1; tc <= 10; ++tc) {
		int N;
		cin >> N;

		// 그래프 정보 입력
		for (int i = 0; i < N; ++i) {
			int parent;
			char alpha;

			cin >> parent >> alpha;
			
			// 알파벳 다음 입력 받기
			// cin.get() 은 공백, 개행을 입력받음
			int children[2] = { 0, };
			if (cin.get() != '\n') {
				cin >> children[0];
				if (cin.get() != '\n') {
					cin >> children[1];
				}
			}

			tree[parent].alpha = alpha;
			tree[parent].children[0] = children[0];
			tree[parent].children[1] = children[1];
		}

		cout << '#' << tc << " ";
		const int root = 1;
		Inorder(root);
		cout << endl;
	}
	
	return 0;
}