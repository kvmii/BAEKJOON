#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
int n;
int sum = 1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (sum < arr[i]) {
			break;
		}
		// ���� k�� ���� ������ �� ������ L�� k���� �۴ٸ� k+1 ~ k + L���� ��� ���� ����
		// �׷��� L�� ũ�ٸ� k+1�� �������� ���Ѵ�
		sum += arr[i];
	}

	cout << sum;
}