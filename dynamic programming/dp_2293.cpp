#include <iostream>

using namespace std;

int n, k;
int  dp[101];
int result[10001];

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	result[0] = 1;

	for (int i = 0; i < n; i++) {
		int T = dp[i];
		for (int j = T; j <= k; j++) {
			result[j] += result[j - T];
			// ex 10���� ����� = 5���� ����� 5��¥�� ������ ����
		}
	}
	cout << result[k] << endl;

	system("PAUSE");
	return 0;
}