#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;
int n, m, T;
int dp[101];
int num = 1;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		arr.push_back({ n, m });
	}

	sort(arr.begin(), arr.end());
	// ������������ �����ϱ�

	for (int i = 0; i < T; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j].second < arr[i].second && dp[i] < dp[j] + 1) {
				// �����ϴ� ���� �� ���� ���ϱ�
				dp[i] = dp[j] + 1;
			}
		}
		num = max(num, dp[i]);
	}

	cout << T - num << endl;
	//��ü - ���� �� ���� = ������ ����
	system("PAUSE");
}