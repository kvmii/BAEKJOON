#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[10];
int result = 0;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int i = n - 1;
	// ���������� ����

	while (k != 0) {
		if (k / coin[i] > 0) {
			// ������ ���ٸ�
			int num = k / coin[i];
			// ���� ����
			result = result + num;
			k = k - num * coin[i];
			i--;
		}
		else i--;
	}

	cout << result;
}