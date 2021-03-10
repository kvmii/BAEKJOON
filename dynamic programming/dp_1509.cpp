#include <iostream>
#include <string>

using namespace std;
string str;
int dp[2501];
int arr[2501][2501];

int main() {
	cin >> str;
	str.insert(0, " ");
	for (int i = 1; i <= str.size(); i++) {
		arr[i][i] = 1;
		// �ڱ� �ڽ��� �Ӹ����
	}
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i + 1]) {
			arr[i][i + 1] = 1;
			// ������ �Ӹ����
		}
	}
	for (int i = 2; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			if (str[j] == str[i + j] && arr[j + 1][i + j - 1] == 1) {
				arr[j][j + i] = 1;
				// 3������ �� �հ� �� �ڰ� ���� �߰� ���ڰ� �Ӹ�����̸� �Ӹ����
			}
		}
	}

	for (int i = 1; i < str.size(); i++)
	{
		dp[i] = 987654321;
		for (int j = 1; j <= i; j++) {
			if (arr[j][i] == 1) {
				// �Ӹ������ ��
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	cout << dp[str.size() - 1];
}