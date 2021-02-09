#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[1000][1000];
int dp[1000][1000];
int n, m, num = 0;
string str;

int square(int x, int y) {
	if (x == 0 || y == 0) {
		dp[x][y] = arr[x][y];
	}
	else if (arr[x][y] == 1) {
		dp[x][y] = min(dp[x][y - 1], min(dp[x - 1][y - 1], dp[x - 1][y])) + 1;
		// 3�� �� �ϳ��� 1�� �ƴϸ� ��������� �ʴ´�
		// ��, 3�� �� �ּڰ� + 1�� ���̴�
	}
	return dp[x][y];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
			// string���� �ް� �ϳ��� ó��
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			num = max(num, square(i, j));
		}
	}

	cout << num * num;
	system("PAUSE");
}