#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T, n, m, k;
int arr[1001];
int dp[1001];
int num[1001];
vector<int> vec[1001];
queue<int> q;

void bfs() {
	// dp_1516�� ������ ����
	while (!q.empty()) {
		int dx = q.front();
		q.pop();
		for (int i = 0; i < vec[dx].size(); i++) {
			num[vec[dx][i]]--;
			dp[vec[dx][i]] = max(dp[vec[dx][i]], dp[dx] + arr[dx]);
			if (num[vec[dx][i]] == 0) {
				q.push(vec[dx][i]);
			}
		}
	}
}

void clear() {
	// �ʱ�ȭ
	for (int i = 1; i < 1001; i++) {
		dp[i] = 0;
		vec[i].clear();
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			// a = ����ǹ�
			num[b]++;
			// b�� ���� ���� ����ǹ��� ����
		}
		cin >> k;

		for (int i = 1; i <= n; i++) {
			if (num[i] == 0) {
				q.push(i);
			}
		}

		bfs();
		cout << dp[k] + arr[k] << endl;
		// ����ǹ����� �������� �ð� + k�� �������� �ð�
		clear();
	}
}