#include <iostream>
#include <queue>
#include <string.h>


int n, m;
int arr[300][300];
bool visited[300][300];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
using namespace std;


void bfs(int x, int y){
	// bfs ���
	// ������ �̾����ִ��� Ȯ��
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;

			if (arr[dx][dy] != 0 && visited[dx][dy] == false) {
				visited[dx][dy] = true;
				q.push({ dx,dy });
			}
		}
	}
}

void down(int x, int y) {
	// �Ѵܰ辿 ���ߴ� �Լ�
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;

		if (arr[dx][dy] == 0 && visited[dx][dy] == false) {
			// �̰� ������ 1�� ����
			// ������� ������ ��� ���� �����Ѱ� 0�� �Ǿ��� �� ���� ���� �ϳ� �� ���ҵȴ�
			// �׷��� ���ǿ� �湮���� �ʾҴٸ��� �߰�
			arr[x][y]--;
		}
		if (arr[x][y] < 0)
			arr[x][y] = 0;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int year = 0;

	while (1) {
		memset(visited, false, sizeof(visited));
		bool zero = true;
		int score = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					zero = false;
					// ���� 0�� ���
				}
			}
		}

		if (zero == true) {
			// ���� 0�̸� �� ����� �и� X
			cout << 0;
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false && arr[i][j] != 0) {
					bfs(i, j);
					score++;
				}
			}
		}

		memset(visited, false, sizeof(visited));

		if (score >= 2) {
			// ������ �� ��� �̻��̸�
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					down(i, j);
					// ����
				}
			}
		}
		year++;
		// 1�� ��
	}

	cout << year;
	return 0;
}