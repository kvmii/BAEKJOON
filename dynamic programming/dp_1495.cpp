#include <iostream>

using namespace std;

int N, S, M;
int arr[101];
int dp[1001][101];
int result = -1;

int main() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[S][0] = 1;
	for (int j = 0; j < N; j++)
	{
		 for (int i = M; i >= 0; i--){
			 // i = 0���� �߾����� ��� 0�� ���Դ�
			 // i = M���� �ϰ� �Ųٷ� ���� ������ ����
			 // 0���� �ϸ� �̹� ������ dp�� �ٽ� �湮�� ���� ����
			if (dp[i][j] == 1 && i + arr[j + 1] <= M) {
				dp[i + arr[j + 1]][j + 1] = 1;
			}
			if (dp[i][j] == 1 && i - arr[j + 1] >= 0) {
				dp[i - arr[j + 1]][j + 1] = 1;
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[i][N] == 1) {
			result = i;
			break;
		}
	}

	cout << result;
}