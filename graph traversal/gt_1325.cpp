#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int n, m;
vector<int> vec[10001];
int arr[10001];
int result = 0;
int visited[10001];

void bfs(int x) {
	// bfs
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 0; i < vec[dx].size(); i++) {
			int dy = vec[dx][i];
			if (visited[dy] != 1) {
				q.push(dy);
				visited[dy] = 1;
			}
		}
		arr[x]++;
		// ��ŷ�� �� �ִ� ����
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[b].push_back(a);
		// �ŷ��ϴ� ���
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(visited, 0, sizeof(visited));
		if (arr[i] > result)
			result = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == result) {
			// ������ �� ������
			cout << i << " ";
		}
	}
	return 0;
}