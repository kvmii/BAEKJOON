#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int dp[1001];
int maximum = 1;
vector<int> vec;

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
				maximum = max(dp[i], maximum);
				// �ִ� ����
			}
		}
	} 


	int num = 987654321;

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == maximum && arr[i] < num) {
			num = arr[i];
			vec.push_back(arr[i]);
			maximum--;
		}
	}
	cout << vec.size() << endl;

	reverse(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	// �����ϴ� ������ ���� ���� �������� �� ������ ���ϴ� ���� ��������
	// ó������ 1,2,3... ������ �ؼ� dp�� ������ vec�� push_back�Ͽ�����
	// 1 5 6 2 3�� ���� �ݷʰ� ���Դ�
	// �׷��� �ִ��� ������ �� �Ųٷ� ������ �� reverse�� ���־���
}