#include <iostream>
#include <string.h>

using namespace std;

int n, m;
long arr[1000001];
long dp[1000001];

int main() {
	cin >> n;
	while (n--) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}

		int max_price = arr[m - 1];
		for (int j = m - 1; j >= 0; j--) {
			// �ں��� Ȯ��
			// ��Ѱ� ������ ������ �ȱ�
			if (max_price > arr[j]) {
				dp[j] = max_price;
				// �ڿ� �ִ� ���� ��Ѱ�
			}
			else {
				dp[j] = arr[j];
				max_price = dp[j];
			}
		}

		long score = 0;
		for (int k = 0; k < m; k++) {
			if (dp[k] > arr[k]) {
				// ��Ѱ� - ���� ��
				score += dp[k] - arr[k];
			}
		}

		cout << score << endl;
	}

}