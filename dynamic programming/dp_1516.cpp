#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> vec[501];
int dp[500];
int arr[500];
int num[500];
// ���� �ǹ��� ����
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int dx = q.front();
		q.pop();

		for (int i = 0; i < vec[dx].size(); i++) {
			int a = vec[dx][i];
			// dx�� �������� �ϴ� �ǹ���
			num[a]--;
			dp[a] = max(dp[a], dp[dx] + arr[dx]);
			// ���� �ǹ� + ���� �ǹ��� ���
			if (num[a] == 0) {
				q.push(a);
				// ���� �ǹ��� ��������
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;

			vec[a].push_back(i);
			// a�� ����Ǵ� �ǹ�: i
			num[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (num[i] == 0) {
			// ���� �ǹ��� ������
			q.push(i);
		}
	}

	bfs();

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] + arr[i] << endl;
	}
}