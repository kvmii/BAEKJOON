#include <iostream>

using namespace std;
int arr[1001];
int dp[1001][3][31];
// �� / ��� ����/ �̵� Ƚ��
int t, w;

int main() {
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}

	if (arr[1] == 1) {
		dp[1][1][0] = 1;
	}
	if( arr[1] == 2) dp[1][2][1] = 1;

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			if(j > 0) {
				if (arr[i] == 1) {
					// 1������ ��������
					dp[i][1][j] = max(dp[i - 1][2][j - 1], dp[i - 1][1][j]) + 1;
					// (2������ �����̰ų� 1������ �״��) + 1
					dp[i][2][j] = max(dp[i - 1][2][j], dp[i - 1][1][j - 1]);
				}

				if (arr[i] == 2) {
					// 2������ ��������
					dp[i][2][j] = max(dp[i - 1][1][j - 1], dp[i - 1][2][j]) + 1;
					// (1������ �����̰ų� 2������ �״��) + 1
					dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][2][j - 1]);
				}
			}

			else {
				if (arr[i] == 1) {
					dp[i][1][j] = dp[i - 1][1][j] + 1;
					dp[i][2][j] = dp[i - 1][2][j];
				}
				if (arr[i] == 2) {
					dp[i][2][j] = dp[i - 1][2][j] + 1;
					dp[i][1][j] = dp[i - 1][1][j];
				}
			}
		}
	}

	int result = 0;

	for (int i = 0; i <= w; i++) {
		// w������ �̵��� ���߿� ���� ���� �޾Ƹ��� ��
		result = max(result, max(dp[t][1][i], dp[t][2][i]));
	}

	cout << result;
} 