#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
char arr[50][50];
int visited[50][50];
int n, m;
int X[] = { 1, -1, 0 ,0 };
int Y[] = { 0, 0, 1, -1 };
int result = 0;
vector < pair <int, int> > vec;

int bfs(int x, int y, int z) {
	//bfs Ȱ��
	int sum = 0;
	queue<tuple<int, int, int>> q;
	q.push({ x, y, z });
	visited[x][y] = 1;
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];

			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;

			if (arr[dx][dy] == 'L' && visited[dx][dy] != 1) {
				q.push({ dx, dy, cnt + 1 });
				visited[dx][dy] = 1;
			}
		}
		if (sum < cnt) {
			sum = cnt;
		}
	}
	return sum;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L' && visited[i][j] != 1) {
				vec.push_back({ i, j });
				// L�� ��� ��ǥ ����
			}
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		result = max(result, bfs(vec[i].first, vec[i].second, 0));
		// �ϳ��� bfs�����鼭 ���� ū �� ã��
		memset(visited, 0, sizeof(visited));
		// �湮 �ʱ�ȭ
	}

	cout << result;
	// �׳� bfs�� Ȱ���ߴ��� �������� ������ �Ǿ���
	// �׷��� �� bfs������ ���� ū ���� ã�Ҵ��� ����
}