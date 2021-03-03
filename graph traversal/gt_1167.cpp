#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int visited[100001];
vector<pair<int, int>> vec[100001];
int n;
int result = 0;
int com;

// 1967�� ������ ����. �Ȱ��� Ǯ���ٰ� �ð��ʰ��� �߻�
// Ʈ���� ������ ���� �� �ϳ��� ���̸� �� ���ؼ� ���� ����� ã�� ���� ��ȿ�����̾���
// �ƹ������� �����ؼ� ���� �� ���� ���� �� �� ������ ���� �� �������� ���� = Ʈ���� �����̶�� ���� ã�� �ذ�

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < vec[a].size(); i++) {
			// a �� ����� ���ҵ�
			int cnt = vec[a][i].first;
			if (visited[cnt] != 1) {
				visited[cnt] = 1;
				// ���� �����ֱ�
				q.push({ cnt, vec[a][i].second + b });
			}
		}

		if (result < b) {
			result = b;
			com = a;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		while(1){
			cin >> b;
			if (b == -1) break;
			cin >> c;
		vec[a].push_back({ b,c });
		// a �� ����� b �� ���� c
		}
	}

	bfs(1);
	// 1���� ���� �� �� ã��
	int num = com;
	// ���� ��ǥ
	memset(visited, 0, sizeof(visited));
	result = 0;

	bfs(num);
	// �� ������ ���� ���ϱ�

	cout << result;
}