#include <iostream>

using namespace std;
int n, m;
int arr[31];

int main() {
	cin >> n >> m;
	arr[n] = m;
	for (int i = m / 2; i <= m; i++) {
		// �ϳ��� ã��
		arr[n - 1] = i;
		// �ٷ� �� ���� �ϳ��� ����
		for (int j = n - 2; j >= 1; j--) {
			arr[j] = arr[j + 2] - arr[j + 1];
			// ���� ���ϱ�
		}
		bool check = false;
		for (int k = 1; k <= n; k++) {
			if (arr[k] < 0) {
				// ������ �ִٸ�
				check = true;
			}
			if (k != n && arr[k] > arr[k + 1]) {
				// A > B�� ���
				check = true;
			}
		}
		if (check == false) break;
	}

	cout << arr[1] << endl;
	cout << arr[2];
}