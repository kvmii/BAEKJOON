#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> vec[101];
int visited[101][101];
int result[101];
int n, m;
int minm = 98765;

void bfs(int x) {
	// bfsȰ��
	queue<pair<int, int>> q;
	q.push({x, 1});
	while (!q.empty()) {
		int cnt = q.front().first;
		int num = q.front().second;
		// �̵� ��
		q.pop();
		for (int i = 0; i < vec[cnt].size(); i++) {
			int nxt = vec[cnt][i];
			if (visited[x][nxt] != 1 && x != nxt) {
				// ������ �Ǿ����� ������
				visited[x][nxt] = 1;
				// x�� nxt�� ���� �Ǿ���
				result[x] += num;
				q.push({nxt, num + 1});
				// �Ÿ� ����
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (minm > result[i]) minm = result[i];
		// ���� ���� �� ����
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == minm) {
			// ���� ���� ���� ���ٸ�
			cout << i;
			return 0;
		}
	}
}