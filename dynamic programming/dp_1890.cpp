#include <iostream>

using namespace std;

long long dp[100][100];
long long result[100][100];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dp[i][j];
		}
	}

	result[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = dp[i][j];
			if (num != 0) {
				if (i + num < N) {
					result[i + num][j] += result[i][j];
					//num �Ÿ��� ������ �� ���
				}
				if (j + num < N) {
					result[i][j + num] += result[i][j];
					//num �Ÿ��� ���ʿ��� �� ���
				}
			}
		}
	}

	cout << result[N - 1][N - 1];
	system("PAUSE");
}