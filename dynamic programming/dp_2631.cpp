#include <iostream>

using namespace std;

int n;
int arr[200];
int dp[200];
int num = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				// �����ϴ� ���� ���ϱ�
				num = max(num, dp[i]);
			}
		}
	}

	cout << n - num << endl;
	// ��ü �� - �����ϴ� ����
}