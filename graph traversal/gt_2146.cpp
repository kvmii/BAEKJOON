#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
int arr[100][100];
int visited[100][100];
int map[100][100];
int X[] = { 1, -1, 0 ,0 };
int Y[] = { 0, 0, 1, -1 };
int n;
int result = 10000;

void bfs(int x, int y, int cnt) {
	// bfs Ȱ��
	// �پ��ִ� ������ ���� ��ȣ�� �ű�
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	map[x][y] = cnt;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];

			if (dx < 0 || dx >= n || dy < 0 || dy >= n)
				continue;

			if (arr[dx][dy] == 1 && visited[dx][dy] != 1) {
				q.push({ dx, dy });
				visited[dx][dy] = 1;
				map[dx][dy] = cnt;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			cin >> arr[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 1 && arr[i][j] == 1) {
				bfs(i, j, cnt);
				cnt++;
				// �� ��ȣ �ű��
				// ��ȣ ����
			}
		}
	}

	for (int k = 1; k < cnt; k++) {
		// ���� ����
		vector<pair<int, int>> vec;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == k) {
					// k�� ���̸� ��ǥ ����
					vec.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < vec.size(); l++) {
					// ������ ��ǥ�� ������ ������ �Ÿ� ����
					if (map[i][j] != k && arr[i][j] == 1) {
						result = min(result, abs(i - vec[l].first) + abs(j - vec[l].second) - 1);
						// ���� ª�� �Ÿ� ����
						// x�� �� + y�� �� - 1 = �Ÿ�
					}
				}
			}
		}
	}

	cout << result;
}