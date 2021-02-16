#include <iostream>
#include <queue>
#define MAX 8
using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, -1, 1 };
int map[MAX][MAX];
int cmap[MAX][MAX];
int n, m;
int result = 0;
queue<pair<int, int>> q;

int count(){
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cmap[i][j] == 0)
				num++;
		}
	}
	return num;
}

void virus() {
	queue<pair<int, int>> Q = q;
	// �̰� ������ ��� ����
	// ���縦 �صξ�� ���� ���ﶧ���� ���� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cmap[i][j] = map[i][j];
			// ����
		}
	}

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx >= 0 && dx < n && dy >= 0 && dy < m) {

				if (cmap[dx][dy] == 0) {
					cmap[dx][dy] = 2;
					Q.push({ dx, dy });
				}
			}
		}
	}

	result = max(count(), result);
}

void wall(int wcnt) {
	if (wcnt == 3) {
		virus();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;	//�� ����
				wall(wcnt + 1);
				map[i][j] = 0;	//�� �㹰�� ���󺹱�
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				q.push({i, j});
		}
	}

	wall(0);

	cout << result << endl;
	return 0;
}