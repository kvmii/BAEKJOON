#include <iostream>
#define MAX 1000000009

using namespace std;

int T, n;
long long dp[100001][3];
// �� ���� ���� ������ �Ǹ� �ȵǹǷ� ���ڸ� ���� ���� ���
// 0 - 1�� ����, 1 - 2�� ����, 2- 3���� ����

int main() {
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MAX;
		// 1�� ���� ��� 2�� 3���� ������ i -1 ���ٰ� +1
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MAX;
		dp[i][2] = (dp[i - 3][1] + dp[i - 3][0]) % MAX;
	}

	cin >> T;
	while (T--) {
		cin >> n;
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MAX << endl;
	}
}