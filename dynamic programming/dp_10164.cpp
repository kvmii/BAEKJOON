#include <iostream>

using namespace std;

long long int arr[16][16];
long long int dp[16][16];

int main() {
	int n, m, t;
	cin >> n >> m >> t;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (t == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) dp[i][j] = 1;

				else if (i == 0) dp[i][j] += dp[i][j - 1];

				else if (j == 0) dp[i][j] += dp[i - 1][j];

				else {
					dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
				}
			}
		}

		cout << dp[n - 1][m - 1] << endl;
		return 0;
	}

	else {
		int b = t % m - 1;
		int a = t / m;
		if (t % m == 0) {
			b = m - 1;
			a = t / m - 1;
		}
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				if (i == 0 && j == 0) dp[i][j] = 1;

				else if (i == 0) dp[i][j] += dp[i][j - 1];

				else if (j == 0) dp[i][j] += dp[i - 1][j];

				else {
					dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
				}
			}
		}

		int cnt = dp[a][b];

		for (int i = a; i < n; i++) {
			for (int j = b; j < m; j++) {
				if (i == a && j == b)
					dp[i][j] = 1;
				else if (i == a) dp[i][j] += dp[i][j - 1];

				else if (j == b) dp[i][j] += dp[i - 1][j];
				else
					dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]);
			}
		}

		cout << dp[n - 1][m - 1] * cnt << endl;
		return 0;
	}

	// 1���õ� ���� - t % m�� 0�� ���� ������ �ʾҴ�
	// 2���õ� ���� - ó������ dp[a][b]�� �״�� �ΰ� �ٽ� ����ߴµ� ���� �ʾҴ�
	// �׷��� dp[a][b]�� �����صΰ� ���ϴϱ� �ȴ�. ���� ���̰� �ִ��� �𸣰ڴ�
}