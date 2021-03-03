#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> vec[50];
int root[50];
// �ڽ��� ����
int visited[50];
// �湮 ����
int parent[50];
// �θ� ���
int n, k;

int bfs(int x) {
	// bfs Ȱ��
	// ��������� ���� ã��
	if (root[x] == 0) return 1;
	visited[x] = 1;
	int score = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cnt = q.front();
		q.pop();
		if (root[cnt] == 0) score++;
		// �ڽ��� ������
		for (int i = 0; i < vec[cnt].size(); i++) {
			if (visited[vec[cnt][i]] != 1) {
				visited[vec[cnt][i]] = 1;
				q.push(vec[cnt][i]);
			}
		}
	}

	return score;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) continue; 
		vec[a].push_back(i);
		root[a]++;
		parent[i] = a;
	}

	cin >> k;

	int result = 0;

	root[parent[k]]--;
	// �������� ����� �θ��� �ڽ� ��--
	// �̰� 0�� �Ǹ� ������尡 �߰� �ȴ�

	for (int i = 0; i < n; i++) {
		if (root[i] == 0) result++;
	}

	cout << result - bfs(k);
	// �������� ����� ������� ���� ����
}