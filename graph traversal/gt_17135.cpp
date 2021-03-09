#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;
int n, m, d;
int arr[15][15];
int map[15][15];
int result = 0;
int bow[15];
int visited[15];
int visit[15][15];
int score;

void kill() {
	// ���̱�
	for (int k = 0; k < m; k++) {
		for (int l = 1; l <= d; l++) {
			for (int j = 0; j < m; j++) {
				// ���ʺ���
				for (int i = n - 1; i >= 0; i--) {
					// �Ʒ�����(����� ��)
					if (bow[k] == 1 && visited[k] != 1) {
						// �ü��� �ִ� �ڸ��� ���� �ʾҴٸ�
						int distance = abs(i - n) + abs(k - j);
						if (distance == l && map[i][j] == 1) {
							// ���� �ִٸ�
							map[i][j] = 0;
							visit[i][j] = 1;
							// �湮 ǥ��
							result++;
							visited[k] = 1;
							break;
						}
						if (distance == l && map[i][j] == 0) {
							// ���� ������ �湮�� �ߴٸ�
							if (visit[i][j] == 1) {
								// �Ȱ��� ���� ��� �Ѿ
								visited[k] = 1;
								break;
							}
						}
					}
					if (visited[k] == 1) break;
				}
				if (visited[k] == 1) break;
			}
			if (visited[k] == 1) break;
		}
	}
}

void move() {
	// ��ĭ�� �Ʒ��� �����̱�
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			map[i][j] = map[i - 1][j];
		}
		map[0][j] = 0;
	}
}

void copy() {
	// ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

bool check() {
	// ������ �������� Ȯ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}

void start(int cnt) {
	if (cnt == 3) {
		// 3���� ��ġ�ߴٸ�
		result = 0;
		copy();
		while (1) {
			memset(visited, 0, sizeof(visited));
			memset(visit, 0, sizeof(visit));
			kill();
			// ���̰�
			move();
			// �����̱�
			if (check() == true) break;
			// ���� ������ ����
		}
		score = max(score, result);
		// �ְ�����
		return;
	}
	for (int i = 0; i < m; i++) {
		if (bow[i] == 0) {
			bow[i] = 1;
			start(cnt + 1);
			bow[i] = 0;
		}
	}
}

int main() { 
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	start(0);
	cout << score;
}