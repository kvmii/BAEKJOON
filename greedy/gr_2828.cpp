#include <iostream>
#include <cmath>

using namespace std;

int n, m, j;
int arr[20];
int num = 0;
int result = 0;

int main() {
	cin >> n >> m;
	// ���� ���ذ� ������� ����
	// �ٱ����� ũ�Ⱑ m�� ���� �߿�
	cin >> j;

	for (int i = 0; i < j; i++) {
		cin >> arr[i];
	}

	num = 1;
	// �ٱ����� ���� ������ �ٱ����� ��ġ��� ����
	for (int i = 0; i < j; i++) {
		if (arr[i] > num) {
			// �����ʿ� �ִ� ��� m - 1��ŭ �� ���� �ȴ�
			int a = abs(arr[i] - num) - (m - 1);
			if (a >= 0) {
				// �̵��� ���
				result += a;
				num = arr[i] - m + 1;
			}
		}
		else {
			// ���ʿ� �ִ� ���� �׳� ���̸�ŭ �����̸� �ȴ�
			result += abs(arr[i] - num);
			num = arr[i];
		}
	}

	cout << result << endl;
}