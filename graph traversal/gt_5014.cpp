#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

int visited[1000001];
int bfs(int x, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x, cnt });
	visited[x] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == G) {
			// ã������ Ƚ�� ��ȯ
			return b;
			break;
		}

		int up = a + U;
		int down = a - D;
		if (visited[up] != 1 && up <= F) {
			q.push({ up, b + 1 });
			// �ö� �� push
			visited[up] = 1;
		}
		if (visited[down] != 1 && down > 0) {
			q.push({ down, b + 1 });
			// ������ �� push
			visited[down] = 1;
		}
	}

	// �� ã���� -1 ��ȯ
	return -1;
}

int main() {
	cin >> F >> S >> G >> U >> D;

	if (S == G) {
		// ������ 0 ��ȯ
		cout << 0;
		return 0;
	}

	int result = bfs(S, 0);

	if (result == -1) cout << "use the stairs" << endl;
	else cout << result << endl;
}