#include <iostream>

using namespace std;
int T, n, m, sum;
int arr[10001];
int dp[10001];
int num[10001];
int result = 0;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		cin >> m;
		sum = 0;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			// ���� �۾� �� ���� �� �ð��� ����
			sum = max(sum, arr[a]);
		}
		arr[i] += sum;
		// ���� �۾� + �۾��� �ɸ��� �ð�
		result = max(result, arr[i]);
	}


	// k�� �����۾��� 1 ~ k - 1�����ۿ� �����Ƿ� ���������� ������� �ʾƵ� �ȴ�
	cout << result;
}